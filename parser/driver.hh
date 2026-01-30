#ifndef DRIVER_HH
#define DRIVER_HH

#include <string>
#include <vector>
#include <map>
#include "contexte.hh"
#include "instructions.hh"
#include "types.hh"

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

    // Directive pour le nombre de tortues
    void initTortues(int nb);

    bool verifierCapteur(TypeCapteur type, Direction dir, int id);
    void definirFonction(std::string nom, Bloc* instructions);
    Bloc* recupererFonction(std::string nom);
    void nouveauJardin(std::string nom);

private:
    JardinHandler* _jardin;
    Contexte _contexte;
    std::map<std::string, Bloc*> _fonctions;
};

#endif
