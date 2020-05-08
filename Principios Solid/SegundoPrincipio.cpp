//******************* Segundo Principio Solid: Principio de Abierto/Cerrado *************************//

//***** Alumno: Franco Agustin Esposito.
//***** Cursada: Edi III.

#include <iostream>

//************ Interfaces ************//
class ICar
{
public:
    virtual ~ICar(){};
    virtual std::string getCarBrand() = 0;
    virtual int mediumPrice() = 0;
};

//************************************//

//************* Clases *************//
class Car : public ICar
{
public:
    Car(std::string brand, int price)
    {
        m_brand = brand;
        m_price = price;
    }

    ~Car() {}

    std::string getCarBrand()
    {
        return m_brand;
    }

    int mediumPrice()
    {
        return m_price;
    }

private:
    std::string m_brand;
    int m_price = 0;
};

class Truck : public ICar
{
public:
    Truck(std::string brand, int price)
    {
        m_brand = brand;
        m_price = price;
    }

    ~Truck() {}

    std::string getCarBrand()
    {
        return m_brand;
    }

    int mediumPrice()
    {
        return m_price;
    }

private:
    std::string m_brand;
    int m_price = 0;
};

class LuxaryCar : public ICar
{
public:
    LuxaryCar(std::string brand, int price)
    {
        m_brand = brand;
        m_price = price;
    }

    ~LuxaryCar() {}

    std::string getCarBrand()
    {
        return m_brand;
    }

    int mediumPrice()
    {
        return m_price;
    }

private:
    std::string m_brand;
    int m_price = 0;
};

//**********************************//

//*********** Functions ***********//
void printCar(ICar *car)
{
    std::cout << "la marca del coche es: " << car->getCarBrand() << " y tiene un precio de " << car->mediumPrice() << std::endl;
}

//*********************************//

//************ Main ***************//

int main()
{
    ICar *car1 = new Car("Ford", 1000);
    ICar *car2 = new Truck("Scania", 2000);
    ICar *car3 = new LuxaryCar("Ferrari", 1000000);

    printCar(car1);
    printCar(car2);
    printCar(car3);

    return 0;
}