///////////////////////////////////////////////////////////////////////
/**
 Project : Observer Example
 Authors : Erich Gamma, Richard Helm, Ralph Johnson and John
Vlissides
 Implementer : Gabriel Nicolás González Ferreira
**/

#include <sstream>
#include <iostream>

#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\Subject.h>
#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\ClockTimer.h>
#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\ConcreteAnalogClock.h>
#include <D:\Programacion\Analisis de Sistemas\EDI\EDI III\Observer\ConcreteDigitalClock.h>

int main()
{
    ISubject *subject = new Subject();
    ClockTimer *timer = new ClockTimer(subject);
    AnalogClock *ac = new AnalogClock(timer);
    DigitalClock *dc = new DigitalClock(timer);

    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();

    delete ac;
    delete dc;
    delete timer;
    return 0;
}
