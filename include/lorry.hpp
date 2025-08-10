#pragma once
#include "car.hpp"
#include <iostream>
#include <string>
#include <iterator>
#include <fmt/format.h>


class Lorry : public Car {
public:
    // Конструктор
    Lorry(std::string tradeMark, int numberCelinders, int power, int bodyLoadCapacity);

    // Деструктор
    ~Lorry() override = default;

    // Метод для печати
    void displayInfo() const override;

    // Получение грузоподъемности
    int getBodyLoadCapacity() const;

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& in, Lorry& lorry);

private:
    int m_bodyLoadCapacity;
};
