/*********************************Main Observer Pattern**********************************/

#include <iostream>

#include "ISubscriber.h"
#include "INotifier.h"
#include "IClockTimer.h"

#include "ClockTimer.h"
#include "ChangeManager.h"
#include "AnalogClock.h"
#include "DigitalClock.h"

int main()
{
    ChangeManager *changeManager = new ChangeManager();
    INotifier *notifier = changeManager;
    ISubscriber *subscriber = changeManager;

    IClockTimer *timer = new ClockTimer(notifier);

    //VIEW
    AnalogClock *analogClock = new AnalogClock(timer, subscriber);
    DigitalClock *digitalClock = new DigitalClock(timer, subscriber);

    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();

    delete analogClock;
    delete digitalClock;
    delete timer;

    return 0;
}
