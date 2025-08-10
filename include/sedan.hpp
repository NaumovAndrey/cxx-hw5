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
Sedan(std::string tradeMark, int numberCelinders, int power);

// Деструктор
~Sedan() override = default;

// Метод для печати
void displayInfo() const override;

friend std::istream& operator>>(std::istream& in, Sedan& sedan);

};
