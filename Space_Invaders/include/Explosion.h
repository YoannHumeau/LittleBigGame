#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "SpaceElement.h"


class Explosion : public SpaceElement
{
    public:
        Explosion();

        void start(Coordinate const& p_position);
        virtual void update(float time) override;
        virtual void crashReaction() override;
        virtual void display(sf::RenderWindow& window) const override;

    protected:

    private:
        bool starting{false};
        float age{};
        static constexpr float LIFETIME{0.5f};
};

#endif // EXPLOSION_H
