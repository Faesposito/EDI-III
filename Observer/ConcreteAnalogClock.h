/*************************************************************************************************/
/****************************************CONCRETE ANALOG CLOCK***********************************/
/**An AnalogClock class can be defined in the same way.**/

#ifndef CONCRETEANALOGCLOCK_H
#define CONCRETEANALOGCLOCK_H

#define TO_STRING(x) dynamic_cast<std::ostringstream &>((std::ostringstream() << std::dec << x)).str()

#include <string>

#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\IWidget.h>
#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\IObserver.h>
#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\ClockTimer.h>

class AnalogClock : public IWidget, public IObserver
{
public:
    AnalogClock(ClockTimer *s)
    {
        m_timer = s;
        m_timer->getSubject()->Attach(this);
    }

    ~AnalogClock()
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
        // draw the digital clock
        std::cout << "I am Analog: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }

private:
    ClockTimer *m_timer;
};

#endif //CONCRETEANALOGCLOCK_H