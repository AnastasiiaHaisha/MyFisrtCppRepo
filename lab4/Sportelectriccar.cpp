#include "SportElectricCar.h"

SportElectricCar::SportElectricCar(
    std::string brand, int speed, int year,
    int battery, int range,
    std::string car_color, float accel)
{
    SetBrand(brand);
    SetSpeed(speed);
    SetYear(year);
    SetBattery(battery);
    SetRange(range);
    color = car_color;
    acceleration_0_100 = accel;

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
    ShowInfo("Sport Electric Car");
    ShowBatteryInfo();
    std::cout << "   Color: " << color
              << " | 0-100 km/h: " << acceleration_0_100 << "s\n";
    return 1;
}