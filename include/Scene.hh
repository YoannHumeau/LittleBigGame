#ifndef SCENE_HH
#define SCENE_HH

#include "AbstractEntity.hh"
#include <list>

class Scene: public ISerializable
{
    private:
        std::list<AbstractEntity*> _entities;

    public:
        Scene();
        Scene(const std::string&);
        ~Scene();

        std::list<AbstractEntity*> GetEntities(void) const;
        void AddEntity(AbstractEntity*);
        void RemoveEntity(AbstractEntity*);
        void Update(void);

        virtual std::string Serialize(void) override;
};

#endif