#include <iostream>
#include "Array.h"

int main() {

    Array<int, 4> array;
    array.add(1);
    array.add(2);
    array.add(3);
    array.add(4);
    std::cout << "affichage du tableau avec le cout : " << array;

    array.backInsertIterator() = 999;
    std::cout << "affichage du tableau avec le cout : " << array;

    return 0;
}
