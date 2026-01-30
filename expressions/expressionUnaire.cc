#include "expressionUnaire.hh"

double ExpressionUnaire::calculer(const Contexte & contexte) const {
    double val = _exp->calculer(contexte);
    if (_op == OperateurUnaire::neg) {
        return -val;
    }
    return val;
}
