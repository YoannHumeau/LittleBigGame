#ifndef IOBSERVER_HH
#define IOBSERVER_HH

class IObserver
{
    public:
        virtual ~IObserver() {};
        virtual void Notify(IObservable*) = 0;
};

#endif
