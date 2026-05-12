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

    int SetBrand(const std::string& vehicle_brand);  // const& — без зайвого копіювання
    int SetSpeed(int max_speed);
    int SetYear(int manufacture_year);

    std::string GetBrand() const;
    int GetSpeed() const;
    int GetYear()  const;

    virtual int MakeSound();
    virtual int MakeSound(int volume);

    virtual int ShowInfo();                          // virtual — щоб поліморфізм працював
    virtual int ShowInfo(const std::string& comment);// const& + virtual

protected:
    virtual int Describe();                          // virtual — нащадки можуть розширити
};

int run();