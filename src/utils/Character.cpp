#include "include/Character.hh"

Character::Character() {}

Character::~Character() {}

double Character::GetX(void) const
{
    return this->_x;
}

void Character::SetX(double x)
{
    this->_x = x;
    for(IObserver *observer : this->_observers)
        observer->Notify(this);
}

double Character::GetY(void) const
{
    return this->_y;
}

void Character::SetY(double y)
{
    this->_y = y;
    for(IObserver *observer : this->_observers)
        observer->Notify(this);
}

int Character::GetLife(void) const
{
    return this->_life;
}

void Character::SetLife(int life)
{
    this->_life = life;
    for(IObserver *observer : this->_observers)
        observer->Notify(this);
}

std::string Character::GetClassName() const
{
    return this->_className;
}

void Character::SetClassName(const std::string className)
{
    this->_className = className;
}

void Character::AddObserver(IObserver *observer)
{
    this->_observers.push_back(observer);
}

void Character::RemoveObserver(IObserver *observer)
{
    this->_observers.remove(observer);
}

void Character::ToString()
{
    std::cout << this->GetClassName() << " avec " << this->GetLife() << " HP." << std::endl;
    std::cout << "En position " << this->GetX() << " / " << this->GetY() << std::endl;
}