#ifndef DRIVER_HH
#define DRIVER_HH

#include <string>
#include <vector>
#include <map>
#include "contexte.hh"
#include "instructions.hh"
#include "types.hh"

// Forward declarations
class JardinHandler;
class JardinRendering;

class Driver {
public:
    Driver(JardinHandler* jardin);
    ~Driver();

    const Contexte& getContexte() const;
    Contexte& getContexteModifiable();
    JardinRendering* getJardin();

    void executer(const Bloc* bloc);
    void bouger(TypeMouvement type, double valeur);
    void changerCouleur(double r, double g, double b);

    bool verifierCapteur(TypeCapteur type, Direction dir, int id);

    // GESTION DES FONCTIONS
    void definirFonction(std::string nom, Bloc* instructions);
    Bloc* recupererFonction(std::string nom); // <-- Nouvelle méthode pour aider AppelFonction

    void nouveauJardin(std::string nom);

private:
    JardinHandler* _jardin;
    Contexte _contexte;

    // Stockage des fonctions définies par l'utilisateur
    std::map<std::string, Bloc*> _fonctions;
};

#endif
