#pragma once

#include "ElectricCar.h"

class SportElectricCar : public ElectricCar
{
    std::string color;
    float acceleration_0_100;

public:
    SportElectricCar(
        const std::string& brand, int speed, int year,  // const& — без копіювання
        int battery, int range,
        const std::string& car_color, float accel);     // const& — без копіювання

    int SetColor(const std::string& car_color);         // const& — без копіювання
    int SetAcceleration(float accel);

    int MakeSound() override;
    int ShowFullInfo();
};