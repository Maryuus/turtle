#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include "expression.hh"
#include "contexte.hh"
#include "types.hh"
#include "condition.hh"  // <--- L'AJOUT INDISPENSABLE EST ICI !
#include <vector>
#include <memory>
#include <string>

class Driver;

class Instruction {
public:
    virtual ~Instruction() {}
    virtual void executer(Contexte & contexte, Driver & driver) const = 0;
};

using InstructionPtr = std::shared_ptr<Instruction>;

class Bloc : public Instruction {
public:
    void ajouter(InstructionPtr instr) {
        _instructions.push_back(instr);
    }
    void executer(Contexte & contexte, Driver & driver) const override;

private:
    std::vector<InstructionPtr> _instructions;
};

class CommandeMouvement : public Instruction {
public:
    CommandeMouvement(ExpressionPtr valeur, TypeMouvement type)
        : _valeur(valeur), _type(type) {}

    void executer(Contexte & ctx, Driver & driver) const override {
        double val = _valeur->calculer(ctx);
        bouger(driver, _type, val);
    }

private:
    void bouger(Driver& driver, TypeMouvement type, double val) const;
    ExpressionPtr _valeur;
    TypeMouvement _type;
};

class CommandeCouleur : public Instruction {
public:
    CommandeCouleur(double r, double g, double b) : _r(r), _g(g), _b(b) {}

    void executer(Contexte &, Driver & driver) const override {
        changerCouleur(driver, _r, _g, _b);
    }
private:
    void changerCouleur(Driver& driver, double r, double g, double b) const;
    double _r, _g, _b;
};

class CommandeSelectionTortue : public Instruction {
public:
    CommandeSelectionTortue(ExpressionPtr id) : _id(id) {}
    void executer(Contexte & ctx, Driver &) const override {
        ctx.tortueCourante = (int)_id->calculer(ctx);
    }
private:
    ExpressionPtr _id;
};

class AppelFonction : public Instruction {
public:
    AppelFonction(const std::string & nom, const std::vector<ExpressionPtr> & args)
        : _nom(nom), _args(args) {}

    void executer(Contexte & ctx, Driver & driver) const override;

private:
    std::string _nom;
    std::vector<ExpressionPtr> _args;
};

// --- Structures de contrôle ---

class ControleSi : public Instruction {
public:
    ControleSi(std::shared_ptr<Condition> cond, InstructionPtr alors, InstructionPtr sinon = nullptr)
        : _condition(cond), _alors(alors), _sinon(sinon) {}

    void executer(Contexte & ctx, Driver & driver) const override {
        if (_condition->calculer(ctx, driver)) {
            _alors->executer(ctx, driver);
        } else if (_sinon) {
            _sinon->executer(ctx, driver);
        }
    }
private:
    std::shared_ptr<Condition> _condition;
    InstructionPtr _alors;
    InstructionPtr _sinon;
};

class ControleTantQue : public Instruction {
public:
    ControleTantQue(std::shared_ptr<Condition> cond, InstructionPtr bloc)
        : _condition(cond), _bloc(bloc) {}

    void executer(Contexte & ctx, Driver & driver) const override {
        while (_condition->calculer(ctx, driver)) {
            _bloc->executer(ctx, driver);
        }
    }
private:
    std::shared_ptr<Condition> _condition;
    InstructionPtr _bloc;
};

class ControleRepete : public Instruction {
public:
    ControleRepete(ExpressionPtr nb, InstructionPtr bloc)
        : _nb(nb), _bloc(bloc) {}

    void executer(Contexte & ctx, Driver & driver) const override {
        int n = (int)_nb->calculer(ctx);
        for(int i=0; i<n; ++i) _bloc->executer(ctx, driver);
    }
private:
    ExpressionPtr _nb;
    InstructionPtr _bloc;
};

inline void CommandeMouvement::bouger(Driver& d, TypeMouvement t, double v) const {
    extern void driver_bouger_wrapper(Driver&, TypeMouvement, double);
    driver_bouger_wrapper(d, t, v);
}

inline void CommandeCouleur::changerCouleur(Driver& d, double r, double g, double b) const {
    extern void driver_couleur_wrapper(Driver&, double, double, double);
    driver_couleur_wrapper(d, r, g, b);
}

#endif
