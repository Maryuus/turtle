#ifndef CONDITIONBINAIRE_HH
#define CONDITIONBINAIRE_HH
#include "condition.hh"
#include "types.hh"

class ConditionBinaire : public Condition {
public:
    ConditionBinaire(ConditionPtr g, ConditionPtr d, OperateurBinaireBool op)
        : _gauche(g), _droite(d), _op(op) {}

    bool calculer(const Contexte & ctx, Driver & driver) const override;

private:
    ConditionPtr _gauche;
    ConditionPtr _droite;
    OperateurBinaireBool _op;
};
#endif
