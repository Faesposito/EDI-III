/**********************************OBSERVER INTERFACE************************************/
/**An abstract class defines the Observer interface:**/

#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void Update() = 0;
};

#endif // IOBSERVER_H