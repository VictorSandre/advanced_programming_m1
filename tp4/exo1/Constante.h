//
// Created by victor SANDRE.
//

#ifndef EXO1_CONSTANTE_H
#define EXO1_CONSTANTE_H

#include "Expression.h"

class Constante : public Expression {
public:
    Constante(int value);

    Constante (const Constante & constante);

    int eval() const override;

    Expression *clone() const override;

    ~Constante() override;

private:
    int value;
};

Constante::Constante(int value) {
    this->value = value;
}

Constante::Constante(const Constante &constante) {
    value = constante.value;
}

int Constante::eval() const {
    return value;
}

Expression *Constante::clone() const {
    return new Constante(*this);
}

Constante::~Constante() {}

#endif //EXO1_CONSTANTE_H
