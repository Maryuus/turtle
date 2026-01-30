#ifndef TYPES_HH
#define TYPES_HH

enum class TypeMouvement { AVANCE, RECULE, TOURNE, SAUTE };
enum class TypeCapteur { MUR, VIDE };
enum class Direction { DEVANT, DERRIERE, GAUCHE, DROITE };
enum class OperateurBinaire { plus, moins, multiplie, divise };
enum class OperateurUnaire { neg };
enum class OperateurBool { egal, different, pluspetit, plusgrand };
enum class OperateurBinaireBool { et, ou };

#endif
