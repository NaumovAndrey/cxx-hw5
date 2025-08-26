#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <lorry.hpp>
#include <sedan.hpp>

int main()
{
    std::vector<std::unique_ptr<Car>> cars;

    cars.push_back(std::make_unique<Lorry>("Tonar", 4, 500, 40));
    cars.push_back(std::make_unique<Sedan>("Mercedes", 6, 300));
    cars.push_back(std::make_unique<Sedan>("Audi", 4, 250));
    cars.push_back(std::make_unique<Sedan>("Lada", 0, 50));
    cars.push_back(std::make_unique<Sedan>("Ford", 4, 150));

    std::for_each(cars.begin(), cars.end(), [](const std::unique_ptr<Car>& car_ptr) {
        std::cout << *car_ptr << "\n";
    });

    //Копирование объектов
    Lorry lorry("Tonar500", 4, 600, 50);
    auto lorry_ptr = lorry.clone();

    Sedan sedan("Lada21120", 2, 50);
    auto sedan_ptr = sedan.clone();

    std::cout << *lorry_ptr << "\n";
    std::cout << *sedan_ptr << "\n";


    //Копирование объектов
    auto lorry_ptr2(lorry);
    auto lorry_ptr3(std::make_unique<Lorry>(lorry));
    std::cout << "lorry_ptr2: " << lorry_ptr2 << "\n";
    std::cout << "lorry_ptr3: " << *lorry_ptr3 << "\n";

    //Перемещение объектов
    auto lorry_ptr4(std::move(lorry));
    std::cout << "lorry_ptr4: " << lorry_ptr4 << "\n";
    std::cout << "lorry: " << lorry << "\n";

    std::cout << "cars: " << Car::getCarCount() << "\n";

    return 0;
}