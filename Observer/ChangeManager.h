/**************************************** Change Manager ***********************************/

#ifndef CHANGEMANAGER_H
#define CHANGEMANAGER_H

#include "ISubscriber.h"
#include "INotifier.h"
#include "IObserver.h"
#include <list>

class ChangeManager : public ISubscriber, public INotifier
{

public:
    ChangeManager() {}
    virtual ~ChangeManager() {}

    void attach(IObserver *observer)
    {
        std::cout << "Attached to Change Manager" << std::endl;
        m_observersList.push_front(observer);
    }

    void detach(IObserver *observer)
    {
        std::cout << "Detached of Change Manager" << std::endl;
        m_observersList.remove(observer);
    }

    void notify(void)
    {
        std::cout << "Notifying" << std::endl;
        std::list<IObserver *>::iterator it;

        for (it = m_observersList.begin(); it != m_observersList.end(); ++it)
        {
            (*it)->Update();
        }
    }

private:
    std::list<IObserver *> m_observersList;
};

#endif // CHANGEMANAGER_H
