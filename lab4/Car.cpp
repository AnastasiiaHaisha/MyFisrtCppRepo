#include "Car.h"

// Конструктор: встановлюємо типові значення через методи батьківського класу
Car::Car()
{
    SetBrand("Generic Car");
    SetSpeed(180);
    SetYear(2010);
    doors = 4;

    // Виводимо інформацію при створенні об'єкта
    std::cout << "[Car created] ";
    ShowInfo();
    MakeSound();
}

int Car::SetDoors(int num_doors)
{
    doors = num_doors;
    return 1;
}

// Перевизначення MakeSound — легковик гудить інакше, ніж базовий Vehicle
int Car::MakeSound()
{
    std::cout << "[Car] Beep-beep! Doors: " << doors << "\n";
    return 1;
}