#include <iostream>
#include "include/ZombieMonster.hh"

int main()
{
    std::cout << "hello" << std::endl;

    Character *z = new ZombieMonster();

    std::cout << z->GetClassName() << std::endl;
    return 0;
}