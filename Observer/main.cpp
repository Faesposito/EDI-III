/*********************************Main Observer Pattern**********************************/

#include <iostream>

#include "ISubscriber.h"
#include "INotifier.h"
#include "IWidget.h"

#include "ClockTimer.h"
#include "ChangeManager.h"
#include "AnalogClock.h"
#include "DigitalClock.h"

int main()
{
    INotifier *notifier = new ChangeManager();
    ISubscriber *subscriber = new ChangeManager();

    ClockTimer *timer = new ClockTimer(notifier);

    //VIEW
    AnalogClock *analogClock = new AnalogClock(timer, subscriber);
    DigitalClock *digitalClock = new DigitalClock(timer, subscriber);

    analogClock->draw();
    digitalClock->draw();
    analogClock->draw();
    digitalClock->draw();
    analogClock->draw();
    digitalClock->draw();
    analogClock->draw();
    digitalClock->draw();

    delete analogClock;
    delete digitalClock;
    delete timer;

    return 0;
}
