#pragma once
#include <string>
#include <iostream> 
#include <memory>


class Car {
public:
    // Конструктор и деструктор
    Car();
    Car(std::string tradeMark="null", int numberCelinders = 0, int power = 0);
    virtual ~Car() = default;
    
    //Конструктор копирования
    //Car(const Car& other);

    // Интерфейс (геттеры и сеттеры)
    std::string getTradeMark() const;
    int getNumberCelinders() const;
    int getPower() const;

    void setTradeMark(const std::string& tradeMark);
    void setNumberCelinders(int numberCelinders);
    void setPower(int power);

    // Чистая виртуальная функция
    virtual void displayInfo() const = 0;
    virtual std::unique_ptr<Car> clone() const = 0;

    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream&, const Car&);
    friend std::istream& operator>>(std::istream&, Car&);

private:
    std::string m_tradeMark;
    int m_numberCelinders;
    int m_power;
};