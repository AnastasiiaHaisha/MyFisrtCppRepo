#pragma once
#include "ElectricCar.h"

// SportElectricCar — найглибший у ієрархії клас
// Успадковує: Vehicle -> Car -> ElectricCar -> SportElectricCar
class SportElectricCar : public ElectricCar
{
    std::string color;        // колір кузова
    float acceleration_0_100; // розгін 0-100 км/год у секундах

public:
    // Конструктор з повними параметрами
    SportElectricCar(std::string brand,
                     int         speed,
                     int         year,
                     int         battery,
                     int         range,
                     std::string color,
                     float       accel);

    int SetColor(std::string car_color);
    int SetAcceleration(float accel);

    // Перевизначений метод звуку — спорткар навіть як EV звучить потужніше
    int MakeSound() override;

    // Повний вивід всієї інформації про авто
    int ShowFullInfo();
};