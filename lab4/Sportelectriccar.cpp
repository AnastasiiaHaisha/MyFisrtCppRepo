#include "SportElectricCar.h"

SportElectricCar::SportElectricCar(
    std::string brand, int speed, int year,
    int battery, int range,
    std::string car_color, float accel)
{
    SetBrand(brand);   // з Vehicle (через ланцюжок наслідування)
    SetSpeed(speed);   // з Vehicle
    SetYear(year);     // з Vehicle
    SetBattery(battery); // з ElectricCar
    SetRange(range);     // з ElectricCar
    color = car_color;   // власне поле
    acceleration_0_100 = accel; // власне поле

    ShowFullInfo();
    MakeSound();
}

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

int SportElectricCar::MakeSound()
{
    std::cout << "[SportElectricCar] ~~ whoosh ~~ (silent speed)\n";
    return 1;
}

int SportElectricCar::ShowFullInfo()
{
    ShowInfo("Sport Electric Car"); // Vehicle::ShowInfo(string) - через ланцюжок
    ShowBatteryInfo();              // ElectricCar::ShowBatteryInfo()
    std::cout << "   Color: " << color
              << " | 0-100 km/h: " << acceleration_0_100 << "s\n";
    return 1;
}