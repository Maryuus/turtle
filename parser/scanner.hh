#ifndef SCANNER_HH
#define SCANNER_HH

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.hh" // Lien direct avec le parser généré
#include "location.hh"

class Scanner : public yyFlexLexer {
public:
    Scanner(std::istream & in, std::ostream & out) : yyFlexLexer(in, out) {}
    virtual ~Scanner() {}
    using FlexLexer::yylex;
    virtual int yylex(yy::Parser::semantic_type * const lval, yy::Parser::location_type *location);
private:
    yy::Parser::semantic_type *yylval = nullptr;
};
#endif
