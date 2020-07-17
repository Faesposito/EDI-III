/************** Factory Design Pattern *************
 *  Franco Esposito.
 *  Edi III.
 ***************************************************/

#ifndef ICOMPUTER_H
#define ICOMPUTER_H

class IComputer
{
public:
    virtual ~IComputer(){};
    virtual void Run() = 0;
    virtual void Stop() = 0;
};

#endif // ICOMPUTER_H