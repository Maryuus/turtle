#pragma once
#include "expression.hh"
#include "condition.hh"

class ExpressionTernaire : public Expression {
public:
    ExpressionTernaire(const ExpressionTernaire &) = default;
    ExpressionTernaire(ConditionPtr condition, ExpressionPtr exp1, ExpressionPtr exp2);
    ~ExpressionTernaire() = default;

    double calculer(const Contexte& contexte) const;

private:
    ConditionPtr _condition;
    ExpressionPtr _exp1;
    ExpressionPtr _exp2;
};
