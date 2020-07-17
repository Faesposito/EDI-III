/************** Factory Design Pattern *************
 *  Franco Esposito.
 *  Edi III.
 ***************************************************/

#ifndef LAPTOP_H
#define LAPTOP_H

#include "IComputer.h"

class Laptop : public IComputer
{
public:
    virtual ~Laptop(){};
    void Run() { std::cout << "Laptop Is Running" << std::endl; };
    void Stop() { std::cout << "Laptop has Stopped" << std::endl; };
};

#endif // LAPTOP_H