//
// Created by victor SANDRE.
//

#ifndef EXO1_MULT_H
#define EXO1_MULT_H

#include "Expression.h"

class Mult : public Expression {
public:
    Mult(const Expression& rExpr, const Expression& lExpr);

    Mult(const Mult& mult);

    int eval() const override;

    Expression *clone() const override;

    ~Mult() override;
};

Mult::Mult(const Expression &rExpr, const Expression &lExpr) {
    _lexpr = lExpr.clone();
    _rexpr = rExpr.clone();
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

Mult::~Mult() {
    if (_lexpr != nullptr)
        delete _lexpr;
    if (_rexpr != nullptr)
        delete _rexpr;
}


#endif //EXO1_MULT_H
