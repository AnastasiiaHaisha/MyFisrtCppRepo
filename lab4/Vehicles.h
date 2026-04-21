#pragma once
#include <iostream>
#include <string>

// =============================================================
//  Клас 1 — Vehicle  (базовий)
// =============================================================
class Vehicle
{
protected:
    std::string brand;
    int         year;
    double      maxSpeed;   // км/год

public:
    Vehicle(const std::string& b, int y, double ms);

    // Перевантаження ShowInfo
    void ShowInfo() const;
    void ShowInfo(const std::string& prefix) const;

    // Віртуальні методи — перевизначаються у нащадках
    virtual void Move()     const;
    virtual void FuelType() const;

    virtual ~Vehicle() = default;
};


// =============================================================
//  Клас 2 — MotorVehicle  (: Vehicle)
//  Транспорт з двигуном внутрішнього згоряння
// =============================================================
class MotorVehicle : virtual public Vehicle
{
protected:
    double engineVolume;   // літри
    int    horsepower;

public:
    MotorVehicle(const std::string& b, int y, double ms,
                 double ev, int hp);

    void Move()     const override;
    void FuelType() const override;
    void RevEngine() const;            // власний метод
};


// =============================================================
//  Клас 3 — ElectricVehicle  (: Vehicle)
//  Електромобіль
// =============================================================
class ElectricVehicle : virtual public Vehicle
{
protected:
    double batteryCapacity; // кВт·год
    int    chargeLevelPct;  // %

public:
    ElectricVehicle(const std::string& b, int y, double ms,
                    double bc, int cl);

    void Move()     const override;
    void FuelType() const override;
    void Charge() const;               // власний метод
};


// =============================================================
//  Клас 4 — Car  (: MotorVehicle)
//  Легковий автомобіль
// =============================================================
class Car : public MotorVehicle
{
    int doors;

public:
    Car(const std::string& b, int y, double ms,
        double ev, int hp, int d);

    void Move() const override;

    // Перевантаження Honk()
    void Honk() const;
    void Honk(int times) const;
};


// =============================================================
//  Клас 5 — Truck  (: MotorVehicle)
//  Вантажівка
// =============================================================
class Truck : public MotorVehicle
{
    double cargoCapacity; // тонн

public:
    Truck(const std::string& b, int y, double ms,
          double ev, int hp, double cc);

    void Move() const override;
    void LoadCargo(double tons) const; // власний метод
};


// =============================================================
//  Клас 6 — ElectricCar  (: ElectricVehicle, Car)
//  Електричний легковик — множинне наслідування
// =============================================================
class ElectricCar : public ElectricVehicle, public Car
{
public:
    ElectricCar(const std::string& b, int y, double ms,
                double bc, int cl, int d);

    void Move()     const override;    // розв'язує неоднозначність
    void FuelType() const override;    // делегує до ElectricVehicle
    void ShowInfo() const;             // перевизначення з префіксом
};