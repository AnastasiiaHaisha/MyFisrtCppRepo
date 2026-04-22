#pragma once
#include "Vehicle.h"

// Клас Motorcycle — другий прямий нащадок Vehicle
class Motorcycle : public Vehicle
{
    // Тип мотоцикла (спортивний, круізер тощо)
    std::string type;

public:
    // Конструктор за замовчуванням
    Motorcycle();

    int SetType(std::string moto_type);

    // Перевизначений метод звуку
    int MakeSound() override;
};