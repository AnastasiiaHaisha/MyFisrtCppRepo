#include "price.h"
#include <iostream>
#include <stdio.h>


void add(Price& a, Price& b) {
    a.gryvnia += b.gryvnia;
    a.kopiyky += b.kopiyky;
}

void multiply(Price& a, int n) {
    a.gryvnia *= n;
    a.kopiyky *= n;
}

void roundPrice(Price& a) {
    int remainder = a.kopiyky % 10;
    if (remainder < 5) {
        a.kopiyky -= remainder;
    } else {
        a.kopiyky += (10 - remainder);
        if (a.kopiyky >= 100) {
            a.gryvnia++;
            a.kopiyky -= 100;
        }
    }
}

void printPrice(Price& p) {
    std::cout << p.gryvnia << " грн " << p.kopiyky << " коп." << std::endl;
}

void processFile(FILE* file) {
    char name[50];
    int h;
    short k;
    int count;
    Price total = {0, 0};

    while (fscanf(file, "%49s %d %hd %d", name, &h, &k, &count) == 4) {
        
        Price price = {h, k};

        std::cout << "Продукт: " << name << std::endl;
        std::cout << "Ціна: " << h << " грн " << k << " копійок " << std::endl;
        std::cout << "Кількість: " << count << std::endl << std::endl;

        multiply(price, count);
        add(total, price);

        if (total.kopiyky >= 100) {
            total.gryvnia += total.kopiyky / 100;
            total.kopiyky %= 100;
        }
    }

    fclose(file);

    std::cout << "Загальна сума: ";
    printPrice(total);

    Price rounded = total;
    roundPrice(rounded);

    std::cout << "Сума після округлення: ";
    printPrice(rounded);
}