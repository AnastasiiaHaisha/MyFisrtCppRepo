#include "Motorcycle.h"

// Конструктор Motorcycle
Motorcycle::Motorcycle()
{
    SetBrand("Generic Motorcycle");
    SetSpeed(200);
    SetYear(2015);
    type = "Standard";

    std::cout << "[Motorcycle created] ";
    ShowInfo();
    MakeSound();
}

// Сетер
int Motorcycle::SetType(std::string moto_type)
{
    type = moto_type;
    return 1;
}

// Override MakeSound
int Motorcycle::MakeSound()
{
    std::cout << "[Motorcycle] Vroom-vroom! Type: " << type << "\n";
    return 1;
}