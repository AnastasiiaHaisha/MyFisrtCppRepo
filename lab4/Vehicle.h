#pragma once

#include <iostream>
#include <string>

class Vehicle
{
    std::string brand; // приватні поля - доступні ТІЛЬКИ всередині класу
    int speed;
    int year;

public:
    Vehicle();
    virtual ~Vehicle() = default; // віртуальний деструктор - ОБОВ'ЯЗКОВИЙ при поліморфізмі

    int SetBrand(std::string vehicle_brand);
    int SetSpeed(int max_speed);
    int SetYear(int manufacture_year);

    std::string GetBrand() const;
    int GetSpeed() const;
    int GetYear()  const;

    virtual int MakeSound();  // можна перевизначити в нащадку
    virtual int MakeSound(int volume);  // перевантаження + віртуальна

    int ShowInfo();   // НЕ віртуальна - не можна перевизначити поліморфно
    int ShowInfo(std::string comment);  // перевантаження ShowInfo

protected:
    int Describe();  // доступна в нащадках, але не зовні

};

int run();