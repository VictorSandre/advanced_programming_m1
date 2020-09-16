#include <iostream>
#include "Expression.h"
#include "Constante.h"
#include "Plus.h"
#include "Mult.h"

int main() {
    const Expression & constante = Constante(2);
    std::cout << constante.eval() << std::endl;

    const Expression & constanteNeg = Constante(-2);
    std::cout << constanteNeg.eval() << std::endl;

    int val = 3;
    const Expression & constanteFromVal = Constante(val);
    std::cout << constanteFromVal.eval() << std::endl;

    const Expression & mult = Mult(Constante(2), Constante(3));
    std::cout << mult.eval() << std::endl;// 6

    const Expression & plus = Plus(Constante(2), Constante(3));
    std::cout << plus.eval() << std::endl;//5

    int a=5;
    const Expression & e = Mult(Plus( Constante(a), Constante(-2)),
                                Plus( Constante(1),Constante(3)) );
    std::cout << e.eval() << std::endl;
    return 0;
}
