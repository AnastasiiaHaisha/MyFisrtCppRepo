#pragma once

#include <iostream>
#include <string>

class Vehicle
{
    std::string brand;
    int speed;
    int year;

public:
    Vehicle();
    virtual ~Vehicle() = default;

    int SetBrand(std::string vehicle_brand);
    int SetSpeed(int max_speed);
    int SetYear(int manufacture_year);

    std::string GetBrand() const;
    int GetSpeed() const;
    int GetYear()  const;

    virtual int MakeSound();
    virtual int MakeSound(int volume);

    int ShowInfo();
    int ShowInfo(std::string comment);

protected:
    int Describe();
};