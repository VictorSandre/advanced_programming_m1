//
// Created by victor SANDRE.
//

#ifndef EXO1_EXPRESSION_H
#define EXO1_EXPRESSION_H

class Expression {
public:
    virtual int eval() const = 0;

    virtual Expression* clone() const = 0;

    virtual ~Expression() = default;
};

#endif //EXO1_EXPRESSION_H
