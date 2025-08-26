#pragma once
#include <string>
#include <iostream> 
#include <memory>


class Car {
public:
    // Конструктор и деструктор
    Car();
    Car(std::string tradeMark="null", int numberCelinders = 0, int power = 0);
    virtual ~Car();
    
    //Конструктор копирования
    //Car(const Car& other);

    // Интерфейс (геттеры и сеттеры)
    std::string getTradeMark() const;
    int getNumberCelinders() const;
    int getPower() const;
    static unsigned long getCarCount();

    void setTradeMark(const std::string& tradeMark);
    void setNumberCelinders(int numberCelinders);
    void setPower(int power);

    // Дефолтный конструктор копирования
    Car(const Car& other) = default;

    // Дефолтный конструктор перемещения
    Car(Car&& other) noexcept = default;

    // Вывод информации
    virtual void displayInfo() const = 0;

    // Замена оператора копирования
    virtual std::unique_ptr<Car> clone() const = 0;

    // Перегрузка операторов вывода и ввода
    friend std::ostream& operator<<(std::ostream&, const Car&);
    friend std::istream& operator>>(std::istream&, Car&);

    static void updateCarCount(bool increase);

protected:
    std::string m_tradeMark;
    int m_numberCelinders;
    int m_power;

    static unsigned long m_carCount;
};