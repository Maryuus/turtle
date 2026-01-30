#pragma once

#include <memory> // <--- C'est cette ligne qui manquait souvent !
#include "contexte.hh"

class Driver; // Forward declaration pour éviter les inclusions cycliques

class Condition {
public:
    virtual ~Condition() = default;

    // Ancienne méthode (pour compatibilité)
    virtual bool calculer(const Contexte &) const { return false; }

    // Nouvelle méthode utilisée par le Driver
    virtual bool calculer(const Contexte & ctx, Driver& driver) const {
        return calculer(ctx);
    }
};

// C'est cette ligne qui définit ConditionPtr. Si elle manque, ExpressionTernaire plante.
using ConditionPtr = std::shared_ptr<Condition>;
