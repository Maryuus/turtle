#include "contexte.hh"

Contexte::Contexte() : tortueCourante(0) {
}

double & Contexte::get(const std::string & nom) {
    return variables[nom];
}

const double & Contexte::get(const std::string & nom) const {
    if (variables.find(nom) == variables.end()) {
        static double zero = 0.0;
        return zero;
    }
    return variables.at(nom);
}

// Implémentation de l'opérateur []
double & Contexte::operator[](const std::string & nom) {
    return variables[nom];
}
