#pragma once
#include "Car.h"

// ElectricCar успадковує Car — додає властивості електромобіля
class ElectricCar : public Car
{
protected:
    int battery_capacity; // ємність батареї у кВт·год
    int range_km;         // запас ходу у км

public:
    // Конструктор з параметрами (ємність батареї та запас ходу)
    ElectricCar(int battery, int range);

    // Пустий конструктор — потрібен для нащадків (SportElectricCar)
    ElectricCar();

    int SetBattery(int battery);
    int SetRange(int range_km);

    // Перевизначений метод звуку — електромобіль тихіший
    int MakeSound() override;

    // Новий метод, специфічний для електромобіля
    int ShowBatteryInfo();
};