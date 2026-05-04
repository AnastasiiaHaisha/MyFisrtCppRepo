#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "ElectricCar.h"
#include "SportElectricCar.h"

int main()
{
    std::cout << "=== OVERLOAD DEMO ===\n";

    Vehicle v;
    v.SetBrand("GenericBrand");
    v.SetSpeed(120);
    v.SetYear(2005);

    v.ShowInfo();
    v.ShowInfo("Base vehicle object");

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

    Vehicle* vehicles[3];
    vehicles[0] = new Car();
    vehicles[1] = new Motorcycle();
    vehicles[2] = new ElectricCar(60, 400);

    for (int i = 0; i < 3; i++)
        vehicles[i]->MakeSound();

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