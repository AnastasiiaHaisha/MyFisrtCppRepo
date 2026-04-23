#pragma once

#include <iostream>
#include <string>

class Vehicle
{
    // PRIVATE поля — доступні лише всередині класу
    std::string brand;   // марка
    int speed;           // максимальна швидкість
    int year;            // рік випуску

public:
    Vehicle();           // конструктор за замовчуванням
    virtual ~Vehicle() = default;  // virtual деструктор для коректного delete

    // Сетери
    int SetBrand(std::string vehicle_brand);
    int SetSpeed(int max_speed);
    int SetYear(int manufacture_year);

    // Гетери
    std::string GetBrand() const;
    int GetSpeed() const;
    int GetYear()  const;

    // VIRTUAL — дозволяє поліморфне перевизначення
    virtual int MakeSound();

    // OVERLOAD — два методи з однаковою назвою, різними параметрами
    int ShowInfo();
    int ShowInfo(std::string comment);

    // Overload MakeSound з параметром гучності (0-100)
    virtual int MakeSound(int volume);

protected:
    // PROTECTED — доступний нащадкам, але не зовні
    int Describe();
};