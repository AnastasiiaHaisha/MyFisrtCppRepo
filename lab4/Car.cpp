#include "Car.h"

Car::Car()
{
    SetBrand("Generic Car");
    SetSpeed(180);
    SetYear(2010);
    doors = 4;

    std::cout << "[Car created] ";
    ShowInfo();
    MakeSound();
}

int Car::SetDoors(int num_doors)
{
    doors = num_doors;
    return 1;
}

int Car::MakeSound()
{
    std::cout << "[Car] Beep-beep! Doors: " << doors << "\n";
    return 1;
}

int Car::MakeSound(int volume)
{
    std::cout << "[Car] Beep";
    if (volume > 70) std::cout << "-BEEP";
    std::cout << "! (" << volume << "%) Doors: " << doors << "\n";
    return 1;
}

int Car::ShowInfo(bool show_doors)
{
    Vehicle::ShowInfo();
    if (show_doors)
        std::cout << "   Doors: " << doors << "\n";
    return 1;
}