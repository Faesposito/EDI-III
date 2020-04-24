/*********************************SUBJECT ABSTRACT CLASS**********************************/
/**Similarly, an abstract class defines the Subject interface:**/

#ifndef SUBJECT_H
#define SUBJECT_H

#define TO_STRING(x) dynamic_cast<std::ostringstream &>((std::ostringstream() << std::dec << x)).str()

#include "D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\ISubject.h"
#include <list>

using namespace std;

class Subject : public ISubject
{
public:
    Subject(){};
    virtual ~Subject(){};

    void Attach(IObserver *o)
    {
        m_observers.push_front(o);
    }
    void Detach(IObserver *o)
    {
        m_observers.remove(o);
    }
    void Notify()
    {
        list<IObserver *>::iterator it;
        for (it = m_observers.begin(); it != m_observers.end(); ++it)
        {
            (*it)->Update();
        }
    }

private:
    list<IObserver *> m_observers;
};

#endif // SUBJECT_H
