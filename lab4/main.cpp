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