#pragma once

#include "Vehicle.h"

class Car : public Vehicle  // Car наслідує Vehicle публічно
{
    int doors;  // власне поле, якого немає у Vehicle

public:
    Car();
    int SetDoors(int num_doors);

    int MakeSound() override;  // перевизначаємо батьківський метод
    int MakeSound(int volume) override;

    using Vehicle::ShowInfo;  // підтягуємо перевантаження з батька
    int ShowInfo(bool show_doors);  // додаємо своє перевантаження
};