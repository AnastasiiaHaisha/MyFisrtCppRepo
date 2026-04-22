#include "ElectricCar.h"

// Конструктор з параметрами — отримує дані про батарею та запас ходу
ElectricCar::ElectricCar(int battery, int range)
{
    // Перевизначаємо значення батьківського класу Car
    SetBrand("Generic EV");
    SetSpeed(200);
    SetYear(2020);

    battery_capacity = battery;
    range_km         = range;

    std::cout << "[ElectricCar created] ";
    ShowInfo("Electric vehicle");
    ShowBatteryInfo();
    MakeSound();
}

// Пустий конструктор — викликає конструктор Car,
// нащадки зможуть самі встановити поля
ElectricCar::ElectricCar()
{
    battery_capacity = 0;
    range_km         = 0;
}

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

// Електромобіль майже безшумний — поліморфна реалізація
int ElectricCar::MakeSound()
{
    std::cout << "[ElectricCar] *silent hum* ...\n";
    return 1;
}

// Додатковий метод — виводить інформацію про батарею
int ElectricCar::ShowBatteryInfo()
{
    std::cout << "   Battery: " << battery_capacity
              << " kWh | Range: " << range_km << " km\n";
    return 1;
}