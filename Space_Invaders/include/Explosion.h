#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "SpaceElement.h"


class Explosion : public SpaceElement
{
    public:
        Explosion();

        void start(Coordinate const& p_position);
        virtual void crashReaction() override;

    protected:
        virtual void update(float time) override;

    private:
        bool starting{false};
        float age{};
        static constexpr float LIFETIME{0.5f};
};

#endif // EXPLOSION_H
