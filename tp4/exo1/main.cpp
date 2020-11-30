#include <iostream>
#include "Expression.h"
#include "Constante.h"
#include "Plus.h"
#include "Mult.h"
#include "Moins.h"

int main() {
    const Expression & constante = Constante(2);
    std::cout << "const : " << constante.eval() << std::endl;

    const Expression & constanteNeg = Constante(-2);
    std::cout << "NegConst : " << constanteNeg.eval() << std::endl;

    int val = 3;
    const Expression & constanteFromVal = Constante(val);
    std::cout << "constFromVal : " <<constanteFromVal.eval() << std::endl;

    const Expression & mult = Mult(Constante(2), Constante(3));
    std::cout << "Mult : " << mult.eval() << std::endl;// 6

    const Expression & plus = Plus(Constante(2), Constante(3));
    std::cout << "Plus : " << plus.eval() << std::endl;//5

    int a=5;
    const Expression & e = Mult(Plus( Constante(a), Constante(-2)),
                                Plus( Constante(1),Constante(3)) );
    std::cout << "mult : " << e.eval() << std::endl;

    const ExpressionBinaire & moins = Moins(Constante(3), Constante(-2));
    std::cout<< "Moins : " << moins.eval() << std::endl;
     return 0;
}
