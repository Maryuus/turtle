// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   parserlex



#include "parser.tab.hh"


// Unqualified %code blocks.
#line 34 "parser/parser.yy"

    #include <iostream>
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

#line 57 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace parser {
#line 149 "parser.tab.cc"

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_programme: // programme
      case symbol_kind::S_liste_instructions: // liste_instructions
        value.copy< Bloc* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
      case symbol_kind::S_condition_base: // condition_base
        value.copy< ConditionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direction: // direction
        value.copy< Direction > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.copy< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_commande: // commande
      case symbol_kind::S_structure_controle: // structure_controle
        value.copy< InstructionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAR_NAME: // VAR_NAME
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args_appel: // args_appel
        value.copy< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_COLOR_HEX: // COLOR_HEX
        value.copy< std::vector<double> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_programme: // programme
      case symbol_kind::S_liste_instructions: // liste_instructions
        value.move< Bloc* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_condition: // condition
      case symbol_kind::S_condition_base: // condition_base
        value.move< ConditionPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_direction: // direction
        value.move< Direction > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< ExpressionPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_commande: // commande
      case symbol_kind::S_structure_controle: // structure_controle
        value.move< InstructionPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VAR_NAME: // VAR_NAME
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_args_appel: // args_appel
        value.move< std::vector<ExpressionPtr> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_COLOR_HEX: // COLOR_HEX
        value.move< std::vector<double> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_programme: // programme
      case symbol_kind::S_liste_instructions: // liste_instructions
        value.YY_MOVE_OR_COPY< Bloc* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
      case symbol_kind::S_condition_base: // condition_base
        value.YY_MOVE_OR_COPY< ConditionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direction: // direction
        value.YY_MOVE_OR_COPY< Direction > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_commande: // commande
      case symbol_kind::S_structure_controle: // structure_controle
        value.YY_MOVE_OR_COPY< InstructionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAR_NAME: // VAR_NAME
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args_appel: // args_appel
        value.YY_MOVE_OR_COPY< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_COLOR_HEX: // COLOR_HEX
        value.YY_MOVE_OR_COPY< std::vector<double> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_programme: // programme
      case symbol_kind::S_liste_instructions: // liste_instructions
        value.move< Bloc* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
      case symbol_kind::S_condition_base: // condition_base
        value.move< ConditionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_direction: // direction
        value.move< Direction > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_commande: // commande
      case symbol_kind::S_structure_controle: // structure_controle
        value.move< InstructionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAR_NAME: // VAR_NAME
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args_appel: // args_appel
        value.move< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_COLOR_HEX: // COLOR_HEX
        value.move< std::vector<double> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_programme: // programme
      case symbol_kind::S_liste_instructions: // liste_instructions
        value.copy< Bloc* > (that.value);
        break;

      case symbol_kind::S_condition: // condition
      case symbol_kind::S_condition_base: // condition_base
        value.copy< ConditionPtr > (that.value);
        break;

      case symbol_kind::S_direction: // direction
        value.copy< Direction > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.copy< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_commande: // commande
      case symbol_kind::S_structure_controle: // structure_controle
        value.copy< InstructionPtr > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_VAR_NAME: // VAR_NAME
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_args_appel: // args_appel
        value.copy< std::vector<ExpressionPtr> > (that.value);
        break;

      case symbol_kind::S_COLOR_HEX: // COLOR_HEX
        value.copy< std::vector<double> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_programme: // programme
      case symbol_kind::S_liste_instructions: // liste_instructions
        value.move< Bloc* > (that.value);
        break;

      case symbol_kind::S_condition: // condition
      case symbol_kind::S_condition_base: // condition_base
        value.move< ConditionPtr > (that.value);
        break;

      case symbol_kind::S_direction: // direction
        value.move< Direction > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.move< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_commande: // commande
      case symbol_kind::S_structure_controle: // structure_controle
        value.move< InstructionPtr > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< double > (that.value);
        break;

      case symbol_kind::S_VAR_NAME: // VAR_NAME
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_args_appel: // args_appel
        value.move< std::vector<ExpressionPtr> > (that.value);
        break;

      case symbol_kind::S_COLOR_HEX: // COLOR_HEX
        value.move< std::vector<double> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_programme: // programme
      case symbol_kind::S_liste_instructions: // liste_instructions
        yylhs.value.emplace< Bloc* > ();
        break;

      case symbol_kind::S_condition: // condition
      case symbol_kind::S_condition_base: // condition_base
        yylhs.value.emplace< ConditionPtr > ();
        break;

      case symbol_kind::S_direction: // direction
        yylhs.value.emplace< Direction > ();
        break;

      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< ExpressionPtr > ();
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_commande: // commande
      case symbol_kind::S_structure_controle: // structure_controle
        yylhs.value.emplace< InstructionPtr > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_VAR_NAME: // VAR_NAME
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_args_appel: // args_appel
        yylhs.value.emplace< std::vector<ExpressionPtr> > ();
        break;

      case symbol_kind::S_COLOR_HEX: // COLOR_HEX
        yylhs.value.emplace< std::vector<double> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: programme
#line 73 "parser/parser.yy"
              {
        driver.executer(yystack_[0].value.as < Bloc* > ());
        delete yystack_[0].value.as < Bloc* > ();
        YYACCEPT;
    }
#line 923 "parser.tab.cc"
    break;

  case 3: // programme: programme instruction NL
#line 81 "parser/parser.yy"
                               { yylhs.value.as < Bloc* > () = yystack_[2].value.as < Bloc* > (); yylhs.value.as < Bloc* > ()->ajouter(yystack_[1].value.as < InstructionPtr > ()); }
#line 929 "parser.tab.cc"
    break;

  case 4: // programme: programme instruction END NL
#line 82 "parser/parser.yy"
                                   { yylhs.value.as < Bloc* > () = yystack_[3].value.as < Bloc* > (); yylhs.value.as < Bloc* > ()->ajouter(yystack_[2].value.as < InstructionPtr > ()); }
#line 935 "parser.tab.cc"
    break;

  case 5: // programme: programme instruction END_OF_FILE
#line 83 "parser/parser.yy"
                                        { yylhs.value.as < Bloc* > () = yystack_[2].value.as < Bloc* > (); yylhs.value.as < Bloc* > ()->ajouter(yystack_[1].value.as < InstructionPtr > ()); }
#line 941 "parser.tab.cc"
    break;

  case 6: // programme: programme NL
#line 84 "parser/parser.yy"
                   { yylhs.value.as < Bloc* > () = yystack_[1].value.as < Bloc* > (); }
#line 947 "parser.tab.cc"
    break;

  case 7: // programme: programme definition_fonction NL
#line 85 "parser/parser.yy"
                                       { yylhs.value.as < Bloc* > () = yystack_[2].value.as < Bloc* > (); }
#line 953 "parser.tab.cc"
    break;

  case 8: // programme: %empty
#line 86 "parser/parser.yy"
                 { yylhs.value.as < Bloc* > () = new Bloc(); }
#line 959 "parser.tab.cc"
    break;

  case 9: // definition_fonction: FONCTION VAR_NAME DP NL liste_instructions END FONCTION
#line 90 "parser/parser.yy"
                                                            {
        driver.definirFonction(yystack_[5].value.as < std::string > (), yystack_[2].value.as < Bloc* > ());
    }
#line 967 "parser.tab.cc"
    break;

  case 10: // liste_instructions: liste_instructions instruction NL
#line 96 "parser/parser.yy"
                                        { yylhs.value.as < Bloc* > () = yystack_[2].value.as < Bloc* > (); yylhs.value.as < Bloc* > ()->ajouter(yystack_[1].value.as < InstructionPtr > ()); }
#line 973 "parser.tab.cc"
    break;

  case 11: // liste_instructions: instruction NL
#line 97 "parser/parser.yy"
                     { yylhs.value.as < Bloc* > () = new Bloc(); yylhs.value.as < Bloc* > ()->ajouter(yystack_[1].value.as < InstructionPtr > ()); }
#line 979 "parser.tab.cc"
    break;

  case 12: // liste_instructions: liste_instructions NL
#line 98 "parser/parser.yy"
                            { yylhs.value.as < Bloc* > () = yystack_[1].value.as < Bloc* > (); }
#line 985 "parser.tab.cc"
    break;

  case 13: // instruction: commande
#line 102 "parser/parser.yy"
               { yylhs.value.as < InstructionPtr > () = yystack_[0].value.as < InstructionPtr > (); }
#line 991 "parser.tab.cc"
    break;

  case 14: // instruction: structure_controle
#line 103 "parser/parser.yy"
                         { yylhs.value.as < InstructionPtr > () = yystack_[0].value.as < InstructionPtr > (); }
#line 997 "parser.tab.cc"
    break;

  case 15: // commande: AVANCE expression
#line 107 "parser/parser.yy"
                        { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[0].value.as < ExpressionPtr > (), TypeMouvement::AVANCE); }
#line 1003 "parser.tab.cc"
    break;

  case 16: // commande: RECULE expression
#line 108 "parser/parser.yy"
                        { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[0].value.as < ExpressionPtr > (), TypeMouvement::RECULE); }
#line 1009 "parser.tab.cc"
    break;

  case 17: // commande: TOURNE expression
#line 109 "parser/parser.yy"
                        { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[0].value.as < ExpressionPtr > (), TypeMouvement::TOURNE); }
#line 1015 "parser.tab.cc"
    break;

  case 18: // commande: TOURNE direction
#line 110 "parser/parser.yy"
                        {
        double angle = (yystack_[0].value.as < Direction > () == Direction::GAUCHE) ? -90.0 : 90.0;
        yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(angle), TypeMouvement::TOURNE);
      }
#line 1024 "parser.tab.cc"
    break;

  case 19: // commande: SAUTE expression
#line 114 "parser/parser.yy"
                        { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[0].value.as < ExpressionPtr > (), TypeMouvement::SAUTE); }
#line 1030 "parser.tab.cc"
    break;

  case 20: // commande: COULEUR COLOR_HEX
#line 115 "parser/parser.yy"
                        { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeCouleur>(yystack_[0].value.as < std::vector<double> > ()[0], yystack_[0].value.as < std::vector<double> > ()[1], yystack_[0].value.as < std::vector<double> > ()[2]); }
#line 1036 "parser.tab.cc"
    break;

  case 21: // commande: JARDIN VAR_NAME
#line 116 "parser/parser.yy"
                        {
                          driver.nouveauJardin(yystack_[0].value.as < std::string > ());
                          yylhs.value.as < InstructionPtr > () = std::make_shared<Bloc>();
                        }
#line 1045 "parser.tab.cc"
    break;

  case 22: // commande: VAR_NAME args_appel
#line 120 "parser/parser.yy"
                          { yylhs.value.as < InstructionPtr > () = std::make_shared<AppelFonction>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ExpressionPtr> > ()); }
#line 1051 "parser.tab.cc"
    break;

  case 23: // commande: commande AROBASE expression
#line 121 "parser/parser.yy"
                                  {
        Bloc* b = new Bloc();
        b->ajouter(std::make_shared<CommandeSelectionTortue>(yystack_[0].value.as < ExpressionPtr > ()));
        b->ajouter(yystack_[2].value.as < InstructionPtr > ());
        yylhs.value.as < InstructionPtr > () = std::shared_ptr<Instruction>(b);
    }
#line 1062 "parser.tab.cc"
    break;

  case 24: // structure_controle: SI condition DP NL liste_instructions END SI
#line 130 "parser/parser.yy"
                                                   {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleSi>(yystack_[5].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1070 "parser.tab.cc"
    break;

  case 25: // structure_controle: SI condition DP NL liste_instructions SINON DP NL liste_instructions END SI
#line 133 "parser/parser.yy"
                                                                                  {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleSi>(yystack_[9].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[6].value.as < Bloc* > ()), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1078 "parser.tab.cc"
    break;

  case 26: // structure_controle: TANT QUE condition DP NL liste_instructions END TANT QUE
#line 136 "parser/parser.yy"
                                                               {
          /* Correction ici : $3 pour la condition au lieu de $2 */
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleTantQue>(yystack_[6].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[3].value.as < Bloc* > ()));
      }
#line 1087 "parser.tab.cc"
    break;

  case 27: // structure_controle: REPETE expression DP NL liste_instructions END REPETE
#line 140 "parser/parser.yy"
                                                            {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleRepete>(yystack_[5].value.as < ExpressionPtr > (), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1095 "parser.tab.cc"
    break;

  case 28: // args_appel: args_appel expression
#line 146 "parser/parser.yy"
                            { yylhs.value.as < std::vector<ExpressionPtr> > () = yystack_[1].value.as < std::vector<ExpressionPtr> > (); yylhs.value.as < std::vector<ExpressionPtr> > ().push_back(yystack_[0].value.as < ExpressionPtr > ()); }
#line 1101 "parser.tab.cc"
    break;

  case 29: // args_appel: %empty
#line 147 "parser/parser.yy"
                 { }
#line 1107 "parser.tab.cc"
    break;

  case 30: // condition: condition_base
#line 151 "parser/parser.yy"
                     { yylhs.value.as < ConditionPtr > () = yystack_[0].value.as < ConditionPtr > (); }
#line 1113 "parser.tab.cc"
    break;

  case 31: // condition: PAS condition_base
#line 152 "parser/parser.yy"
                         {
        yylhs.value.as < ConditionPtr > () = yystack_[0].value.as < ConditionPtr > ();
    }
#line 1121 "parser.tab.cc"
    break;

  case 32: // condition: condition ET condition
#line 155 "parser/parser.yy"
                             { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionBinaire>(yystack_[2].value.as < ConditionPtr > (), yystack_[0].value.as < ConditionPtr > (), OperateurBinaireBool::et); }
#line 1127 "parser.tab.cc"
    break;

  case 33: // condition: condition OU condition
#line 156 "parser/parser.yy"
                             { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionBinaire>(yystack_[2].value.as < ConditionPtr > (), yystack_[0].value.as < ConditionPtr > (), OperateurBinaireBool::ou); }
#line 1133 "parser.tab.cc"
    break;

  case 34: // condition: LPAR condition RPAR
#line 157 "parser/parser.yy"
                          { yylhs.value.as < ConditionPtr > () = yystack_[1].value.as < ConditionPtr > (); }
#line 1139 "parser.tab.cc"
    break;

  case 35: // condition_base: MUR direction
#line 161 "parser/parser.yy"
                    { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, yystack_[0].value.as < Direction > ()); }
#line 1145 "parser.tab.cc"
    break;

  case 36: // condition_base: VIDE direction
#line 162 "parser/parser.yy"
                     { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, yystack_[0].value.as < Direction > ()); }
#line 1151 "parser.tab.cc"
    break;

  case 37: // condition_base: PAS MUR direction
#line 163 "parser/parser.yy"
                        {
         yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, yystack_[0].value.as < Direction > ());
      }
#line 1159 "parser.tab.cc"
    break;

  case 38: // condition_base: PAS VIDE direction
#line 166 "parser/parser.yy"
                         {
         yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, yystack_[0].value.as < Direction > ());
      }
#line 1167 "parser.tab.cc"
    break;

  case 39: // condition_base: expression EGAL expression
#line 169 "parser/parser.yy"
                                 { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::egal); }
#line 1173 "parser.tab.cc"
    break;

  case 40: // condition_base: expression DIFFERENT expression
#line 170 "parser/parser.yy"
                                      { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::different); }
#line 1179 "parser.tab.cc"
    break;

  case 41: // condition_base: expression INF expression
#line 171 "parser/parser.yy"
                                { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::pluspetit); }
#line 1185 "parser.tab.cc"
    break;

  case 42: // condition_base: expression SUP expression
#line 172 "parser/parser.yy"
                                { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::plusgrand); }
#line 1191 "parser.tab.cc"
    break;

  case 43: // direction: DEVANT
#line 176 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::DEVANT; }
#line 1197 "parser.tab.cc"
    break;

  case 44: // direction: DERRIERE
#line 177 "parser/parser.yy"
               { yylhs.value.as < Direction > () = Direction::DERRIERE; }
#line 1203 "parser.tab.cc"
    break;

  case 45: // direction: GAUCHE
#line 178 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::GAUCHE; }
#line 1209 "parser.tab.cc"
    break;

  case 46: // direction: DROITE
#line 179 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::DROITE; }
#line 1215 "parser.tab.cc"
    break;

  case 47: // expression: NUMBER
#line 183 "parser/parser.yy"
             { yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < double > ()); }
#line 1221 "parser.tab.cc"
    break;

  case 48: // expression: VAR_NAME
#line 184 "parser/parser.yy"
               { yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ()); }
#line 1227 "parser.tab.cc"
    break;

  case 49: // expression: DOLLAR NUMBER
#line 185 "parser/parser.yy"
                    { yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>("$" + std::to_string((int)yystack_[0].value.as < double > ())); }
#line 1233 "parser.tab.cc"
    break;

  case 50: // expression: expression PLUS expression
#line 186 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::plus); }
#line 1239 "parser.tab.cc"
    break;

  case 51: // expression: expression MOINS expression
#line 187 "parser/parser.yy"
                                  { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::moins); }
#line 1245 "parser.tab.cc"
    break;

  case 52: // expression: expression MULT expression
#line 188 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::multiplie); }
#line 1251 "parser.tab.cc"
    break;

  case 53: // expression: expression DIV expression
#line 189 "parser/parser.yy"
                                { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::divise); }
#line 1257 "parser.tab.cc"
    break;

  case 54: // expression: MOINS expression
#line 190 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (), OperateurUnaire::neg); }
#line 1263 "parser.tab.cc"
    break;

  case 55: // expression: LPAR expression RPAR
#line 191 "parser/parser.yy"
                           { yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > (); }
#line 1269 "parser.tab.cc"
    break;


#line 1273 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char  Parser ::yypact_ninf_ = -85;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     -85,     8,    87,   -85,   -85,   -14,   -14,   205,   -14,   -17,
     -30,   -13,   180,    15,   -14,   -85,    32,    45,    39,   -85,
       0,   -14,   -14,   -85,   -85,    33,    33,   -85,   -85,   -85,
     -85,   -85,    33,    33,   -85,   -85,    47,    84,    84,   184,
     180,   -15,   -85,   229,   180,    14,   -14,   -85,   -85,    76,
     -85,   -14,   -85,   -85,   210,   -14,   -14,   -14,   -14,    78,
     -85,   -85,    84,    84,     3,   -85,    21,   219,    82,   180,
     180,   -14,   -14,   -14,   -14,    -6,    85,    33,   -85,    33,
     -85,    27,    27,   -85,   -85,   178,   -85,   -85,    84,    84,
     -85,   178,   -85,    48,    33,    33,    33,    33,    86,   178,
     110,    88,   -85,   -85,    68,   178,   127,   -85,    79,   109,
     -85,   101,    97,   147,   107,   -85,   -85,   -85,   124,   116,
     -85,   178,   121,   164,   -85,   126,   -85
  };

  const signed char
   Parser ::yydefact_[] =
  {
       8,     0,     2,     1,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,    13,    14,
       0,     0,     0,    47,    48,    15,    16,    43,    44,    45,
      46,    18,    17,    19,    20,    21,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,    22,     7,     3,     0,
       5,     0,    49,    54,     0,     0,     0,     0,     0,     0,
      35,    36,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     4,    23,
      55,    50,    51,    52,    53,     0,    35,    36,     0,     0,
      34,     0,    32,    33,    39,    40,    41,    42,     0,     0,
       0,     0,    37,    38,     0,     0,     0,    12,     0,     0,
      11,     0,     0,     0,     0,     9,    10,    24,     0,     0,
      27,     0,     0,     0,    26,     0,    25
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -85,   -85,   -85,   -85,   -84,    -2,   -85,   -85,   -85,   -31,
     103,   -32,    -4
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,     1,     2,    16,   100,   101,    18,    19,    46,    41,
      42,    31,    43
  };

  const signed char
   Parser ::yytable_[] =
  {
      17,    25,    26,    32,    33,    60,    61,   104,     3,    66,
      45,    68,    35,    75,    20,   106,    21,    53,    54,    22,
      98,   113,    88,    89,    69,    70,    34,    23,    24,    36,
      86,    87,    44,    69,    70,    47,    67,   123,    92,    93,
      76,    52,    77,    55,    56,    57,    58,    79,    48,    49,
      50,    81,    82,    83,    84,    90,   102,   103,    57,    58,
      69,    70,    55,    56,    57,    58,    51,    94,    95,    96,
      97,   107,   111,    59,     5,     6,     7,     8,     9,    78,
      10,    85,    12,   112,    13,    91,    14,    69,    99,   105,
       4,   110,   115,     5,     6,     7,     8,     9,   109,    10,
      11,    12,   109,    13,   109,    14,    27,    28,    29,    30,
      15,   109,   116,   107,   108,   117,     5,     6,     7,     8,
       9,   109,    10,   118,    12,   120,    13,   121,    14,    15,
     107,   114,   122,     5,     6,     7,     8,     9,   124,    10,
     126,    12,    65,    13,     0,    14,     0,     0,     0,     0,
     107,   119,    15,     5,     6,     7,     8,     9,     0,    10,
       0,    12,     0,    13,     0,    14,     0,   107,   125,    15,
       5,     6,     7,     8,     9,     0,    10,     0,    12,     0,
      13,     0,    14,     0,     5,     6,     7,     8,     9,    15,
      10,     0,    12,     0,    13,     0,    14,     0,     0,    37,
      38,    39,     0,    62,    63,    64,    15,     0,    20,     0,
      21,     0,    20,    40,    21,     0,     0,    22,     0,     0,
      15,    23,    24,     0,     0,    23,    24,    27,    28,    29,
      30,     0,     0,    20,     0,    21,     0,     0,    22,    55,
      56,    57,    58,     0,    80,     0,    23,    24,    55,    56,
      57,    58,     0,    80,    71,    72,    73,    74,    55,    56,
      57,    58,     0,     0,    71,    72,    73,    74
  };

  const signed char
   Parser ::yycheck_[] =
  {
       2,     5,     6,     7,     8,    37,    38,    91,     0,    40,
      14,    26,    42,    44,    28,    99,    30,    21,    22,    33,
      26,   105,    19,    20,    39,    40,    43,    41,    42,    42,
      62,    63,    17,    39,    40,     3,    40,   121,    69,    70,
      26,    41,    46,    29,    30,    31,    32,    51,     3,     4,
       5,    55,    56,    57,    58,    34,    88,    89,    31,    32,
      39,    40,    29,    30,    31,    32,    27,    71,    72,    73,
      74,     3,     4,    26,     6,     7,     8,     9,    10,     3,
      12,     3,    14,    15,    16,     3,    18,    39,     3,     3,
       3,     3,    13,     6,     7,     8,     9,    10,   100,    12,
      13,    14,   104,    16,   106,    18,    22,    23,    24,    25,
      42,   113,     3,     3,     4,    14,     6,     7,     8,     9,
      10,   123,    12,    26,    14,    18,    16,     3,    18,    42,
       3,     4,    16,     6,     7,     8,     9,    10,    17,    12,
      14,    14,    39,    16,    -1,    18,    -1,    -1,    -1,    -1,
       3,     4,    42,     6,     7,     8,     9,    10,    -1,    12,
      -1,    14,    -1,    16,    -1,    18,    -1,     3,     4,    42,
       6,     7,     8,     9,    10,    -1,    12,    -1,    14,    -1,
      16,    -1,    18,    -1,     6,     7,     8,     9,    10,    42,
      12,    -1,    14,    -1,    16,    -1,    18,    -1,    -1,    19,
      20,    21,    -1,    19,    20,    21,    42,    -1,    28,    -1,
      30,    -1,    28,    33,    30,    -1,    -1,    33,    -1,    -1,
      42,    41,    42,    -1,    -1,    41,    42,    22,    23,    24,
      25,    -1,    -1,    28,    -1,    30,    -1,    -1,    33,    29,
      30,    31,    32,    -1,    34,    -1,    41,    42,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    38,    29,    30,
      31,    32,    -1,    -1,    35,    36,    37,    38
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    46,    47,     0,     3,     6,     7,     8,     9,    10,
      12,    13,    14,    16,    18,    42,    48,    50,    51,    52,
      28,    30,    33,    41,    42,    57,    57,    22,    23,    24,
      25,    56,    57,    57,    43,    42,    42,    19,    20,    21,
      33,    54,    55,    57,    17,    57,    53,     3,     3,     4,
       5,    27,    41,    57,    57,    29,    30,    31,    32,    26,
      56,    56,    19,    20,    21,    55,    54,    57,    26,    39,
      40,    35,    36,    37,    38,    54,    26,    57,     3,    57,
      34,    57,    57,    57,    57,     3,    56,    56,    19,    20,
      34,     3,    54,    54,    57,    57,    57,    57,    26,     3,
      49,    50,    56,    56,    49,     3,    49,     3,     4,    50,
       3,     4,    15,    49,     4,    13,     3,    14,    26,     4,
      18,     3,    16,    49,    17,     4,    14
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    45,    46,    47,    47,    47,    47,    47,    47,    48,
      49,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     3,     4,     3,     2,     3,     0,     7,
       3,     2,     2,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     7,    11,     9,     7,     2,     0,
       1,     2,     3,     3,     3,     2,     2,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     3,     3,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "END",
  "END_OF_FILE", "AVANCE", "RECULE", "TOURNE", "SAUTE", "COULEUR",
  "TORTUES", "JARDIN", "FONCTION", "SI", "SINON", "TANT", "QUE", "REPETE",
  "MUR", "VIDE", "PAS", "DEVANT", "DERRIERE", "GAUCHE", "DROITE", "DP",
  "AROBASE", "DOLLAR", "PLUS", "MOINS", "MULT", "DIV", "LPAR", "RPAR",
  "EGAL", "DIFFERENT", "INF", "SUP", "ET", "OU", "NUMBER", "VAR_NAME",
  "COLOR_HEX", "NEG", "$accept", "root", "programme",
  "definition_fonction", "liste_instructions", "instruction", "commande",
  "structure_controle", "args_appel", "condition", "condition_base",
  "direction", "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    73,    73,    81,    82,    83,    84,    85,    86,    90,
      96,    97,    98,   102,   103,   107,   108,   109,   110,   114,
     115,   116,   120,   121,   130,   133,   136,   140,   146,   147,
     151,   152,   155,   156,   157,   161,   162,   163,   166,   169,
     170,   171,   172,   176,   177,   178,   179,   183,   184,   185,
     186,   187,   188,   189,   190,   191
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    // Last valid token kind.
    const int code_max = 299;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // parser
#line 1736 "parser.tab.cc"

#line 194 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
