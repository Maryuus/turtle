#include "expressionTernaire.hh"
#include <iostream>

ExpressionTernaire::ExpressionTernaire(ConditionPtr condition, ExpressionPtr exp1, ExpressionPtr exp2):
_condition(condition), _exp1(exp1), _exp2(exp2){
}

double ExpressionTernaire::calculer(const Contexte& contexte) const {
    // PATCH : L'expression ternaire n'est pas utilisée dans la grammaire du projet.
    // Comme elle ne peut plus appeler _condition->calculer() sans le Driver,
    // on retourne simplement 0 pour éviter l'erreur de compilation.

    std::cerr << "Attention : Tentative d'utilisation d'ExpressionTernaire (non supporté)" << std::endl;
    return 0.0;
}
