#ifndef TESTBINAIRE_HH
#define TESTBINAIRE_HH
#include "condition.hh"
#include "expression.hh"
#include "types.hh"

class TestBinaire : public Condition {
public:
    TestBinaire(ExpressionPtr g, ExpressionPtr d, OperateurBool op)
        : _gauche(g), _droite(d), _op(op) {}

    bool calculer(const Contexte & ctx, Driver &) const override;

private:
    ExpressionPtr _gauche;
    ExpressionPtr _droite;
    OperateurBool _op;
};
#endif
