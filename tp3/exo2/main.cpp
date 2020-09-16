#include <iostream>
#include "Generator.h"

int main() {
    std::cout << "Test Foncteur" << std::endl;

    Generator generator(5);

    std::cout << generator() << std::endl
              << generator() << std::endl
              << generator() << std::endl
              << generator() << std::endl
              << generator() << std::endl
              << std::endl;

    return 0;
}
