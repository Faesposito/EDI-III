/************** Factory Design Pattern *************
 *  Franco Esposito.
 *  Edi III.
 ***************************************************/

#ifndef DESKTOP_H
#define DESKTOP_H

#include "IComputer.h"

class Desktop : public IComputer
{
public:
    virtual ~Desktop(){};
    void Run() { std::cout << "Desktop Is Running" << std::endl; };
    void Stop() { std::cout << "Desktop has Stopped" << std::endl; };
};

#endif // DESKTOP_H