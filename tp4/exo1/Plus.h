//
// Created by victor SANDRE.
//

#ifndef EXO1_PLUS_H
#define EXO1_PLUS_H

#include "ExpressionBinaire.h"

class Plus : public ExpressionBinaire {
public:
    Plus(const Expression &lExpr, const Expression &rExpr);

    Plus(const Plus& plus);

    int eval() const override;

    Expression *clone() const override;

    ~Plus() override = default;
};

Plus::Plus(const Expression& lExpr, const Expression& rExpr) : ExpressionBinaire(lExpr, rExpr){
}

Plus::Plus(const Plus &plus) {
    _lexpr = plus._lexpr->clone();
    _rexpr = plus._rexpr->clone();
}

int Plus::eval() const {
    return _lexpr->eval() + _rexpr->eval();
}

Expression *Plus::clone() const {
    return new Plus(*this);
}

#endif //EXO1_PLUS_H
