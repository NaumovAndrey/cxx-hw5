#include "sedan.hpp"

Sedan::Sedan(){}
Sedan::Sedan(std::string tradeMark, int numberCelinders, int power) :
    Car(tradeMark, numberCelinders, power) {}

Sedan &Sedan::operator=(const Sedan &other)
{
    if(this != &other) {
        Car::operator=(other);

        return *this;
    }
}

Sedan::Sedan(const Sedan &other) : Car(other) {}

void Sedan::displayInfo() const
{
    {
    std::cout << fmt::format(
        "{:10}\t{:5}\t{:5}",
        getTradeMark(),
        getNumberCelinders(),
        getPower()
    ) << std::endl;
    }
}

Sedan::Sedan(const Sedan &other) : Car(other)

std::unique_ptr<Car> Sedan::clone() const
{
    return std::make_unique<Sedan>(*this);
}
