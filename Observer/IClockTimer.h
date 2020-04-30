/********************************* Clock Timer Interface ************************************/

#ifndef ICLOCKTIMER_H
#define ICLOCKTIMER_H

class ClockTimer
{
public:
    virtual ~ClockTimer() {}

    virtual int getHour() = 0;

    virtual int getMinute() = 0;

    virtual int getSecond() = 0;

    virtual void Tick() = 0;
};

#endif // ICLOCKTIMER_H
