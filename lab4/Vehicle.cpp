#include "Vehicle.h"

Vehicle::Vehicle()
{
    brand = "Unknown";
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