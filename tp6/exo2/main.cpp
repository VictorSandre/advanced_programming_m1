#include <iostream>
#include "Array.h"

int main() {

    Array<int, 4> array;
    array.add(1);
    array.add(2);
    array.add(3);
    array.add(4);
    std::cout << "affichage du tableau avec le cout : " << array;

    Iterator<int> it = array.begin();
    Iterator<int> it2 = array.begin();
    Iterator<int> it3 = array.end();
    std::cout << "array.begin() != array.begin() :" << (it != it2) << std::endl;
    std::cout << "array.begin() != array.end() :" << (it != it3) << std::endl;

    std::cout << "affichage du tableau avec le custom iterator : [ ";
    for (it; it!=it3 ; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;

    //TODO demander comment faire un: Array<int,6>::Iterator it = array.begin();
    return 0;
}
