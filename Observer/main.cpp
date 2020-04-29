/*********************************Main Observer Pattern**********************************/

#include <iostream>

#include "include/ISubscriber.h"
#include "include/INotifier.h"
#include "include/IWidget.h"

#include "include/ClockTimer.h"
#include "include/ChangeManager.h"
#include "include/AnalogClock.h"
#include "include/DigitalClock.h"

int main()
{
    INotifier *notifier = ChangeManager::createChangeManager();
    ISubscriber *subscriber = ChangeManager::createChangeManager();

    ClockTimer *timer = new ClockTimer(notifier);

    //VIEW
    AnalogClock *analogClock = new AnalogClock(timer, subscriber);
    DigitalClock *digitalClock = new DigitalClock(timer, subscriber);

    timer->Tick();
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
