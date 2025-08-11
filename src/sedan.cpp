#include "sedan.hpp"

Sedan::Sedan(std::string tradeMark, int numberCelinders, int power) :
    Car(tradeMark, numberCelinders, power) {}

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

std::unique_ptr<Car> Sedan::clone() const
{
    return std::make_unique<Sedan>(*this);
}
