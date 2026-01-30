%{
#include "scanner.hh"
#include <cstdlib>
#define YY_NO_UNISTD_H
using token = yy::Parser::token;
#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
%{
    yylval = lval;
%}

"--".* { }
"//".* { }
"%".* { }
[ \t]       { }
"\n"        { loc->lines(); return token::NL; }
"fin"       { return token::END; }

"avance"    { return token::AVANCE; }
"recule"    { return token::RECULE; }
"tourne"    { return token::TOURNE; }
"saute"     { return token::SAUTE; }
"couleur"   { return token::COULEUR; }
"tortues"   { return token::TORTUES; }
"jardin"    { return token::JARDIN; }

"si"        { return token::SI; }
"sinon"     { return token::SINON; }
"tant"      { return token::TANT; }
"que"       { return token::QUE; }
"repete"    { return token::REPETE; }
"fonction"  { return token::FONCTION; }

"mur"       { return token::MUR; }
"vide"      { return token::VIDE; }

"pas"[ \t]+"de" { return token::PAS; }
"pas"           { return token::PAS; }

"devant"    { return token::DEVANT; }
"derriere"  { return token::DERRIERE; }
"gauche"    { return token::GAUCHE; }
"droite"    { return token::DROITE; }

":"         { return token::DP; }
"@"         { return token::AROBASE; }
"$"         { return token::DOLLAR; }

[0-9]+(\.[0-9]+)?      { yylval->build<double>(std::atof(YYText())); return token::NUMBER; }

"#"[0-9a-fA-F]{6}      {
    std::string s = YYText();
    unsigned int r, g, b;
    std::sscanf(s.c_str(), "#%02x%02x%02x", &r, &g, &b);
    yylval->build<std::vector<double>>({(double)r, (double)g, (double)b});
    return token::COLOR_HEX;
}
"#".* { }

"+" { return token::PLUS; }
"-" { return token::MOINS; }
"*" { return token::MULT; }
"/" { return token::DIV; }
"(" { return token::LPAR; }
")" { return token::RPAR; }
"==" { return token::EGAL; }
"!=" { return token::DIFFERENT; }
"<" { return token::INF; }
">" { return token::SUP; }
"et" { return token::ET; }
"ou" { return token::OU; }

\"[^\"\n]*\" {
    std::string s(YYText());
    yylval->build<std::string>(s.substr(1, s.length()-2));
    return token::VAR_NAME;
}
\'[^\'\n]*\' {
    std::string s(YYText());
    yylval->build<std::string>(s.substr(1, s.length()-2));
    return token::VAR_NAME;
}

[a-zA-Z0-9_\./-]+ {
    yylval->build<std::string>(YYText());
    return token::VAR_NAME;
}

<<EOF>> { return token::END_OF_FILE; }
.       { }
%%
