#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "ElectricCar.h"
#include "SportElectricCar.h"

int main()
{
    std::cout << "=== ДЕМОНСТРАЦІЯ OVERLOAD ===\n";

    Vehicle v;
    v.SetBrand("GenericBrand");
    v.SetSpeed(120);
    v.SetYear(2005);

    v.ShowInfo();                       // виклик версії без параметра
    v.ShowInfo("Base vehicle object");  // виклик версії з параметром

    std::cout << "\n=== ДЕМОНСТРАЦІЯ OVERLOAD (Car) ===\n";

    Car car;
    car.SetBrand("Toyota");
    car.SetDoors(4);

    car.MakeSound();        // override без параметра -> [Car] Beep-beep!
    car.MakeSound(30);      // override з параметром гучності -> [Car] Beep! (30%)
    car.MakeSound(90);      // override з гучністю > 70 -> [Car] Beep-BEEP! (90%)

    car.ShowInfo();                 // успадкований overload (без параметра)
    car.ShowInfo("Nice sedan");     // успадкований overload (string)
    car.ShowInfo(true);             // новий overload (bool) -> показує кількість дверей

    std::cout << "\n=== ДЕМОНСТРАЦІЯ POLYMORPHISM ===\n";

    Vehicle* vehicles[3];
    vehicles[0] = new Car();
    vehicles[1] = new Motorcycle();
    vehicles[2] = new ElectricCar(60, 400);

    for (int i = 0; i < 3; i++)
    {
        vehicles[i]->MakeSound(); // ПОЛІМОРФНИЙ ВИКЛИК
    }

    // Виведе:
    // [Car] Beep-beep! Doors: 4
    // [Motorcycle] Vroom-vroom! Type: Standard
    // [ElectricCar] *silent hum* ...

    std::cout << "\n=== ПОЛІМОРФНИЙ ВИКЛИК MakeSound(int) ===\n";

    Vehicle* ptr = new Car();
    ptr->MakeSound(80);    // викличе Car::MakeSound(80), бо virtual!
    delete ptr;

    std::cout << "\n=== ДЕМОНСТРАЦІЯ SportElectricCar ===\n";

    SportElectricCar* sev = new SportElectricCar(
        "Tesla", 320, 2024,
        100, 600,
        "Red", 2.9f
    );

    delete sev;

    // Звільнення пам'яті масиву
    for (int i = 0; i < 3; i++)
        delete vehicles[i];

    return 0;
}