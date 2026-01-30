#include "conditionBinaire.hh"

bool ConditionBinaire::calculer(const Contexte & ctx, Driver & driver) const {
    bool g = _gauche->calculer(ctx, driver);

    // Optimisation lazy evaluation (court-circuit)
    if (_op == OperateurBinaireBool::ou && g) return true;
    if (_op == OperateurBinaireBool::et && !g) return false;

    bool d = _droite->calculer(ctx, driver);

    switch(_op) {
        case OperateurBinaireBool::et: return g && d;
        case OperateurBinaireBool::ou: return g || d;
    }
    return false;
}
