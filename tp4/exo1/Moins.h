//
// Created by user on 27/11/2020.
//

#ifndef EXO1_MOINS_H
#define EXO1_MOINS_H

#include "ExpressionBinaire.h"

class Moins : public ExpressionBinaire {
public:
    Moins(const Expression&, const Expression&);

    Moins(const Moins&);

    int eval() const override;

    Expression *clone() const override;

    ~Moins() override = default;
};

Moins::Moins(const Expression & lExpr, const Expression & rExpr) : ExpressionBinaire(lExpr, rExpr) {
}

Moins::Moins(const Moins & moins) {
    _rexpr = moins._rexpr->clone();
    _lexpr = moins._rexpr->clone();
}

Expression *Moins::clone() const {
    return new Moins(*this);
}

int Moins::eval() const {
    return _lexpr->eval() - _rexpr->eval();
}

#endif //EXO1_MOINS_H
