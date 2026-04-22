#pragma once
#include <iostream>
#include <string>

// Базовий клас для всіх транспортних засобів
class Vehicle
{
    // Приватні поля: доступні лише всередині класу
    std::string brand;   // марка транспортного засобу
    int speed;           // максимальна швидкість (км/год)
    int year;            // рік випуску

public:
    // Конструктор за замовчуванням
    Vehicle();

    // Сетери для полів
    int SetBrand(std::string vehicle_brand);
    int SetSpeed(int max_speed);
    int SetYear(int manufacture_year);

    // Гетери для полів (потрібні підкласам)
    std::string GetBrand() const;
    int GetSpeed() const;
    int GetYear() const;

    // Метод виводу звуку — буде перевизначений у підкласах
    virtual int MakeSound();

    // Перевантажений метод ShowInfo:
    // варіант 1 — без параметрів (виводить усі дані)
    int ShowInfo();
    // варіант 2 — з параметром (виводить дані + коментар)
    int ShowInfo(std::string comment);

protected:
    // Захищений метод — доступний лише у цьому та похідних класах
    int Describe();
};