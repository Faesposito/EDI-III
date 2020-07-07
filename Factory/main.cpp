/************** Factory Design Pattern *************
 *  Franco Esposito.
 *  Edi III.
 ***************************************************/

#include <iostream>
#include "include/ComputerFactory.h"

void userChoice(ComputerFactory &computerFactory)
{
    std::string description;
    std::cout << "select type of computer: ";
    std::cin >> description;
    computerFactory.doSomething(description);
}

int main()
{
    ComputerFactory *computerFactory = new ComputerFactory();

    userChoice(*computerFactory);
    userChoice(*computerFactory);

    delete computerFactory;

    return 0;
}
