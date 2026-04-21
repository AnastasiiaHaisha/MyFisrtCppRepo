#include "vehicles.h"

int main()
{
    // Your test code here, for example:
    Car car("Toyota", 2020, 180.0, 1.6, 120, 4);
    car.ShowInfo();
    car.Move();
    car.Honk(3);

    Truck truck("Volvo", 2018, 120.0, 8.0, 400, 20.0);
    truck.Move();
    truck.LoadCargo(15.0);

    ElectricCar tesla("Tesla", 2023, 250.0, 100.0, 80, 4);
    tesla.ShowInfo();
    tesla.Move();
    tesla.FuelType();

    return 0;
}