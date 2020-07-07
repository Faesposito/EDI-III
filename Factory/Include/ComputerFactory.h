/************** Factory Design Pattern *************
 *  Franco Esposito.
 *  Edi III.
 ***************************************************/

#ifndef COMPUTERFACTORY_H
#define COMPUTERFACTORY_H

#include "IComputer.h"
#include "Laptop.h"
#include "Desktop.h"

class ComputerFactory
{
public:
    static IComputer *NewComputer(const std::string &description)
    {
        if (description == "laptop")
            return new Laptop;
        if (description == "desktop")
            return new Desktop;
        return nullptr;
    }
    void doSomething(const std::string &description)
    {
        IComputer *computer = this->NewComputer(description);
        computer->Run();
        computer->Stop();
    }
};

#endif // COMPUTERFACTORY_H