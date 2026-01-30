#include "driver.hh"
#include "jardinHandler.hh"
#include "jardinRendering.hh"
#include <iostream>
#include <cmath>

#define ECHELLE 40.0

Driver::Driver(JardinHandler * jardin) : _jardin(jardin) {}
Driver::~Driver() {}

const Contexte & Driver::getContexte() const { return _contexte; }
Contexte & Driver::getContexteModifiable() { return _contexte; }
JardinRendering * Driver::getJardin() { return _jardin->getJardin(); }

void Driver::executer(const Bloc * bloc) {
    if (bloc != nullptr) ((Bloc*)bloc)->executer(_contexte, *this);
}

void Driver::definirFonction(std::string nom, Bloc * instructions) {
    _fonctions[nom] = instructions;
}

Bloc* Driver::recupererFonction(std::string nom) {
    if (_fonctions.find(nom) != _fonctions.end()) {
        return _fonctions[nom];
    }
    return nullptr;
}

// Implémentation simple pour ajouter les tortues manquantes
void Driver::initTortues(int nb) {
    int current = getJardin()->nombreTortues();
    // On assume qu'il y a au moins 1 tortue par défaut.
    // On ajoute celles qui manquent.
    for (int i = current; i < nb; ++i) {
        getJardin()->nouvelleTortue();
    }
}

// IMPLÉMENTATION DE BLOC::EXECUTER
void Bloc::executer(Contexte & ctx, Driver & driver) const {
    for (auto & instr : _instructions) {
        instr->executer(ctx, driver);
    }
}

// IMPLÉMENTATION DE APPELFONCTION::EXECUTER
void AppelFonction::executer(Contexte & ctx, Driver & driver) const {
    Bloc* code = driver.recupererFonction(_nom);
    if (!code) {
        std::cerr << "Erreur: Fonction inconnue '" << _nom << "'" << std::endl;
        return;
    }
    // Passage de paramètres simplifié (scope global)
    Contexte& c = driver.getContexteModifiable();
    for(size_t i=0; i < _args.size(); ++i) {
        double val = _args[i]->calculer(ctx);
        c["$" + std::to_string(i+1)] = val;
    }
    code->executer(ctx, driver);
}

void Driver::bouger(TypeMouvement type, double valeur) {
    int id = _contexte.tortueCourante;
    if (id >= getJardin()->nombreTortues()) return;

    float angleDeg = getJardin()->orientation(id);
    float angleRad = angleDeg * M_PI / 180.0;
    PointF pos = getJardin()->position(id);
    float curX = pos.x;
    float curY = pos.y;

    float dist = (float)(valeur * ECHELLE);
    float dX = 0; float dY = 0;

    switch(type) {
    case TypeMouvement::AVANCE:
        dX = dist * cos(angleRad); dY = dist * sin(angleRad); break;
    case TypeMouvement::RECULE:
        dX = -dist * cos(angleRad); dY = -dist * sin(angleRad); break;
    case TypeMouvement::TOURNE:
        getJardin()->changeOrientation(id, angleDeg + (float)valeur); return;
    case TypeMouvement::SAUTE:
        dX = dist * cos(angleRad); dY = dist * sin(angleRad); break;
    }
    getJardin()->changePosition(id, curX + dX, curY + dY);
}

bool Driver::verifierCapteur(TypeCapteur type, Direction, int id) {
    PointF pos = getJardin()->position(id);
    int targetX = (int)(pos.x / ECHELLE);
    int targetY = (int)(pos.y / ECHELLE);

    if (type == TypeCapteur::MUR) return getJardin()->estMur(targetX, targetY);
    if (type == TypeCapteur::VIDE) return getJardin()->estVide(targetX, targetY);
    return false;
}

void Driver::nouveauJardin(std::string nomJardin){
    getJardin()->construction(nomJardin);
}

void Driver::changerCouleur(double r, double g, double b) {
    int tortueCourante = _contexte.tortueCourante;
    getJardin()->changerCouleur((int)r, (int)g, (int)b);
    getJardin()->changeCouleur(tortueCourante, (int)r, (int)g, (int)b);
}

void driver_bouger_wrapper(Driver& d, TypeMouvement t, double v) {
    d.bouger(t, v);
}
void driver_couleur_wrapper(Driver& d, double r, double g, double b) {
    d.changerCouleur(r, g, b);
}
