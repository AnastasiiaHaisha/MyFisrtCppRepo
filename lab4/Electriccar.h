#pragma once

#include "Car.h"

class ElectricCar : public Car
{
protected:
    int battery_capacity;
    int range_km;

public:
    ElectricCar(int battery, int range);
    ElectricCar();

    int SetBattery(int battery);
    int SetRange(int range_km);

    int MakeSound() override;

    int ShowBatteryInfo();
}