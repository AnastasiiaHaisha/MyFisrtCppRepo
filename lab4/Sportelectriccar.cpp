#include "SportElectricCar.h"

// Конструктор викликає пустий конструктор ElectricCar (не перевантажений),
// а потім встановлює всі поля вручну через сетери
SportElectricCar::SportElectricCar(std::string brand,
                                   int         speed,
                                   int         year,
                                   int         battery,
                                   int         range,
                                   std::string car_color,
                                   float       accel)
{
    // Поля з Vehicle (через public-успадкування доступні сетери)
    SetBrand(brand);
    SetSpeed(speed);
    SetYear(year);

    // Поля з ElectricCar (protected — доступні напряму або через сетери)
    SetBattery(battery);
    SetRange(range);

    // Власні поля
    color             = car_color;
    acceleration_0_100 = accel;

    std::cout << "[SportElectricCar created]\n";
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

// Спортивний електромобіль видає агресивніший звук — ще одне перевизначення
int SportElectricCar::MakeSound()
{
    std::cout << "[SportElectricCar] WHOOOOSH! Zero to 100 in "
              << acceleration_0_100 << "s!\n";
    return 1;
}

// Повний вивід: використовуємо перевантажений ShowInfo(comment) з Vehicle
int SportElectricCar::ShowFullInfo()
{
    // Викликаємо перевантажену версію ShowInfo з параметром (з класу Vehicle)
    ShowInfo("Sport Electric Vehicle");
    ShowBatteryInfo(); // метод з ElectricCar
    std::cout << "   Color: " << color
              << " | 0-100 km/h: " << acceleration_0_100 << " sec\n";
    return 1;
}