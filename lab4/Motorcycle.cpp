#include "Motorcycle.h"

// Конструктор: типові значення для мотоцикла
Motorcycle::Motorcycle()
{
    SetBrand("Generic Moto");
    SetSpeed(220);
    SetYear(2015);
    type = "Standard";

    std::cout << "[Motorcycle created] ";
    ShowInfo();
    MakeSound();
}

int Motorcycle::SetType(std::string moto_type)
{
    type = moto_type;
    return 1;
}

// Мотоцикл видає зовсім інший звук — перевизначення polymorphism у дії
int Motorcycle::MakeSound()
{
    std::cout << "[Motorcycle] Vroom-vroom! Type: " << type << "\n";
    return 1;
}