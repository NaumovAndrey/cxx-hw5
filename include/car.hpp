#pragma once
#include <string>
#include <iostream> 


class Car {
public:
    // Конструктор и деструктор
    Car(std::string tradeMark, int numberCelinders = 0, int power = 0);
    virtual ~Car() = default;

    // Интерфейс (геттеры и сеттеры)
    std::string getTradeMark() const;
    int getNumberCelinders() const;
    int getPower() const;

    void setTradeMark(const std::string& tradeMark);
    void setNumberCelinders(int numberCelinders);
    void setPower(int power);

    // Чистая виртуальная функция
    virtual void displayInfo() const = 0;

    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream&, const Car&);
    friend std::istream& operator>>(std::istream&, Car&);

private:
    std::string m_tradeMark;
    int m_numberCelinders;
    int m_power;
};