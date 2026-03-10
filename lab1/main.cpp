#include <iostream>
#include <stdio.h>
#include "price.h"

int main() {    
    FILE* my_file;
    fopen_s(&my_file, "input.txt", "r");
    processFile(my_file);
    return 0;
}

