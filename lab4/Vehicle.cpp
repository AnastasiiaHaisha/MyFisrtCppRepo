#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "ElectricCar.h"
#include "SportElectricCar.h"

Vehicle::Vehicle()
{
    brand = "Unknown";  // значення за замовчуванням
    speed = 0;
    year  = 2000;
}

int Vehicle::SetBrand(std::string vehicle_brand)  
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

std::string Vehicle::GetBrand() const
{
    return brand;
}

int Vehicle::GetSpeed() const
{
    return speed;
}

int Vehicle::GetYear() const
{
    return year;
}

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

int Vehicle::ShowInfo(std::string comment)
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

int Vehicle::MakeSound(int volume)  // ПЕРЕВАНТАЖЕННЯ - та сама назва, інший параметр
{
    if (volume <= 0)
        std::cout << "[Vehicle] (silence)\n";
    else if (volume < 50)
        std::cout << "[Vehicle] vrr... (volume: " << volume << "%)\n";
    else
        std::cout << "[Vehicle] VRRRR! (volume: " << volume << "%)\n";
    return 1;
}

int run(){
    std::cout << "=== OVERLOAD DEMO ===\n";

    Vehicle v;
    v.SetBrand("GenericBrand");
    v.SetSpeed(120);
    v.SetYear(2005);

    v.ShowInfo();               // ShowInfo()
    v.ShowInfo("Base vehicle"); // ShowInfo(string) - інший метод, інша поведінка

    std::cout << "\n=== OVERLOAD DEMO (Car) ===\n";

    Car car;
    car.SetBrand("Toyota");
    car.SetDoors(4);

    car.MakeSound();    // Car::MakeSound()
    car.MakeSound(30);  // Car::MakeSound(int) - volume < 70, звичайний beep
    car.MakeSound(90);  // Car::MakeSound(int) - volume > 70, BEEP

    car.ShowInfo();
    car.ShowInfo("Nice sedan");
    car.ShowInfo(true);

    std::cout << "\n=== POLYMORPHISM DEMO ===\n";

    Vehicle* vehicles[3];
    vehicles[0] = new Car();         // вказівник Vehicle*, але об'єкт Car
    vehicles[1] = new Motorcycle();  // вказівник Vehicle*, але об'єкт Motorcycle
    vehicles[2] = new ElectricCar(60, 400);

    for (int i = 0; i < 3; i++)
        vehicles[i]->MakeSound();  // який MakeSound викличеться???

    std::cout << "\n=== POLYMORPHIC MakeSound(int) DEMO ===\n";

    Vehicle* ptr = new Car();
    ptr->MakeSound(80);
    delete ptr;

    std::cout << "\n=== SportElectricCar DEMO ===\n";

    SportElectricCar* sec = new SportElectricCar(
        "Tesla", 320, 2024,
        100, 600,
        "Red", 2.9f
    );

    delete sec;

    for (int i = 0; i < 3; i++)
        delete vehicles[i];

    return 0;
}