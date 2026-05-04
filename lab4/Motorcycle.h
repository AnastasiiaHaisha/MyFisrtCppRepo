#pragma once

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
    std::string type;  // власне поле "тип мотоцикла"

public:
    Motorcycle();
    int SetType(std::string moto_type);

    int MakeSound() override;  // тільки без параметра - MakeSound(int) НЕ перевизначено
};