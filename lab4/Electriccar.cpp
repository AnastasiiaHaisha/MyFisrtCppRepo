#include "ElectricCar.h"

// Параметризований конструктор: повна ініціалізація
ElectricCar::ElectricCar(int battery, int range)
{
    SetBrand("Generic EV");
    SetSpeed(250);
    SetYear(2022);
    battery_capacity = battery;
    range_km = range;

    ShowInfo("Electric vehicle");  // overload з параметром
    ShowBatteryInfo();
    MakeSound();
}

// Пустий конструктор: мінімальна ініціалізація для нащадків
ElectricCar::ElectricCar()
{
    battery_capacity = 0;
    range_km = 0;
}

// Сетери
int ElectricCar::SetBattery(int battery)
{
    battery_capacity = battery;
    return 1;
}

int ElectricCar::SetRange(int range)
{
    range_km = range;
    return 1;
}

// Override MakeSound
int ElectricCar::MakeSound()
{
    std::cout << "[ElectricCar] *silent hum* ...\n";
    return 1;
}

// Вивід інформації про батарею
int ElectricCar::ShowBatteryInfo()
{
    std::cout << "   Battery: " << battery_capacity
              << " kWh | Range: " << range_km << " km\n";
    return 1;
}