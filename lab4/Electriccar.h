#pragma once

#include "Car.h"

class ElectricCar : public Car
{
protected:
    int battery_capacity;   // кВт·год — protected для доступу нащадків
    int range_km;           // запас ходу — protected

public:
    ElectricCar(int battery, int range);   // конструктор з параметрами
    ElectricCar();                          // пустий конструктор для нащадків

    int SetBattery(int battery);
    int SetRange(int range_km);

    int MakeSound() override;

    int ShowBatteryInfo();                  // новий метод класу
};