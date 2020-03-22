// #include "Pistol.h"

// std::unique_ptr<Bullet> Pistol::attack(Coordinate position) {
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > 0.2) {
//         // space.add(std::make_unique<Bullet>(position));
//         lastShoot.restart();
//         return std::make_unique<Bullet>(position);
//     }
//     return nullptr;
// }