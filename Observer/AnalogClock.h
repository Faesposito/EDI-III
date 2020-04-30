/**************************************** Analog Clock ***********************************/

#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <sstream>
#define TO_STRING(x) dynamic_cast<std::ostringstream &>(          \
                         (std::ostringstream() << std::dec << x)) \
                         .str()

#include <iostream>
#include <string>

#include "IWidget.h"
#include "IObserver.h"
#include "ISubscriber.h"
#include "ClockTimer.h"

class AnalogClock : public IWidget, public IObserver
{
public:
    AnalogClock(ClockTimer *clockTimer, ISubscriber *subscriber)
    {
        std::cout << "Creating Analog Clock!" << std::endl;
        m_timer = clockTimer;
        m_subscriber = subscriber;
        m_subscriber->attach(this);
    }

    ~AnalogClock()
    {
        std::cout << "Destroying Analog Clock!" << std::endl;
        m_subscriber->detach(this);
    }

    void Update()
    {
        m_hours = m_timer->getHour();
        m_minutes = m_timer->getMinute();
        m_seconds = m_timer->getSecond();
        draw();
    }

    void draw()
    {

        std::string hours = TO_STRING(m_timer->getHour());
        std::string minutes = TO_STRING(m_timer->getMinute());
        std::string seconds = TO_STRING(m_timer->getSecond());
        if (hours.size() == 1)
        {
            hours = "0" + hours;
        }
        if (minutes.size() == 1)
        {
            minutes = "0" + minutes;
        }
        if (seconds.size() == 1)
        {
            seconds = "0" + seconds;
        }
        std::cout << "I am Analog: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }

private:
    ClockTimer *m_timer;
    ISubscriber *m_subscriber;
    int m_hours;
    int m_minutes;
    int m_seconds;
};

#endif //ANALOGCLOCK_H
