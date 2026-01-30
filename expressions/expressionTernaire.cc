#include "expressionTernaire.hh"

ExpressionTernaire::ExpressionTernaire(ConditionPtr condition, ExpressionPtr exp1, ExpressionPtr exp2):
    _condition(condition), _exp1(exp1), _exp2(exp2){
}

double ExpressionTernaire::calculer(const Contexte& contexte) const {
    
    bool resultatCondition = _condition->calculer(contexte);
    if (resultatCondition) return _exp1->calculer(contexte);
    else return _exp2->calculer(contexte);
}
