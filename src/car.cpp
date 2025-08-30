#include "car.hpp"


unsigned long Car::m_carCount = 0;

// Конструкторы
Car::Car() {}
Car::Car(std::string tradeMark, int numberCelinders, int power) :
    m_tradeMark(tradeMark), m_numberCelinders(numberCelinders), m_power(power)
{
    updateCarCount(true);
}
 
Car::~Car()
{
    updateCarCount(false); 
}

//Конструктор копирования
//Car(const Car& other) : 
//    m_tradeMark(other.m_tradeMark), m_numberCelinders(other.m_numberCelinders), m_power(other.m_power) {}

// Геттеры
std::string Car::getTradeMark() const {
    return m_tradeMark;
}

int Car::getNumberCelinders() const {
    return m_numberCelinders;
}

int Car::getPower() const {
    return m_power;
}

unsigned long Car::getCarCount()
{
    return m_carCount;
}

// Сеттеры
void Car::setTradeMark(const std::string& tradeMark) {
    m_tradeMark = tradeMark;
}

void Car::setNumberCelinders(int numberCelinders) {
    m_numberCelinders = numberCelinders;
}

void Car::setPower(int power) {
    m_power = power;
}

// Реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const Car& car) {
    car.displayInfo();
    return os;
}

// Реализация оператора ввода
std::istream& operator>>(std::istream& in, Car& car) {
    std::string tradeMark;
    int numberCelinders, power;

    std::cout << "Enter Trademark: ";
    in >> tradeMark;
    std::cout << "Enter Number of Cylinders: ";
    in >> numberCelinders;
    std::cout << "Enter Engine Power: ";
    in >> power;

    car.setTradeMark(tradeMark);
    car.setNumberCelinders(numberCelinders);
    car.setPower(power);

    return in;
}

void Car::updateCarCount(bool increase)
{
    if (increase)
    {
        ++Car::m_carCount;
    }
    else
    {
        --Car::m_carCount;
    }
}

