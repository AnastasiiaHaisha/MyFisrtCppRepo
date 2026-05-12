#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "ElectricCar.h"
#include "SportElectricCar.h"

#include <memory>  // для unique_ptr

Vehicle::Vehicle()
{
    brand = "Unknown";
    speed = 0;
    year  = 2000;
}

int Vehicle::SetBrand(const std::string& vehicle_brand)  // const& — без копіювання
{
    brand = vehicle_brand;
    return 1;
}

int Vehicle::SetSpeed(int max_speed)
{
    speed = max_speed;
    return 1;
}

int Vehicle::SetYear(int manufacture_year)
{
    year = manufacture_year;
    return 1;
}

std::string Vehicle::GetBrand() const { return brand; }
int         Vehicle::GetSpeed() const { return speed; }
int         Vehicle::GetYear()  const { return year;  }

int Vehicle::Describe()
{
    std::cout << "Brand: " << brand
              << " | Speed: " << speed
              << " | Year: " << year << "\n";
    return 1;
}

int Vehicle::ShowInfo()
{
    Describe();
    return 1;
}

int Vehicle::ShowInfo(const std::string& comment)  // const& — без копіювання
{
    Describe();
    std::cout << "   Note: " << comment << "\n";
    return 1;
}

int Vehicle::MakeSound()
{
    std::cout << "[Vehicle] Vrrrr...\n";
    return 1;
}

int Vehicle::MakeSound(int volume)
{
    if (volume <= 0)
        std::cout << "[Vehicle] (silence)\n";
    else if (volume < 50)
        std::cout << "[Vehicle] vrr... (volume: " << volume << "%)\n";
    else
        std::cout << "[Vehicle] VRRRR! (volume: " << volume << "%)\n";
    return 1;
}

int run()
{
    std::cout << "=== OVERLOAD DEMO ===\n";

    Vehicle v;
    v.SetBrand("GenericBrand");
    v.SetSpeed(120);
    v.SetYear(2005);

    v.ShowInfo();
    v.ShowInfo("Base vehicle");

    std::cout << "\n=== OVERLOAD DEMO (Car) ===\n";

    Car car;
    car.SetBrand("Toyota");
    car.SetDoors(4);

    car.MakeSound();
    car.MakeSound(30);
    car.MakeSound(90);

    car.ShowInfo();
    car.ShowInfo("Nice sedan");
    car.ShowInfo(true);

    std::cout << "\n=== POLYMORPHISM DEMO ===\n";

    // unique_ptr замість сирих вказівників — пам'ять звільняється автоматично
    std::unique_ptr<Vehicle> vehicles[3];
    vehicles[0] = std::make_unique<Car>();
    vehicles[1] = std::make_unique<Motorcycle>();
    vehicles[2] = std::make_unique<ElectricCar>(60, 400);

    for (int i = 0; i < 3; i++)
        vehicles[i]->MakeSound();  // викличе Car::, Motorcycle::, ElectricCar:: — завдяки virtual

    std::cout << "\n=== POLYMORPHIC MakeSound(int) DEMO ===\n";

    std::unique_ptr<Vehicle> ptr = std::make_unique<Car>();
    ptr->MakeSound(80);  // Car::MakeSound(int) — завдяки virtual
    // delete не потрібен

    std::cout << "\n=== SportElectricCar DEMO ===\n";

    auto sec = std::make_unique<SportElectricCar>(
        "Tesla", 320, 2024,
        100, 600,
        "Red", 2.9f
    );
    // delete не потрібен

    return 0;
}