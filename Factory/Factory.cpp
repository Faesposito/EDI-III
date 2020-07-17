/************** Factory Design Pattern *************
 *  Franco Esposito.
 *  Edi III.
 ***************************************************/

#include <iostream>

class Computer
{
public:
    virtual ~Computer(){};
    virtual void Run() = 0;
    virtual void Stop() = 0;
};

class Laptop : public Computer
{
public:
    virtual ~Laptop(){};
    void Run() { std::cout << "Laptop Is Running" << std::endl; };
    void Stop() { std::cout << "Laptop has Stopped" << std::endl; };
};

class Desktop : public Computer
{
public:
    virtual ~Desktop(){};
    void Run() { std::cout << "Desktop Is Running" << std::endl; };
    void Stop() { std::cout << "Desktop has Stopped" << std::endl; };
};

class ComputerFactory
{
public:
    static Computer *CreateComputer(const std::string &description)
    {
        if (description == "laptop")
            return new Laptop;
        if (description == "desktop")
            return new Desktop;
        return nullptr;
    }
    void doSomething(const std::string &description)
    {
        Computer *computer = this->CreateComputer(description);
        computer->Run();
        computer->Stop();
    }
};

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

    return 0;
}
