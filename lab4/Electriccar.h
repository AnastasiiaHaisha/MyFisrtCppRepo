#pragma once

#include "Car.h"

class ElectricCar : public Car  // наслідує Car, а не Vehicle напряму
{
protected:  // protected - бо SportElectricCar теж буде їх використовувати
    int battery_capacity;
    int range_km;

public:
    ElectricCar(int battery, int range);  // конструктор з параметрами
    ElectricCar();                        // конструктор без параметрів

    int SetBattery(int battery);
    int SetRange(int range_km);

    int MakeSound() override;

    int ShowBatteryInfo();
};