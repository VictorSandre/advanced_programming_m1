#include <iostream>
#include "Array.h"

int main() {
    Array<int,2> array;
    std::cout << "array:" << array;

    array.add(1);
    std::cout << "array:" << array;

    array.add(2);
    std::cout << "array:" << array;

    array.add(3);
    std::cout << "array:" << array;

    Array<int, 2> array_cpy(array);
    std::cout << "array_cpy:" << array_cpy;

    array_cpy[0] = 5;
    std::cout << "array_cpy:" << array_cpy;
    std::cout << "array:" << array;
    std::cout << "array[0]:" << array[0] << std::endl;

    int toto[] = {1,2,9,4};
    Array<int,3> array_char(toto);
    std::cout << "array_char:" << array_char;

    Array<int,2> assignement_array;
    std::cout << "assignement_array:" << assignement_array;
    assignement_array = array_cpy;
    std::cout << "assignement_array:" << assignement_array;
    assignement_array[0] = 26;
    std::cout << "assignement_array:" << assignement_array;
    std::cout << "array_cpy:" << array_cpy;
    return 0;
}
