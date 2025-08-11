#include "lorry.hpp"

// Конструктор
Lorry::Lorry(std::string tradeMark, int numberCelinders, int power, int bodyLoadCapacity) :
    Car(tradeMark, numberCelinders, power), m_bodyLoadCapacity(bodyLoadCapacity) {}


// Метод отображения информации
void Lorry::displayInfo() const {
    std::cout << fmt::format(
        "{:10}\t{:5}\t{:5}\t{:5}",
        getTradeMark(),
        getNumberCelinders(),
        getPower(),
        getBodyLoadCapacity()
    ) << std::endl;
}

//Метод клонирования объекта (для создания копии объекта). За место конструктора копирования
std::unique_ptr<Car> Lorry::clone() const
{
    return std::make_unique<Lorry>(*this);
}

// Геттер грузоподъемности
int Lorry::getBodyLoadCapacity() const {
    return m_bodyLoadCapacity;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& in, Lorry& lorry) {
    std::string tradeMark;
    int numberCelinders, power, bodyLoadCapacity;

    std::cout << "Введите марку: ";
    in >> tradeMark;
    std::cout << "Введите количество цилиндров: ";
    in >> numberCelinders;
    std::cout << "Введите мощность двигателя: ";
    in >> power;
    std::cout << "Введите грузоподъемность: ";
    in >> bodyLoadCapacity;

    lorry.setTradeMark(tradeMark);
    lorry.setNumberCelinders(numberCelinders);
    lorry.setPower(power);
    lorry.m_bodyLoadCapacity = bodyLoadCapacity;

    return in;
}