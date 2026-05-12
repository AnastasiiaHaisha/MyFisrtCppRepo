#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
    int doors;

public:
    Car();
    int SetDoors(int num_doors);

    int MakeSound() override;
    int MakeSound(int volume) override;

    using Vehicle::ShowInfo;
    int ShowInfo(bool show_doors);
};