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

    return 0;
}