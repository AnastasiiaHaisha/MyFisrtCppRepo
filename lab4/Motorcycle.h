#pragma once

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
    std::string type;

public:
    Motorcycle();
    int SetType(const std::string& moto_type);  // const& — без копіювання

    int MakeSound() override;
    // MakeSound(int) НЕ перевизначено — викличеться Vehicle::MakeSound(int)
};