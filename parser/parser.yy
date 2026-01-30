%skeleton "lalr1.cc"
%require "3.0"
%defines
%define api.parser.class { Parser }
%define api.value.type variant
%define parse.assert
%locations

%code requires{
    #include "contexte.hh"
    #include "expression.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    #include "instructions.hh"
    #include "capteurs.hh"
    #include "types.hh"
    #include "condition.hh"
    #include "conditionBinaire.hh"
    #include "testBinaire.hh"
    #include <vector>
    #include <string>

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token NL END END_OF_FILE
%token AVANCE RECULE TOURNE SAUTE COULEUR TORTUES JARDIN FONCTION
%token SI SINON TANT QUE REPETE
%token MUR VIDE PAS DEVANT DERRIERE GAUCHE DROITE FOIS
%token DP AROBASE DOLLAR
%token PLUS MOINS MULT DIV LPAR RPAR EGAL DIFFERENT INF SUP ET OU
%token <double> NUMBER
%token <std::string> VAR_NAME
%token <std::vector<double>> COLOR_HEX

%type <ExpressionPtr> expression
%type <ConditionPtr> condition condition_base
%type <InstructionPtr> instruction commande structure_controle
%type <Bloc*> liste_instructions programme
%type <std::vector<ExpressionPtr>> args_appel
%type <Direction> direction

%left OU
%left ET
%left EGAL DIFFERENT INF SUP
%left PLUS MOINS
%left MULT DIV
%precedence NEG

%%

root:
    programme {
        driver.executer($1);
        delete $1;
        YYACCEPT;
    }
    ;

programme:
      programme instruction NL { $$ = $1; $$->ajouter($2); }
    | programme instruction END NL { $$ = $1; $$->ajouter($2); }
    | programme instruction END_OF_FILE { $$ = $1; $$->ajouter($2); }
    | programme NL { $$ = $1; }
    | programme definition_fonction NL { $$ = $1; }
    | /* vide */ { $$ = new Bloc(); }
    ;

definition_fonction:
    FONCTION VAR_NAME DP NL liste_instructions END FONCTION {
        driver.definirFonction($2, $5);
    }
    ;

liste_instructions:
      liste_instructions instruction NL { $$ = $1; $$->ajouter($2); }
    | instruction NL { $$ = new Bloc(); $$->ajouter($1); }
    | liste_instructions NL { $$ = $1; }
    | NL { $$ = new Bloc(); }
    ;

instruction:
      commande { $$ = $1; }
    | structure_controle { $$ = $1; }
    ;

unite_opt:
      /* vide */
    | FOIS
    | VAR_NAME /* Au cas où l'utilisateur écrit "pas" pour "steps" ou autre mot */
    ;

commande:
      AVANCE expression unite_opt { $$ = std::make_shared<CommandeMouvement>($2, TypeMouvement::AVANCE); }
    | RECULE expression unite_opt { $$ = std::make_shared<CommandeMouvement>($2, TypeMouvement::RECULE); }
    | SAUTE expression unite_opt  { $$ = std::make_shared<CommandeMouvement>($2, TypeMouvement::SAUTE); }
    | TOURNE expression unite_opt { $$ = std::make_shared<CommandeMouvement>($2, TypeMouvement::TOURNE); }

    /* Commandes sans arguments (valeurs par défaut) */
    | AVANCE { $$ = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::AVANCE); }
    | RECULE { $$ = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::RECULE); }
    | SAUTE  { $$ = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::SAUTE); }
    | TOURNE { $$ = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(90.0), TypeMouvement::TOURNE); }

    | TOURNE direction  {
        double angle = ($2 == Direction::GAUCHE) ? -90.0 : 90.0;
        $$ = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(angle), TypeMouvement::TOURNE);
      }
    | TOURNE direction expression unite_opt {
         ExpressionPtr angle = $3;
         if ($2 == Direction::GAUCHE) {
             angle = std::make_shared<ExpressionUnaire>($3, OperateurUnaire::neg);
         }
         $$ = std::make_shared<CommandeMouvement>(angle, TypeMouvement::TOURNE);
    }

    | TORTUES expression {
        /* Directive préprocesseur : exécutée immédiatement */
        int nb = (int)$2->calculer(driver.getContexte());
        driver.initTortues(nb);
        $$ = std::make_shared<Bloc>(); /* On retourne un bloc vide pour l'AST */
    }
    | COULEUR COLOR_HEX { $$ = std::make_shared<CommandeCouleur>($2[0], $2[1], $2[2]); }
    | COULEUR VAR_NAME { $$ = std::make_shared<CommandeCouleur>(255, 0, 0); } /* Couleur par defaut si erreur */

    | JARDIN VAR_NAME   { driver.nouveauJardin($2); $$ = std::make_shared<Bloc>(); }
    | VAR_NAME args_appel { $$ = std::make_shared<AppelFonction>($1, $2); }
    | commande AROBASE expression {
        Bloc* b = new Bloc();
        b->ajouter(std::make_shared<CommandeSelectionTortue>($3));
        b->ajouter($1);
        $$ = std::shared_ptr<Instruction>(b);
    }
    ;

structure_controle:
      SI condition DP NL liste_instructions END SI {
          $$ = std::make_shared<ControleSi>($2, std::shared_ptr<Instruction>($5));
      }
    | SI condition DP NL liste_instructions SINON DP NL liste_instructions END SI {
          $$ = std::make_shared<ControleSi>($2, std::shared_ptr<Instruction>($5), std::shared_ptr<Instruction>($9));
      }
    | TANT QUE condition DP NL liste_instructions END TANT QUE {
          $$ = std::make_shared<ControleTantQue>($3, std::shared_ptr<Instruction>($6));
      }
    | REPETE expression DP NL liste_instructions END REPETE {
          $$ = std::make_shared<ControleRepete>($2, std::shared_ptr<Instruction>($5));
      }
    ;

args_appel:
      args_appel expression { $$ = $1; $$.push_back($2); }
    | /* vide */ { }
    ;

condition:
      condition_base { $$ = $1; }
    | PAS condition { $$ = std::make_shared<ConditionNot>($2); }
    | condition ET condition { $$ = std::make_shared<ConditionBinaire>($1, $3, OperateurBinaireBool::et); }
    | condition OU condition { $$ = std::make_shared<ConditionBinaire>($1, $3, OperateurBinaireBool::ou); }
    | LPAR condition RPAR { $$ = $2; }
    ;

condition_base:
      MUR direction { $$ = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, $2); }
    | VIDE direction { $$ = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, $2); }
    | MUR direction AROBASE expression { $$ = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, $2, $4); }
    | VIDE direction AROBASE expression { $$ = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, $2, $4); }

    | expression EGAL expression { $$ = std::make_shared<TestBinaire>($1, $3, OperateurBool::egal); }
    | expression DIFFERENT expression { $$ = std::make_shared<TestBinaire>($1, $3, OperateurBool::different); }
    | expression INF expression { $$ = std::make_shared<TestBinaire>($1, $3, OperateurBool::pluspetit); }
    | expression SUP expression { $$ = std::make_shared<TestBinaire>($1, $3, OperateurBool::plusgrand); }
    ;

direction:
      DEVANT { $$ = Direction::DEVANT; }
    | DERRIERE { $$ = Direction::DERRIERE; }
    | GAUCHE { $$ = Direction::GAUCHE; }
    | DROITE { $$ = Direction::DROITE; }
    ;

expression:
      NUMBER { $$ = std::make_shared<Constante>($1); }
    | VAR_NAME { $$ = std::make_shared<Variable>($1); }
    | DOLLAR NUMBER { $$ = std::make_shared<Variable>("$" + std::to_string((int)$2)); }
    | expression PLUS expression { $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::plus); }
    | expression MOINS expression { $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::moins); }
    | expression MULT expression { $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::multiplie); }
    | expression DIV expression { $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::divise); }
    | MOINS expression %prec NEG { $$ = std::make_shared<ExpressionUnaire>($2, OperateurUnaire::neg); }
    | LPAR expression RPAR { $$ = $2; }
    ;

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
