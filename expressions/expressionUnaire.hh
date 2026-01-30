#ifndef EXPRESSIONUNAIRE_HH
#define EXPRESSIONUNAIRE_HH
#include "expression.hh"
#include "types.hh"

class ExpressionUnaire : public Expression {
public:
    ExpressionUnaire(ExpressionPtr exp, OperateurUnaire op)
        : _exp(exp), _op(op) {}

    double calculer(const Contexte & ctx) const override;

private:
    ExpressionPtr _exp;
    OperateurUnaire _op;
};
#endif
