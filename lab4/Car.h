#pragma once
#include "Vehicle.h"

// Клас Car успадковує Vehicle через public-успадкування
// (всі public-методи батька залишаються публічними)
class Car : public Vehicle
{
    // Додаткове поле: кількість дверей
    int doors;

public:
    // Конструктор за замовчуванням встановлює типові значення для легкового авто
    Car();

    // Сетер для кількості дверей
    int SetDoors(int num_doors);

    // Перевизначений метод звуку (override)
    int MakeSound() override;
};