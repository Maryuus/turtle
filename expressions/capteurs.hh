#ifndef CAPTEURS_HH
#define CAPTEURS_HH

#include "condition.hh"
#include "types.hh"
#include "expression.hh"
#include <memory>

class ConditionCapteur : public Condition {
public:
    // Constructeur étendu : accepte une expression "tortue" optionnelle
    ConditionCapteur(TypeCapteur type, Direction direction, ExpressionPtr tortue = nullptr);

    bool calculer(const Contexte & ctx, Driver& driver) const override;

private:
    TypeCapteur m_type;
    Direction m_direction;
    ExpressionPtr m_tortue; // Pointeur nul si c'est la tortue courante
};

#endif
