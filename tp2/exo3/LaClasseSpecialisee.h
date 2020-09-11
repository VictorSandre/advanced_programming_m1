//
// Created by vs on 09/09/2020.
//

#ifndef EXO2_LACLASSESPECIALISEE_H
#define EXO2_LACLASSESPECIALISEE_H

#include "LaClasse.h"

class LaClasseSpecialisee : public LaClasse {
public:
    LaClasseSpecialisee();

    LaClasseSpecialisee(const LaClasse &lc);

    LaClasseSpecialisee(int i);

    LaClasseSpecialisee(LaClasse &&other);

private:
};

LaClasseSpecialisee::LaClasseSpecialisee() {
    std::cout << "LaClasseSpecialisee::LaClasseSpecialisee" << std::endl;
}

LaClasseSpecialisee::LaClasseSpecialisee(const LaClasse &lc) : LaClasse(lc) {
    std::cout << "LaClasseSpecialisee::LaClasseSpecialisee(const LaClasse &lc)" << std::endl;
}

LaClasseSpecialisee::LaClasseSpecialisee(int i) : LaClasse(i) {
    std::cout << "LaClasseSpecialisee::LaClasseSpecialisee(int i)" << std::endl;
}

LaClasseSpecialisee::LaClasseSpecialisee(LaClasse &&other) : LaClasse(other) {
    std::cout << "LaClasseSpecialisee::LaClasseSpecialisee(LaClasse &&other)" << std::endl;
}

#endif //EXO2_LACLASSESPECIALISEE_H
