#include "Vehicle.h"

// Конструктор за замовчуванням
Vehicle::Vehicle()
{
    brand = "Unknown";
    speed = 0;
    year  = 2000;
}

// Сетери
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

// Гетери
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

// Protected метод — внутрішній помічник для ShowInfo
int Vehicle::Describe()
{
    std::cout << "Brand: " << brand
              << " | Speed: " << speed
              << " | Year: " << year << "\n";
    return 1;
}

// Overload варіант 1: без параметра
int Vehicle::ShowInfo()
{
    Describe();
    return 1;
}

// Overload варіант 2: з параметром-коментарем
int Vehicle::ShowInfo(std::string comment)
{
    Describe();
    std::cout << "   Note: " << comment << "\n";
    return 1;
}

// Базова реалізація MakeSound (без параметра)
int Vehicle::MakeSound()
{
    std::cout << "[Vehicle] Vrrrr...\n";
    return 1;
}

// Overload MakeSound з гучністю (0-100)
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