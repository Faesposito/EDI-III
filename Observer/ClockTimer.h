/********************************* Clock Timer ************************************/

#ifndef CLOCKTIMER_H
#define CLOCKTIMER_H

#include "ISubscriber.h"
#include "INotifier.h"
#include <iostream>

class ClockTimer
{
public:
    ClockTimer(INotifier *notifier)
    {
        std::cout << "Timer Created!" << std::endl;
        m_notifier = notifier;
    }

    ~ClockTimer()
    {
        std::cout << "Timer Destroyed!" << std::endl;
        delete m_notifier;
    }

    int getHour()
    {
        return m_hours;
    }

    int getMinute()
    {
        return m_minutes;
    }

    int getSecond()
    {
        return m_seconds;
    }

    void Tick()
    {

        m_seconds++;
        if (m_seconds == 60)
        {
            m_seconds = 0;
            m_minutes++;
            if (m_minutes == 60)
            {
                m_seconds = 0;
                m_minutes = 0;
                m_hours++;
                if (m_hours == 24)
                {
                    m_seconds = 0;
                    m_minutes = 0;
                    m_hours = 0;
                }
            }
        }
        m_notifier->notify();
    }

private:
    int m_hours = 0;
    int m_minutes = 0;
    int m_seconds = 0;
    INotifier *m_notifier;
};

#endif // CLOCKTIMER_H
