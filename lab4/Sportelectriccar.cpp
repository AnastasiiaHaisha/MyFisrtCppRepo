#include "SportElectricCar.h"

// Конструктор з повним набором параметрів
SportElectricCar::SportElectricCar(
    std::string brand, int speed, int year,
    int battery, int range,
    std::string car_color, float accel)
{
    // З Vehicle (через public успадкування):
    SetBrand(brand);
    SetSpeed(speed);
    SetYear(year);

    // З ElectricCar (через public setters або protected напряму):
    SetBattery(battery);
    SetRange(range);

    // Власні поля:
    color = car_color;
    acceleration_0_100 = accel;

    ShowFullInfo();   // власний метод
    MakeSound();      // власний override
}

// Сетери
int SportElectricCar::SetColor(std::string car_color)
{
    color = car_color;
    return 1;
}

int SportElectricCar::SetAcceleration(float accel)
{
    acceleration_0_100 = accel;
    return 1;
}

// Override MakeSound — четверте перевизначення у ланцюжку
int SportElectricCar::MakeSound()
{
    std::cout << "[SportElectricCar] WHOOOOSH! Zero to 100 in "
              << acceleration_0_100 << "s!\n";
    return 1;
}

// Комбінований вивід усієї інформації
int SportElectricCar::ShowFullInfo()
{
    ShowInfo("Sport Electric Vehicle");  // overload з батька (Vehicle)
    ShowBatteryInfo();                   // метод ElectricCar
    std::cout << "   Color: " << color
              << " | 0-100 km/h: " << acceleration_0_100 << " sec\n";
    return 1;
}