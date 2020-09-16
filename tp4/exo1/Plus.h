//
// Created by victor SANDRE.
//

#ifndef EXO1_PLUS_H
#define EXO1_PLUS_H

#include "Expression.h"

class Plus : public Expression {
public:
    Plus(const Expression &lExpr, const Expression &rExpr);

    Plus(const Plus& plus);

    int eval() const override;

    Expression *clone() const override;

    ~Plus() override;
};

Plus::Plus(const Expression& lExpr, const Expression& rExpr) {
    _lexpr = lExpr.clone();
    _rexpr = rExpr.clone();
}

int Plus::eval() const {
    return _lexpr->eval() + _rexpr->eval();
}

Expression *Plus::clone() const {
    return new Plus(*this);
}

Plus::Plus(const Plus &plus) {
    _lexpr = plus._lexpr->clone();
    _rexpr = plus._rexpr->clone();
}

Plus::~Plus() {
    if (_lexpr != nullptr)
        delete _lexpr;
    if (_rexpr != nullptr)
        delete _rexpr;
}

#endif //EXO1_PLUS_H
