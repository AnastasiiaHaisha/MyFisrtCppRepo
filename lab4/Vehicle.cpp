#include "Vehicle.h"

// Конструктор за замовчуванням — ініціалізує поля стандартними значеннями
Vehicle::Vehicle()
{
    brand = "Unknown";
    speed = 0;
    year  = 2000;
}

// --- Сетери ---

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

// --- Гетери ---

std::string Vehicle::GetBrand() const { return brand; }
int         Vehicle::GetSpeed() const { return speed; }
int         Vehicle::GetYear()  const { return year;  }

// Базова реалізація звуку — підкласи перевизначають цей метод
int Vehicle::MakeSound()
{
    std::cout << "[Vehicle] Vrrrr...\n";
    return 1;
}

// Перевантаження ShowInfo — варіант 1: тільки основні дані
int Vehicle::ShowInfo()
{
    Describe();
    return 1;
}

// Перевантаження ShowInfo — варіант 2: дані + додатковий коментар
int Vehicle::ShowInfo(std::string comment)
{
    Describe();
    std::cout << "   Note: " << comment << "\n";
    return 1;
}

// Захищений метод — виводить базову інформацію про транспортний засіб
int Vehicle::Describe()
{
    std::cout << "Brand: " << brand
              << " | Max speed: " << speed << " km/h"
              << " | Year: " << year << "\n";
    return 1;
}