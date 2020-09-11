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
    LaClasse c1;//instanciation
    std::cout<< "etape suivante " << std::endl;
    LaClasse c2=LaClasse();//operateur d'affectation
    std::cout<< "etape suivante " << std::endl;
    LaClasse cc1(c1);//constructeur par copie
    std::cout<< "etape suivante " << std::endl;
    LaClasse cc2=c1;
    std::cout<< "etape suivante " << std::endl;
    LaClasse cc3=LaClasse(c1);
    std::cout<< "etape suivante " << std::endl;
    LaClasse cv1(5);
    std::cout<< "etape suivante " << std::endl;
    LaClasse cv2=5;
    std::cout<< "etape suivante " << std::endl;
    LaClasse cv3=LaClasse(5);
    std::cout<< "etape suivante " << std::endl;
    LaClasse cv4=(LaClasse)5;
    std::cout<< "etape suivante " << std::endl;
    std::cout << std::endl;
    c1=cc1;
    std::cout<< "etape suivante " << std::endl;
    std::cout << std::endl;
    c2=8;
    std::cout<< "etape suivante " << std::endl;
    std::cout << std::endl;
    std::cout<< "etape suivante " << std::endl;
    if(cv1)
    {
        cv1=F(10);
        cv1=F(c1);
        cv1=c1.F(c2);
    }

    std::cout << "Tableaux \n";
    LaClasse tab[3];
    LaClasse *pc=new LaClasse(tab[0]);
    delete pc;
    std::cout << "Avant de sortir ... \n";
    return 0;
}