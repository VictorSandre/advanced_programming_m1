//
// Created by user on 27/11/2020.
//

#ifndef EXO1_EXPRESSIONBINAIRE_H
#define EXO1_EXPRESSIONBINAIRE_H

#include "Expression.h"

class ExpressionBinaire : public Expression {
public:
    ExpressionBinaire() = default;

    ExpressionBinaire(const Expression&, const Expression&);

    ~ExpressionBinaire() override;
protected:
    Expression* _lexpr;
    Expression* _rexpr;
};

ExpressionBinaire::ExpressionBinaire(const Expression & lExpr, const Expression & rExpr) :
_rexpr(rExpr.clone()), _lexpr(lExpr.clone()) {
}

ExpressionBinaire::~ExpressionBinaire() {
        delete _rexpr;
        delete _lexpr;
}


#endif //EXO1_EXPRESSIONBINAIRE_H
