#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "ElectricCar.h"
#include "SportElectricCar.h"

int main()
{
    std::cout << "========== Vehicle ==========\n";
    // Базовий клас — демонструємо перевантаження ShowInfo
    Vehicle v;
    v.SetBrand("Generic");
    v.SetSpeed(100);
    v.SetYear(2005);
    v.ShowInfo();                        // варіант 1 — без коментаря
    v.ShowInfo("Base vehicle object");   // варіант 2 — з коментарем
    v.MakeSound();

    std::cout << "\n========== Car ==========\n";
    // Car перевизначає MakeSound
    Car car;
    car.SetBrand("Toyota");
    car.SetSpeed(190);
    car.SetDoors(4);
    car.ShowInfo("Regular car");
    car.MakeSound();

    std::cout << "\n========== Motorcycle ==========\n";
    // Motorcycle — другий прямий нащадок Vehicle, своя реалізація MakeSound
    Motorcycle moto;
    moto.SetBrand("Honda");
    moto.SetSpeed(230);
    moto.SetType("Sport");
    moto.ShowInfo();
    moto.MakeSound();

    std::cout << "\n========== ElectricCar ==========\n";
    // ElectricCar успадковує Car, додає battery та range
    ElectricCar ev(75, 500);
    ev.SetBrand("Tesla");
    ev.SetYear(2022);
    ev.ShowInfo();

    std::cout << "\n========== SportElectricCar ==========\n";
    // Найглибший клас ієрархії — Vehicle -> Car -> ElectricCar -> SportElectricCar
    SportElectricCar* sev = new SportElectricCar(
        "Rimac",  // марка
        412,      // макс. швидкість км/год
        2023,     // рік
        120,      // батарея кВт·год
        550,      // запас ходу км
        "Red",    // колір
        1.97f     // розгін 0-100
    );

    // Поліморфний виклик через вказівник на базовий клас
    std::cout << "\n--- Polymorphism demo (base pointer -> derived sound) ---\n";
    Vehicle* vehicles[3];
    vehicles[0] = new Car();
    vehicles[1] = new Motorcycle();
    vehicles[2] = new ElectricCar(60, 400);

    for (int i = 0; i < 3; i++)
    {
        vehicles[i]->MakeSound(); // кожен клас викличе свій MakeSound
    }

    // Звільняємо пам'ять
    delete sev;
    for (int i = 0; i < 3; i++) delete vehicles[i];

    return 0;
}