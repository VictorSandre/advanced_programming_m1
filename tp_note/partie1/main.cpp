#include <iostream>
#include "SequenceCirculaire.h"

int main() {
    std::cout<< "Tp SequenceCirculaire Partie1 : " << std::endl;
    SequenceCirculaire<double> sc;

    std::cout<< "test constructeur par défault : " << sc << std::endl;

    // TODO abigous constructor if type = int what to do ?
    //SequenceCirculaire<int> scAmbigous(10, 5);
    SequenceCirculaire<double> sc1(10, 5.1);

    std::cout<< "test constructeur par valeur : " << sc1 << std::endl;

    SequenceCirculaire<double> sc2(sc1);
    std::cout<< "test constructeur par copie : " << sc2 << std::endl;

    SequenceCirculaire<double> sc3(std::move(sc2));
    std::cout<< "test constructeur par déplacement : " << sc2 << sc3 << std::endl;

    sc = sc3;
    std::cout<< "test opérateur affectation par copie : " << sc << sc3 << std::endl;

    sc = SequenceCirculaire<double>();

    sc.insertion(0, 0);
    sc.insertion(1, 1);
    sc.insertion(2, 2);
    sc.insertion(3, 3);
    sc.insertion(4, 4);
    sc.insertion(5, 5);
    sc.insertion(6, 6);
    sc.insertion(7, 7);
    sc.insertion(8, 8);
    sc.insertion(9, 9);
    sc.insertion(10, 10);
    sc.insertion(11, 11);
    sc.insertion(12, 12);
    sc.insertion(13, 13);
    sc.insertion(14, 14);
    sc.insertion(15, 15);
    sc.insertion(16, 16);
    sc.insertion(17, 17);
    sc.insertion(18, 18);
    sc.insertion(19, 19);
    std::cout << "test insersion éléments : " << sc << std::endl;
    std::cout <<"test d'erreur d'insersion" << std::endl;
    try {
        sc.insertion(25, 8.1);
    } catch (const std::exception& erreur) {
        std::cout <<"erreur:" << erreur.what() << std::endl;
    }

    std::cout <<"test d'opérateur [index positif] : " << sc[3] << ";" << sc[23] << std::endl;
    std::cout <<"test d'opérateur [index négatif] : " << sc[-1] << ";" << sc[-21] << std::endl;

    std::cout <<"test fonction de recherche : " << sc.recherche(6) << ";" << sc.recherche(674) << std::endl;



    return 0;
}
