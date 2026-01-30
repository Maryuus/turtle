#ifndef CONDITION_HH
#define CONDITION_HH

#include <memory>
#include "contexte.hh"

class Driver;

class Condition {
public:
    virtual ~Condition() = default;

    // Méthode principale appelée par le Driver
    virtual bool calculer(const Contexte & ctx, Driver& driver) const {
        return false;
    }
};

using ConditionPtr = std::shared_ptr<Condition>;

// Ajout indispensable pour gérer "pas de mur", "pas vide", etc.
class ConditionNot : public Condition {
public:
    ConditionNot(ConditionPtr condition) : _condition(condition) {}

    bool calculer(const Contexte & ctx, Driver& driver) const override {
        return !_condition->calculer(ctx, driver);
    }

private:
    ConditionPtr _condition;
};

#endif
