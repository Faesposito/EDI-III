/*********************************SUBJECT interface**********************************/
/**Similarly, an abstract class defines the Subject interface:**/

#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\IObserver.h"

class ISubject
{
public:
    virtual ~ISubject() {}
    virtual void Attach(IObserver *o) = 0;
    virtual void Detach(IObserver *o) = 0;
    virtual void Notify() = 0;
};

#endif // ISUBJECT_H
