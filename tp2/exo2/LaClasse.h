//
// Created by mc on 09/09/2020.
//

#ifndef EXO2_LACLASSE_H
#define EXO2_LACLASSE_H

#include <iostream>

class LaClasse
{
public :
    //Construction, conversion, affectation et destruction
    LaClasse();
    LaClasse(const LaClasse & lc);
    LaClasse(int i);
    LaClasse(LaClasse&& other) noexcept;

    operator bool() const;

    ~LaClasse();

    const LaClasse & operator=(const LaClasse & c);
    LaClasse& operator=(LaClasse&& other);

    LaClasse F(LaClasse); //Autre fonction membre

    friend std::ostream & operator << (std::ostream & os, const LaClasse & lc);
private :
    int l;
};

LaClasse F(LaClasse vv)
{
    std::cout << " in F \n";
    return 8;
}

LaClasse LaClasse::F(LaClasse v)
{
    std::cout << " in LaClasse::F \n";
    return ::F(v);
}

std::ostream & operator << (std::ostream & os, const LaClasse & lc)
{
    os << " in ostream << LaClasse "<< lc.l << std::endl;
    return os;
}

LaClasse::LaClasse() : l(0) {
    std::cout << "LaClasse::LaClasse()\n";
}

LaClasse::LaClasse(const LaClasse &lc) : l(lc.l) {
    std::cout << "LaClasse::LaClasse(const LaClasse & )\n";
}

LaClasse::LaClasse(int i) : l(i) {
    std::cout << "LaClasse::LaClasse(int)\n";
}

LaClasse::LaClasse(LaClasse &&other) noexcept {
    std::cout << "LaClasse(LaClasse &&other)" << std::endl;
    std::move(other);
    // Si on a pas d'opérateur d'assignation de déplacement il faut commenter la ligne du dessu et decommenter
    // celle du dessous
    l = other.l;
}

LaClasse::operator bool() const {
    std::cout << "LaClasse::operator bool() const\n";
    return true;
}

LaClasse::~LaClasse() {
    std::cout << "~LaClasse::LaClasse()\n";
}

LaClasse &LaClasse::operator=(LaClasse&& other) {
    std::cout<< " LaClasse &operator=(LaClasse&& other) " << std::endl;
    if (this != &other) {
        l = other.l;
    }
}

const LaClasse &LaClasse::operator=(const LaClasse &c) {
    l=c.l;
    std::cout << "LaClasse::operator=(const LaClasse &)\n";
    return *this;
}

#endif //EXO2_LACLASSE_H
