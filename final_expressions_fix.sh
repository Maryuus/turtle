#!/bin/bash

echo "=== NETTOYAGE DES EXPRESSIONS (MATHS UNIQUEMENT) ==="

# -----------------------------------------------------------------------------
# 1. EXPRESSION BINAIRE (Uniquement +, -, *, /)
# -----------------------------------------------------------------------------
cat << 'EOF' > expressions/expressionBinaire.cc
#include "expressionBinaire.hh"
#include <cmath>

// Note: Le constructeur est déjà défini inline dans le .hh ou doit l'être ici.
// Pour éviter la redéfinition, on ne met QUE la méthode calculer ici.

double ExpressionBinaire::calculer(const Contexte & contexte) const {
    double gauche = _gauche->calculer(contexte);
    double droite = _droite->calculer(contexte);

    switch(_op) {
        case OperateurBinaire::plus: return gauche + droite;
        case OperateurBinaire::moins: return gauche - droite;
        case OperateurBinaire::multiplie: return gauche * droite;
        case OperateurBinaire::divise:
            if (droite != 0) return gauche / droite;
            return 0; // Sécurité division par zéro
    }
    return 0;
}
EOF

# -----------------------------------------------------------------------------
# 2. EXPRESSION UNAIRE (Uniquement le MOINS unaire)
# -----------------------------------------------------------------------------
cat << 'EOF' > expressions/expressionUnaire.cc
#include "expressionUnaire.hh"

double ExpressionUnaire::calculer(const Contexte & contexte) const {
    double val = _exp->calculer(contexte);
    if (_op == OperateurUnaire::neg) {
        return -val;
    }
    return val;
}
EOF

# -----------------------------------------------------------------------------
# 3. TEST BINAIRE (Comparaisons <, >, ==)
# -----------------------------------------------------------------------------
cat << 'EOF' > expressions/testBinaire.cc
#include "testBinaire.hh"

bool TestBinaire::calculer(const Contexte & ctx, Driver &) const {
    double g = _gauche->calculer(ctx);
    double d = _droite->calculer(ctx);

    switch(_op) {
        case OperateurBool::egal: return g == d;
        case OperateurBool::different: return g != d;
        case OperateurBool::pluspetit: return g < d;
        case OperateurBool::plusgrand: return g > d;
    }
    return false;
}
EOF

# -----------------------------------------------------------------------------
# 4. CONDITION BINAIRE (Logique ET, OU)
# -----------------------------------------------------------------------------
cat << 'EOF' > expressions/conditionBinaire.cc
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
EOF

# -----------------------------------------------------------------------------
# 5. RECOMPILATION
# -----------------------------------------------------------------------------
echo "=== RECOMPILATION ==="
# On supprime les objets .o pour forcer la recompilation propre
rm -f expressions/expressionBinaire.o expressions/expressionUnaire.o expressions/testBinaire.o expressions/conditionBinaire.o
rm -f main.o tortue
make

echo "=== TEST EXEMPLE 1 ==="
./tortue exemples/exemple1.txt

echo "=== TEST CARRE ROUGE ==="
./tortue test_carre.txt
