#pragma once

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
    std::string type;

public:
    Motorcycle();
    int SetType(std::string moto_type);

    int MakeSound() override;
};