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
