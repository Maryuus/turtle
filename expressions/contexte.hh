#ifndef CONTEXTE_HH
#define CONTEXTE_HH

#include <map>
#include <string>

class Contexte {
public:
    Contexte();

    // Accès standard
    double & get(const std::string & nom);
    const double & get(const std::string & nom) const;

    // LE SAUVEUR : L'opérateur [] pour que driver.cc soit content
    double & operator[](const std::string & nom);

    // Notre ajout précédent
    int tortueCourante;

private:
    std::map<std::string, double> variables;
};

#endif
