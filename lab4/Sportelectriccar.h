#pragma once

#include "ElectricCar.h"

class SportElectricCar : public ElectricCar
{
    std::string color;
    float acceleration_0_100;

public:
    SportElectricCar(
        std::string brand, int speed, int year,
        int battery, int range,
        std::string car_color, float accel);

    int SetColor(std::string car_color);
    int SetAcceleration(float accel);

    int MakeSound() override;
    int ShowFullInfo();
};