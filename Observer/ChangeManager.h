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
    static ChangeManager *createChangeManager();
    virtual ~ChangeManager();

    void attach(IObserver *observer);

    void detach(IObserver *observer);

    void notify(void);

protected:
    ChangeManager();

private:
    static ChangeManager *m_instance;
    std::list<IObserver *> m_observersList;
};

#endif // CHANGEMANAGER_H
