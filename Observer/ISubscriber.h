/********************************* Subscriber Interface **********************************/

#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H

#include "IObserver.h"

class ISubscriber
{
public:
    virtual ~ISubscriber() {}
    virtual void attach(IObserver *observer) = 0;
    virtual void detach(IObserver *observer) = 0;
};

#endif // ISUBSCRIBER_H
