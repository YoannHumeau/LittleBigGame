#ifndef CHARACTER_HH
#define CHARACTER_HH

#include "AbstractEntity.hh"
#include "IObservable.hh"

class Character: public AbstractEntity, public IObservable
{
    private:
        double _x;
        double _y;
        int _life;
        std::string _className;

    public:
        Character();
        virtual ~Character() = 0;

        // Getters & Setters
        double GetX(void) const;
        void SetX(double);
        double GetY(void) const;
        void SetY(double);
        int GetLife(void) const;
        void SetLife(int);
        std::string GetClassName(void) const;
        void SetClassName(const std::string);

        void AddObserver(IObserver*) override;
        void RemoveObserver(IObserver*) override;
        
        virtual void Update(void) override;
        virtual void Draw(void) override;
        
        void ToString(void);
};

#endif