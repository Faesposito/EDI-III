/********************************* Change Manager **********************************/

#include <iostream>
#include "include/ChangeManager.h"

ChangeManager *ChangeManager::m_instance = 0;

ChangeManager::ChangeManager()
{
    //ctor
}

ChangeManager::~ChangeManager()
{
    //dtor
}

ChangeManager *ChangeManager::createChangeManager()
{
    if (m_instance == 0)
    {
        m_instance = new ChangeManager();
    }
    return m_instance;
}

void ChangeManager::attach(IObserver *observer)
{
    std::cout << "Attached to Change Manager" << std::endl;
    m_observersList.push_front(observer);
}

void ChangeManager::detach(IObserver *observer)
{
    std::cout << "Detached of Change Manager" << std::endl;
    m_observersList.remove(observer);
}

void ChangeManager::notify(void)
{
    std::cout << "Notifying" << std::endl;
    std::list<IObserver *>::iterator it;

    for (it = m_observersList.begin(); it != m_observersList.end(); ++it)
    {
        (*it)->Update();
    }
}
