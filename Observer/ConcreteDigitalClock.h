/****************************************CONCRETE DIGITAL CLOCK********************************/
/**Now we can define a class DigitalClock that displays the time. It inherits its graphical functionality from 
 * a Widget class provided by a user interface toolkit. The Observer interface is mixed into the DigitalClock
interface by inheriting from Observer.**/

#ifndef CONCRETEDIGITALCLOCK_H
#define CONCRETEDIGITALCLOCK_H

#define TO_STRING(x) dynamic_cast<std::ostringstream &>((std::ostringstream() << std::dec << x)).str()

#include <string>

#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\IWidget.h>
#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\IObserver.h>
#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\ClockTimer.h>

class DigitalClock : public IWidget, public IObserver
{
public:
    DigitalClock(ClockTimer *s)
    {
        m_timer = s;
        m_timer->getSubject()->Attach(this);
    }

    ~DigitalClock()
    {
        m_timer->getSubject()->Detach(this);
    }

    void Update()
    {
        Draw();
    }

    void Draw()
    {
        // get the new values from the subject
        std::string hours = TO_STRING(m_timer->GetHour());
        std::string minutes = TO_STRING(m_timer->GetMinute());
        std::string seconds = TO_STRING(m_timer->GetSecond());
        // draw the digital clock
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
        std::cout << "I am Digital: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }

private:
    ClockTimer *m_timer;
};

#endif // CONCRETEDIGITALCLOCK_H