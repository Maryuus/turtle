#include "variable.hh"
#include "contexte.hh"

Variable::Variable(const std::string & nom) : _nom(nom) {
}

double Variable::calculer(const Contexte & contexte) const {
    // CORRECTION : On utilise get() qui est compatible avec "const"
    return contexte.get(_nom);
}
