//******************* Primer Principio Solid: Principio de responsabilidad única *************************//

//***** Alumno: Franco Agustin Esposito.
//***** Cursada: Edi III.

#include <iostream>

//************ Interfaces ************//
class ICar
{
public:
    virtual ~ICar(){};
    virtual std::string getCarBrand() = 0;
};

class ICarDB
{
public:
    virtual ~ICarDB() {}
    virtual void saveCarInDB(ICar *car) = 0;
    virtual void deleteCarOfDB(ICar *car) = 0;
};
//************************************//

//************* Clases *************//
class Car : public ICar
{
public:
    Car(std::string brand)
    {
        m_brand = brand;
    }

    ~Car() {}

    std::string getCarBrand()
    {
        return m_brand;
    }

private:
    std::string m_brand;
};

class CarDB : public ICarDB
{
public:
    CarDB() {}
    ~CarDB() {}

    void saveCarInDB(ICar *car)
    {
        std::cout << "Car " << car->getCarBrand() << " saved from DB." << std::endl;
    }

    void deleteCarOfDB(ICar *car)
    {
        std::cout << "Car " << car->getCarBrand() << " deleted from DB." << std::endl;
    }
};

//**********************************//

//*********** Functions ***********//
void printBrand(ICar *car)
{
    std::cout << "la marca del coche es: " << car->getCarBrand() << std::endl;
}
//*********************************//

//************ Main ***************//

int main()
{
    ICar *car1 = new Car("Ford");
    ICar *car2 = new Car("Fiat");
    ICar *car3 = new Car("Ferrari");

    printBrand(car1);
    printBrand(car2);
    printBrand(car3);

    ICarDB *DBHandler = new CarDB();

    DBHandler->saveCarInDB(car1);
    DBHandler->saveCarInDB(car2);
    DBHandler->saveCarInDB(car3);

    DBHandler->deleteCarOfDB(car1);

    return 0;
}