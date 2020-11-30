#include <iostream>
#include "SequenceCirculaire.h"

int main() {
    std::cout<< "Tp SequenceCirculaire Partie2 : " << std::endl;

    SequenceCirculaire<double> cercle(10, 5.5);
    std::cout << cercle << std::endl;

    for(int i = 0 ; i < 10 ; ++i)
        cercle[i] = i;
    std::cout << cercle << std::endl;

    Circulateur<double> circ(5,cercle);
    Circulateur<double> circEnd(4,cercle);

    for (;circ != circEnd ; ++circ)
        std::cout << *circ << std::endl;
    std::cout << cercle << std::endl;

    circ = cercle.makeCirculateur(0);
    for (int i = 0; i < 20; ++i) {
        *circ = i+0.2;
        ++circ;
    }

    std::cout << cercle << std::endl;
    std::cout << "test égalité: " << (circ == circ) ;
    return 0;
}
