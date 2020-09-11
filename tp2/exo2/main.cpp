#include <iostream>
#include "LaClasse.h"
/**
 * Pour compiler un fichier :  g++ LaClasse.cpp -o laClasse -std=c++17
 *
 * Pour supprimer l'optimisation: g++ LaClasse.cpp -o laClasse -std=c++17 -fno-elide-constructors
 *
 * Pour exectuter: ./laClasse
 */

int main()
{
    std::cout << "test du contruteur par déplacement" << std::endl;
    LaClasse lc = LaClasse(4); // Appel du constructeur par déplacement
    LaClasse lc2 = lc;
    return 0;
}