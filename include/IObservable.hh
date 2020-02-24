#ifndef IOBSERVABLE_HH
#define IOBSERVABLE_HH

class IObservable;

#include <list>
#include "IObserver.hh"

class IObservable
{
    protected:
        std::list<IObserver*> _observers;
    public:
        virtual ~IObservable() {};

        virtual void AddObserver(IObserver*) = 0;
        virtual void RemoveObserver(IObserver*) = 0;
};

#endif