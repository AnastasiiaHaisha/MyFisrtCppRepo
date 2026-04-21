#include "vehicles.h"

// =============================================================
//  Vehicle
// =============================================================
Vehicle::Vehicle(const std::string& b, int y, double ms)
    : brand(b), year(y), maxSpeed(ms) {}

void Vehicle::ShowInfo() const
{
    std::cout << "[Vehicle] " << brand
              << " (" << year << "), max speed: "
              << maxSpeed << " km/h\n";
}

void Vehicle::ShowInfo(const std::string& prefix) const
{
    std::cout << prefix << brand
              << " (" << year << "), max speed: "
              << maxSpeed << " km/h\n";
}

void Vehicle::Move() const
{
    std::cout << brand << " is moving (base behavior).\n";
}

void Vehicle::FuelType() const
{
    std::cout << "Fuel type: unknown.\n";
}


// =============================================================
//  MotorVehicle
// =============================================================
MotorVehicle::MotorVehicle(const std::string& b, int y, double ms,
                            double ev, int hp)
    : Vehicle(b, y, ms), engineVolume(ev), horsepower(hp) {}

void MotorVehicle::Move() const
{
    std::cout << brand << " is moving on a combustion engine ("
              << horsepower << " hp).\n";
}

void MotorVehicle::FuelType() const
{
    std::cout << brand << ": fuel - gasoline/diesel, engine volume "
              << engineVolume << " L.\n";
}

void MotorVehicle::RevEngine() const
{
    std::cout << brand << ": VROOM! (" << engineVolume << " L)\n";
}


// =============================================================
//  ElectricVehicle
// =============================================================
ElectricVehicle::ElectricVehicle(const std::string& b, int y, double ms,
                                  double bc, int cl)
    : Vehicle(b, y, ms), batteryCapacity(bc), chargeLevelPct(cl) {}

void ElectricVehicle::Move() const
{
    std::cout << brand << " is moving silently on electricity ("
              << chargeLevelPct << "% charge).\n";
}

void ElectricVehicle::FuelType() const
{
    std::cout << brand << ": fuel - electricity, battery "
              << batteryCapacity << " kWh.\n";
}

void ElectricVehicle::Charge() const
{
    std::cout << brand << ": connecting to charging station...\n";
}


// =============================================================
//  Car
// =============================================================
Car::Car(const std::string& b, int y, double ms,
         double ev, int hp, int d)
    : Vehicle(b, y, ms), MotorVehicle(b, y, ms, ev, hp), doors(d) {}

void Car::Move() const
{
    std::cout << brand << " (car, " << doors
              << " doors) is driving down the road.\n";
}

void Car::Honk() const
{
    std::cout << brand << ": Beep!\n";
}

void Car::Honk(int times) const
{
    std::cout << brand << ": ";
    for (int i = 0; i < times; ++i) std::cout << "Beep! ";
    std::cout << "\n";
}


// =============================================================
//  Truck
// =============================================================
Truck::Truck(const std::string& b, int y, double ms,
             double ev, int hp, double cc)
    : Vehicle(b, y, ms), MotorVehicle(b, y, ms, ev, hp), cargoCapacity(cc) {}

void Truck::Move() const
{
    std::cout << brand << " (truck, cargo up to "
              << cargoCapacity << " t) is moving slowly.\n";
}

void Truck::LoadCargo(double tons) const
{
    if (tons <= cargoCapacity)
        std::cout << brand << ": loaded " << tons << " t.\n";
    else
        std::cout << brand << ": overload! Limit "
                  << cargoCapacity << " t.\n";
}


// =============================================================
//  ElectricCar
// =============================================================
ElectricCar::ElectricCar(const std::string& b, int y, double ms,
                          double bc, int cl, int d)
    : Vehicle(b, y, ms),
      ElectricVehicle(b, y, ms, bc, cl),
      Car(b, y, ms, 0.0, 0, d) {}

void ElectricCar::Move() const
{
    std::cout << brand << " (electric car) is flying silently!\n";
}

void ElectricCar::FuelType() const
{
    ElectricVehicle::FuelType();
}

void ElectricCar::ShowInfo() const
{
    ElectricVehicle::ShowInfo("[ElectricCar] ");
}