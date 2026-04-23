#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
    int doors;   // нова приватна властивість

public:
    Car();
    int SetDoors(int num_doors);

    int MakeSound() override;           // Override без параметра
    int MakeSound(int volume) override; // Override з гучністю

    // Відкриваємо успадковані overload-и ShowInfo з Vehicle
    using Vehicle::ShowInfo;
    int ShowInfo(bool show_doors);      // Overload ShowInfo з bool
};