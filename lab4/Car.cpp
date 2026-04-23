#include "Car.h"

// Конструктор Car
Car::Car()
{
    SetBrand("Generic Car");   // виклик методу батька
    SetSpeed(180);              // виклик методу батька
    SetYear(2010);              // виклик методу батька
    doors = 4;

    std::cout << "[Car created] ";
    ShowInfo();                 // виклик успадкованого overload-методу
    MakeSound();
}

// Сетер
int Car::SetDoors(int num_doors)
{
    doors = num_doors;
    return 1;
}

// Override MakeSound без параметра
int Car::MakeSound()
{
    std::cout << "[Car] Beep-beep! Doors: " << doors << "\n";
    return 1;
}

// Override MakeSound з гучністю
int Car::MakeSound(int volume)
{
    std::cout << "[Car] Beep";
    if (volume > 70) std::cout << "-BEEP";
    std::cout << "! (" << volume << "%) Doors: " << doors << "\n";
    return 1;
}

// Overload ShowInfo з bool
int Car::ShowInfo(bool show_doors)
{
    // Викликаємо батьківський ShowInfo() без параметра
    Vehicle::ShowInfo();
    if (show_doors)
        std::cout << "   Doors: " << doors << "\n";
    return 1;
}