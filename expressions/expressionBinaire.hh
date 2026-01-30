#ifndef EXPRESSIONBINAIRE_HH
#define EXPRESSIONBINAIRE_HH
#include "expression.hh"
#include "types.hh"

class ExpressionBinaire : public Expression {
public:
    ExpressionBinaire(ExpressionPtr g, ExpressionPtr d, OperateurBinaire op)
        : _gauche(g), _droite(d), _op(op) {}

    double calculer(const Contexte & ctx) const override; // Implémenté dans .cc

private:
    ExpressionPtr _gauche;
    ExpressionPtr _droite;
    OperateurBinaire _op;
};
#endif
