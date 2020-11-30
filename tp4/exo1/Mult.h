//
// Created by victor SANDRE.
//

#ifndef EXO1_MULT_H
#define EXO1_MULT_H

#include "ExpressionBinaire.h"

class Mult : public ExpressionBinaire {
public:
    Mult(const Expression& rExpr, const Expression& lExpr);

    Mult(const Mult& mult);

    int eval() const override;

    Expression *clone() const override;

    ~Mult() override = default;
};

Mult::Mult(const Expression &rExpr, const Expression &lExpr) : ExpressionBinaire(lExpr, rExpr){
}

Mult::Mult(const Mult &mult) {
    _rexpr = mult._rexpr->clone();
    _lexpr = mult._lexpr->clone();
}

int Mult::eval() const {
    return _lexpr->eval() * _rexpr->eval();
}

Expression *Mult::clone() const {
    return new Mult(*this);
}



#endif //EXO1_MULT_H
