/********************************* Notifier Interface **********************************/

#ifndef INOTIFIER_H
#define INOTIFIER_H

class INotifier
{
public:
    virtual ~INotifier(void) {}
    virtual void notify(void) = 0;
};

#endif // INOTIFIER_H
