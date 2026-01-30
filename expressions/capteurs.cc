#include "capteurs.hh"
#include "driver.hh"

ConditionCapteur::ConditionCapteur(TypeCapteur type, Direction direction, ExpressionPtr tortue)
    : m_type(type), m_direction(direction), m_tortue(tortue)
{}

bool ConditionCapteur::calculer(const Contexte & ctx, Driver& driver) const {
    // Si une tortue est spécifiée (@2), on calcule son ID
    int id = ctx.tortueCourante;
    if (m_tortue) {
        id = (int)m_tortue->calculer(ctx);
    }

    return driver.verifierCapteur(m_type, m_direction, id);
}
