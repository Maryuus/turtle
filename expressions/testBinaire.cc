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
