#include "Ennemy.h"
#include "Bonus.h"
#include "BonusFactory.h"

Ennemy::Ennemy(Game &p_game, Space& p_space, float x, float y, std::string_view path):
Ship(p_space, p_game, path)
{
    position = Coordinate{x, y};
    type = ElementType::ENNEMY;
}

Ennemy::~Ennemy() {}

void Ennemy::crashReaction(SpaceElement& other) {
    if (other.type == ElementType::BULLET || other.type == ElementType::PLAYER) {
        game.addPoints(sprite.getScale().x * 100);
        destruct = true;
        space.add(std::make_unique<Explosion>(position));
        AskForBonus();
    }
}

void Ennemy::AskForBonus()
{
    int random = rand() % 70;
    int bonus = 0;

    switch (random) {
        case 1:
            bonus = 1;
            break;
        case 2:
            bonus = 2;
            break;
        case 3:
            bonus = 3;
            break;
    }

    if (bonus != 0) 
        space.add(BonusFactory::GetInstance().Create(position.x, position.y, bonus));
}