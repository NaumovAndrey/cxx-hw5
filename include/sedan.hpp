#pragma once
#include "car.hpp"
#include <iostream>
#include <string>
#include <iterator>
#include <fmt/format.h>

class Sedan : public Car 
{
public:
// Конструктор
Sedan();
Sedan(std::string tradeMark, int numberCelinders, int power);


// Деструктор
~Sedan() override = default;

//реализация оператора присваивания
Sedan& operator=(const Sedan& other);

// Конструктор копирования
Sedan(const Sedan& other);

// Метод для печати
void displayInfo() const override;

// Перегрузка метода (оператора копирования)
std::unique_ptr<Car> clone() const override;

friend std::istream& operator>>(std::istream& in, Sedan& sedan);

};
