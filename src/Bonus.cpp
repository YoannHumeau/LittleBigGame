#include "Bonus.h"

Bonus::Bonus(float x, float y, std::string_view path):
PhysicalElement(path)
{
    position = Coordinate{x, y};
    type = ElementType::BONUS;
}

Bonus::~Bonus() {}

void Bonus::crashReaction(SpaceElement& other) {
    if (other.type == ElementType::PLAYER) {
        destruct = true;
        Player& p = dynamic_cast<Player&>(other);
        consumeBonus(p);
    }
}