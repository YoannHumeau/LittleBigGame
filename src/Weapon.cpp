#include "Weapon.h"

// Weapon::Weapon(){}
// Weapon::Weapon(){
//     std::cout << "Test weapon" << std::endl;
// }

Weapon::~Weapon(){}

void Weapon::attack(Space& space, Coordinate position) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > 0.2) {
        std::cout << "Waepon" << std::endl;
        space.add(std::make_unique<Bullet>(position));
        lastShoot.restart();
    }
}