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





#include "parser.hh"


// Unqualified %code blocks.
#line 32 "parser/parser.yy"

    #include <iostream>
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

#line 55 "parser/parser.cc"


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

namespace yy {
#line 147 "parser/parser.cc"

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
#line 68 "parser/parser.yy"
              {
        driver.executer(yystack_[0].value.as < Bloc* > ());
        delete yystack_[0].value.as < Bloc* > ();
        YYACCEPT;
    }
#line 921 "parser/parser.cc"
    break;

  case 3: // programme: programme instruction NL
#line 76 "parser/parser.yy"
                               { yylhs.value.as < Bloc* > () = yystack_[2].value.as < Bloc* > (); yylhs.value.as < Bloc* > ()->ajouter(yystack_[1].value.as < InstructionPtr > ()); }
#line 927 "parser/parser.cc"
    break;

  case 4: // programme: programme instruction END NL
#line 77 "parser/parser.yy"
                                   { yylhs.value.as < Bloc* > () = yystack_[3].value.as < Bloc* > (); yylhs.value.as < Bloc* > ()->ajouter(yystack_[2].value.as < InstructionPtr > ()); }
#line 933 "parser/parser.cc"
    break;

  case 5: // programme: programme instruction END_OF_FILE
#line 78 "parser/parser.yy"
                                        { yylhs.value.as < Bloc* > () = yystack_[2].value.as < Bloc* > (); yylhs.value.as < Bloc* > ()->ajouter(yystack_[1].value.as < InstructionPtr > ()); }
#line 939 "parser/parser.cc"
    break;

  case 6: // programme: programme NL
#line 79 "parser/parser.yy"
                   { yylhs.value.as < Bloc* > () = yystack_[1].value.as < Bloc* > (); }
#line 945 "parser/parser.cc"
    break;

  case 7: // programme: programme definition_fonction NL
#line 80 "parser/parser.yy"
                                       { yylhs.value.as < Bloc* > () = yystack_[2].value.as < Bloc* > (); }
#line 951 "parser/parser.cc"
    break;

  case 8: // programme: %empty
#line 81 "parser/parser.yy"
                 { yylhs.value.as < Bloc* > () = new Bloc(); }
#line 957 "parser/parser.cc"
    break;

  case 9: // definition_fonction: FONCTION VAR_NAME DP NL liste_instructions END FONCTION
#line 85 "parser/parser.yy"
                                                            {
        driver.definirFonction(yystack_[5].value.as < std::string > (), yystack_[2].value.as < Bloc* > ());
    }
#line 965 "parser/parser.cc"
    break;

  case 10: // liste_instructions: liste_instructions instruction NL
#line 91 "parser/parser.yy"
                                        { yylhs.value.as < Bloc* > () = yystack_[2].value.as < Bloc* > (); yylhs.value.as < Bloc* > ()->ajouter(yystack_[1].value.as < InstructionPtr > ()); }
#line 971 "parser/parser.cc"
    break;

  case 11: // liste_instructions: instruction NL
#line 92 "parser/parser.yy"
                     { yylhs.value.as < Bloc* > () = new Bloc(); yylhs.value.as < Bloc* > ()->ajouter(yystack_[1].value.as < InstructionPtr > ()); }
#line 977 "parser/parser.cc"
    break;

  case 12: // liste_instructions: liste_instructions NL
#line 93 "parser/parser.yy"
                            { yylhs.value.as < Bloc* > () = yystack_[1].value.as < Bloc* > (); }
#line 983 "parser/parser.cc"
    break;

  case 13: // liste_instructions: NL
#line 94 "parser/parser.yy"
         { yylhs.value.as < Bloc* > () = new Bloc(); }
#line 989 "parser/parser.cc"
    break;

  case 14: // instruction: commande
#line 98 "parser/parser.yy"
               { yylhs.value.as < InstructionPtr > () = yystack_[0].value.as < InstructionPtr > (); }
#line 995 "parser/parser.cc"
    break;

  case 15: // instruction: structure_controle
#line 99 "parser/parser.yy"
                         { yylhs.value.as < InstructionPtr > () = yystack_[0].value.as < InstructionPtr > (); }
#line 1001 "parser/parser.cc"
    break;

  case 19: // commande: AVANCE expression unite_opt
#line 109 "parser/parser.yy"
                                  { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[1].value.as < ExpressionPtr > (), TypeMouvement::AVANCE); }
#line 1007 "parser/parser.cc"
    break;

  case 20: // commande: RECULE expression unite_opt
#line 110 "parser/parser.yy"
                                  { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[1].value.as < ExpressionPtr > (), TypeMouvement::RECULE); }
#line 1013 "parser/parser.cc"
    break;

  case 21: // commande: SAUTE expression unite_opt
#line 111 "parser/parser.yy"
                                  { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[1].value.as < ExpressionPtr > (), TypeMouvement::SAUTE); }
#line 1019 "parser/parser.cc"
    break;

  case 22: // commande: TOURNE expression unite_opt
#line 112 "parser/parser.yy"
                                  { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[1].value.as < ExpressionPtr > (), TypeMouvement::TOURNE); }
#line 1025 "parser/parser.cc"
    break;

  case 23: // commande: AVANCE
#line 115 "parser/parser.yy"
             { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::AVANCE); }
#line 1031 "parser/parser.cc"
    break;

  case 24: // commande: RECULE
#line 116 "parser/parser.yy"
             { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::RECULE); }
#line 1037 "parser/parser.cc"
    break;

  case 25: // commande: SAUTE
#line 117 "parser/parser.yy"
             { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::SAUTE); }
#line 1043 "parser/parser.cc"
    break;

  case 26: // commande: TOURNE
#line 118 "parser/parser.yy"
             { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(90.0), TypeMouvement::TOURNE); }
#line 1049 "parser/parser.cc"
    break;

  case 27: // commande: TOURNE direction
#line 120 "parser/parser.yy"
                        {
        double angle = (yystack_[0].value.as < Direction > () == Direction::GAUCHE) ? -90.0 : 90.0;
        yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(angle), TypeMouvement::TOURNE);
      }
#line 1058 "parser/parser.cc"
    break;

  case 28: // commande: TOURNE direction expression unite_opt
#line 124 "parser/parser.yy"
                                            {
         ExpressionPtr angle = yystack_[1].value.as < ExpressionPtr > ();
         if (yystack_[2].value.as < Direction > () == Direction::GAUCHE) {
             angle = std::make_shared<ExpressionUnaire>(yystack_[1].value.as < ExpressionPtr > (), OperateurUnaire::neg);
         }
         yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(angle, TypeMouvement::TOURNE);
    }
#line 1070 "parser/parser.cc"
    break;

  case 29: // commande: TORTUES expression
#line 132 "parser/parser.yy"
                         {
        /* Directive préprocesseur : exécutée immédiatement */
        int nb = (int)yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.initTortues(nb);
        yylhs.value.as < InstructionPtr > () = std::make_shared<Bloc>(); /* On retourne un bloc vide pour l'AST */
    }
#line 1081 "parser/parser.cc"
    break;

  case 30: // commande: COULEUR COLOR_HEX
#line 138 "parser/parser.yy"
                        { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeCouleur>(yystack_[0].value.as < std::vector<double> > ()[0], yystack_[0].value.as < std::vector<double> > ()[1], yystack_[0].value.as < std::vector<double> > ()[2]); }
#line 1087 "parser/parser.cc"
    break;

  case 31: // commande: COULEUR VAR_NAME
#line 139 "parser/parser.yy"
                       { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeCouleur>(255, 0, 0); }
#line 1093 "parser/parser.cc"
    break;

  case 32: // commande: JARDIN VAR_NAME
#line 141 "parser/parser.yy"
                        { driver.nouveauJardin(yystack_[0].value.as < std::string > ()); yylhs.value.as < InstructionPtr > () = std::make_shared<Bloc>(); }
#line 1099 "parser/parser.cc"
    break;

  case 33: // commande: VAR_NAME args_appel
#line 142 "parser/parser.yy"
                          { yylhs.value.as < InstructionPtr > () = std::make_shared<AppelFonction>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ExpressionPtr> > ()); }
#line 1105 "parser/parser.cc"
    break;

  case 34: // commande: commande AROBASE expression
#line 143 "parser/parser.yy"
                                  {
        Bloc* b = new Bloc();
        b->ajouter(std::make_shared<CommandeSelectionTortue>(yystack_[0].value.as < ExpressionPtr > ()));
        b->ajouter(yystack_[2].value.as < InstructionPtr > ());
        yylhs.value.as < InstructionPtr > () = std::shared_ptr<Instruction>(b);
    }
#line 1116 "parser/parser.cc"
    break;

  case 35: // structure_controle: SI condition DP NL liste_instructions END SI
#line 152 "parser/parser.yy"
                                                   {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleSi>(yystack_[5].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1124 "parser/parser.cc"
    break;

  case 36: // structure_controle: SI condition DP NL liste_instructions SINON DP NL liste_instructions END SI
#line 155 "parser/parser.yy"
                                                                                  {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleSi>(yystack_[9].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[6].value.as < Bloc* > ()), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1132 "parser/parser.cc"
    break;

  case 37: // structure_controle: TANT QUE condition DP NL liste_instructions END TANT QUE
#line 158 "parser/parser.yy"
                                                               {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleTantQue>(yystack_[6].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[3].value.as < Bloc* > ()));
      }
#line 1140 "parser/parser.cc"
    break;

  case 38: // structure_controle: REPETE expression DP NL liste_instructions END REPETE
#line 161 "parser/parser.yy"
                                                            {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleRepete>(yystack_[5].value.as < ExpressionPtr > (), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1148 "parser/parser.cc"
    break;

  case 39: // args_appel: args_appel expression
#line 167 "parser/parser.yy"
                            { yylhs.value.as < std::vector<ExpressionPtr> > () = yystack_[1].value.as < std::vector<ExpressionPtr> > (); yylhs.value.as < std::vector<ExpressionPtr> > ().push_back(yystack_[0].value.as < ExpressionPtr > ()); }
#line 1154 "parser/parser.cc"
    break;

  case 40: // args_appel: %empty
#line 168 "parser/parser.yy"
                 { }
#line 1160 "parser/parser.cc"
    break;

  case 41: // condition: condition_base
#line 172 "parser/parser.yy"
                     { yylhs.value.as < ConditionPtr > () = yystack_[0].value.as < ConditionPtr > (); }
#line 1166 "parser/parser.cc"
    break;

  case 42: // condition: PAS condition
#line 173 "parser/parser.yy"
                    { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionNot>(yystack_[0].value.as < ConditionPtr > ()); }
#line 1172 "parser/parser.cc"
    break;

  case 43: // condition: condition ET condition
#line 174 "parser/parser.yy"
                             { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionBinaire>(yystack_[2].value.as < ConditionPtr > (), yystack_[0].value.as < ConditionPtr > (), OperateurBinaireBool::et); }
#line 1178 "parser/parser.cc"
    break;

  case 44: // condition: condition OU condition
#line 175 "parser/parser.yy"
                             { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionBinaire>(yystack_[2].value.as < ConditionPtr > (), yystack_[0].value.as < ConditionPtr > (), OperateurBinaireBool::ou); }
#line 1184 "parser/parser.cc"
    break;

  case 45: // condition: LPAR condition RPAR
#line 176 "parser/parser.yy"
                          { yylhs.value.as < ConditionPtr > () = yystack_[1].value.as < ConditionPtr > (); }
#line 1190 "parser/parser.cc"
    break;

  case 46: // condition_base: MUR direction
#line 180 "parser/parser.yy"
                    { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, yystack_[0].value.as < Direction > ()); }
#line 1196 "parser/parser.cc"
    break;

  case 47: // condition_base: VIDE direction
#line 181 "parser/parser.yy"
                     { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, yystack_[0].value.as < Direction > ()); }
#line 1202 "parser/parser.cc"
    break;

  case 48: // condition_base: MUR direction AROBASE expression
#line 182 "parser/parser.yy"
                                       { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, yystack_[2].value.as < Direction > (), yystack_[0].value.as < ExpressionPtr > ()); }
#line 1208 "parser/parser.cc"
    break;

  case 49: // condition_base: VIDE direction AROBASE expression
#line 183 "parser/parser.yy"
                                        { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, yystack_[2].value.as < Direction > (), yystack_[0].value.as < ExpressionPtr > ()); }
#line 1214 "parser/parser.cc"
    break;

  case 50: // condition_base: expression EGAL expression
#line 185 "parser/parser.yy"
                                 { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::egal); }
#line 1220 "parser/parser.cc"
    break;

  case 51: // condition_base: expression DIFFERENT expression
#line 186 "parser/parser.yy"
                                      { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::different); }
#line 1226 "parser/parser.cc"
    break;

  case 52: // condition_base: expression INF expression
#line 187 "parser/parser.yy"
                                { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::pluspetit); }
#line 1232 "parser/parser.cc"
    break;

  case 53: // condition_base: expression SUP expression
#line 188 "parser/parser.yy"
                                { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::plusgrand); }
#line 1238 "parser/parser.cc"
    break;

  case 54: // direction: DEVANT
#line 192 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::DEVANT; }
#line 1244 "parser/parser.cc"
    break;

  case 55: // direction: DERRIERE
#line 193 "parser/parser.yy"
               { yylhs.value.as < Direction > () = Direction::DERRIERE; }
#line 1250 "parser/parser.cc"
    break;

  case 56: // direction: GAUCHE
#line 194 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::GAUCHE; }
#line 1256 "parser/parser.cc"
    break;

  case 57: // direction: DROITE
#line 195 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::DROITE; }
#line 1262 "parser/parser.cc"
    break;

  case 58: // expression: NUMBER
#line 199 "parser/parser.yy"
             { yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < double > ()); }
#line 1268 "parser/parser.cc"
    break;

  case 59: // expression: VAR_NAME
#line 200 "parser/parser.yy"
               { yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ()); }
#line 1274 "parser/parser.cc"
    break;

  case 60: // expression: DOLLAR NUMBER
#line 201 "parser/parser.yy"
                    { yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>("$" + std::to_string((int)yystack_[0].value.as < double > ())); }
#line 1280 "parser/parser.cc"
    break;

  case 61: // expression: expression PLUS expression
#line 202 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::plus); }
#line 1286 "parser/parser.cc"
    break;

  case 62: // expression: expression MOINS expression
#line 203 "parser/parser.yy"
                                  { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::moins); }
#line 1292 "parser/parser.cc"
    break;

  case 63: // expression: expression MULT expression
#line 204 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::multiplie); }
#line 1298 "parser/parser.cc"
    break;

  case 64: // expression: expression DIV expression
#line 205 "parser/parser.yy"
                                { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::divise); }
#line 1304 "parser/parser.cc"
    break;

  case 65: // expression: MOINS expression
#line 206 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (), OperateurUnaire::neg); }
#line 1310 "parser/parser.cc"
    break;

  case 66: // expression: LPAR expression RPAR
#line 207 "parser/parser.yy"
                           { yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > (); }
#line 1316 "parser/parser.cc"
    break;


#line 1320 "parser/parser.cc"

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









  const signed char  Parser ::yypact_ninf_ = -47;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     -47,     5,    86,   -47,   -47,   -19,   -19,   212,   -19,   -35,
     -19,   -18,     0,   197,    31,   -19,   -47,    85,    17,    73,
     -47,    61,   -19,   -19,   -47,   -47,    82,    82,   -47,   -47,
     -47,   -47,   -19,    82,    82,   -47,   -47,    40,   -47,    83,
     198,   198,   197,   197,    22,   -47,   220,   197,    89,   -19,
     -47,   -47,   114,   -47,   -19,   -47,   -47,   132,   -47,   -19,
     -19,   -19,   -19,   -47,   -47,   -47,    82,   -47,   -47,   120,
      96,    98,   -24,    12,    48,   124,   197,   197,   -19,   -19,
     -19,   -19,    27,   129,    40,   -47,    40,   -47,    32,    32,
     -47,   -47,   -47,   195,   -19,   -19,   -47,   195,   -47,   100,
      40,    40,    40,    40,   139,   195,   -47,   127,   141,    40,
      40,    26,   195,   143,   -47,   135,   153,   -47,   144,   133,
     165,   148,   -47,   -47,   -47,   175,   164,   -47,   195,   177,
     181,   -47,   168,   -47
  };

  const signed char
   Parser ::yydefact_[] =
  {
       8,     0,     2,     1,     6,    23,    24,    26,    25,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,    14,
      15,     0,     0,     0,    58,    59,    16,    16,    54,    55,
      56,    57,    27,    16,    16,    31,    30,    29,    32,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,    33,
       7,     3,     0,     5,     0,    60,    65,     0,    17,     0,
       0,     0,     0,    18,    19,    20,    16,    22,    21,     0,
      46,    47,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     4,    34,    66,    61,    62,
      63,    64,    28,     0,     0,     0,    45,     0,    43,    44,
      50,    51,    52,    53,     0,     0,    13,     0,     0,    48,
      49,     0,     0,     0,    12,     0,     0,    11,     0,     0,
       0,     0,     9,    10,    35,     0,     0,    38,     0,     0,
       0,    37,     0,    36
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -47,   -47,   -47,   -47,   -46,    -2,   -20,   -47,   -47,   -47,
     -16,   -47,    66,    -4
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,     1,     2,    17,   107,   108,    64,    19,    20,    49,
      44,    45,    32,    46
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      18,    26,    27,    33,    34,     3,    37,    65,    35,    36,
      21,    48,    22,    67,    68,    23,    76,    77,    56,    57,
      51,    52,    53,    24,    25,    38,    72,    73,    66,   114,
     118,    82,     5,     6,     7,     8,     9,    10,    11,    74,
      13,   119,    14,    39,    15,    84,    92,    96,    47,    75,
      86,   111,    76,    77,   104,    88,    89,    90,    91,   113,
      98,    99,    76,    77,    61,    62,   120,    76,    77,    16,
      59,    60,    61,    62,   100,   101,   102,   103,    59,    60,
      61,    62,   130,    87,    78,    79,    80,    81,    50,     4,
     109,   110,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    54,    14,    55,    15,   116,    70,    71,    58,   116,
      69,   116,    59,    60,    61,    62,    83,    85,   116,    59,
      60,    61,    62,    93,    94,    63,    95,    97,   116,    16,
     114,   115,   105,     5,     6,     7,     8,     9,    10,    11,
      76,    13,   112,    14,   117,    15,   114,   121,   122,     5,
       6,     7,     8,     9,    10,    11,   123,    13,   124,    14,
     125,    15,    59,    60,    61,    62,   127,    87,   114,   126,
      16,     5,     6,     7,     8,     9,    10,    11,   128,    13,
     129,    14,   133,    15,   114,   132,    16,     5,     6,     7,
       8,     9,    10,    11,   131,    13,     0,    14,   106,    15,
       0,     5,     6,     7,     8,     9,    10,    11,    16,    13,
       0,    14,     0,    15,     0,     0,    40,    41,    42,     0,
      28,    29,    30,    31,    16,     0,    21,     0,    22,     0,
       0,    43,     0,     0,    28,    29,    30,    31,    16,    24,
      25,    21,     0,    22,     0,     0,    23,     0,     0,     0,
      59,    60,    61,    62,    24,    25,    78,    79,    80,    81
  };

  const short
   Parser ::yycheck_[] =
  {
       2,     5,     6,     7,     8,     0,    10,    27,    43,    44,
      29,    15,    31,    33,    34,    34,    40,    41,    22,    23,
       3,     4,     5,    42,    43,    43,    42,    43,    32,     3,
       4,    47,     6,     7,     8,     9,    10,    11,    12,    43,
      14,    15,    16,    43,    18,    49,    66,    35,    17,    27,
      54,    97,    40,    41,    27,    59,    60,    61,    62,   105,
      76,    77,    40,    41,    32,    33,   112,    40,    41,    43,
      30,    31,    32,    33,    78,    79,    80,    81,    30,    31,
      32,    33,   128,    35,    36,    37,    38,    39,     3,     3,
      94,    95,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    28,    16,    42,    18,   107,    40,    41,    26,   111,
      27,   113,    30,    31,    32,    33,    27,     3,   120,    30,
      31,    32,    33,     3,    28,    43,    28,     3,   130,    43,
       3,     4,     3,     6,     7,     8,     9,    10,    11,    12,
      40,    14,     3,    16,     3,    18,     3,     4,    13,     6,
       7,     8,     9,    10,    11,    12,     3,    14,    14,    16,
      27,    18,    30,    31,    32,    33,    18,    35,     3,     4,
      43,     6,     7,     8,     9,    10,    11,    12,     3,    14,
      16,    16,    14,    18,     3,     4,    43,     6,     7,     8,
       9,    10,    11,    12,    17,    14,    -1,    16,     3,    18,
      -1,     6,     7,     8,     9,    10,    11,    12,    43,    14,
      -1,    16,    -1,    18,    -1,    -1,    19,    20,    21,    -1,
      22,    23,    24,    25,    43,    -1,    29,    -1,    31,    -1,
      -1,    34,    -1,    -1,    22,    23,    24,    25,    43,    42,
      43,    29,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,
      30,    31,    32,    33,    42,    43,    36,    37,    38,    39
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    47,    48,     0,     3,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    16,    18,    43,    49,    51,    53,
      54,    29,    31,    34,    42,    43,    59,    59,    22,    23,
      24,    25,    58,    59,    59,    43,    44,    59,    43,    43,
      19,    20,    21,    34,    56,    57,    59,    17,    59,    55,
       3,     3,     4,     5,    28,    42,    59,    59,    26,    30,
      31,    32,    33,    43,    52,    52,    59,    52,    52,    27,
      58,    58,    56,    56,    59,    27,    40,    41,    36,    37,
      38,    39,    56,    27,    59,     3,    59,    35,    59,    59,
      59,    59,    52,     3,    28,    28,    35,     3,    56,    56,
      59,    59,    59,    59,    27,     3,     3,    50,    51,    59,
      59,    50,     3,    50,     3,     4,    51,     3,     4,    15,
      50,     4,    13,     3,    14,    27,     4,    18,     3,    16,
      50,    17,     4,    14
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    46,    47,    48,    48,    48,    48,    48,    48,    49,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     3,     4,     3,     2,     3,     0,     7,
       3,     2,     2,     1,     1,     1,     0,     1,     1,     3,
       3,     3,     3,     1,     1,     1,     1,     2,     4,     2,
       2,     2,     2,     2,     3,     7,    11,     9,     7,     2,
       0,     1,     2,     3,     3,     3,     2,     2,     4,     4,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     3,     3,     2,     3
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
  "MUR", "VIDE", "PAS", "DEVANT", "DERRIERE", "GAUCHE", "DROITE", "FOIS",
  "DP", "AROBASE", "DOLLAR", "PLUS", "MOINS", "MULT", "DIV", "LPAR",
  "RPAR", "EGAL", "DIFFERENT", "INF", "SUP", "ET", "OU", "NUMBER",
  "VAR_NAME", "COLOR_HEX", "NEG", "$accept", "root", "programme",
  "definition_fonction", "liste_instructions", "instruction", "unite_opt",
  "commande", "structure_controle", "args_appel", "condition",
  "condition_base", "direction", "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    68,    68,    76,    77,    78,    79,    80,    81,    85,
      91,    92,    93,    94,    98,    99,   102,   104,   105,   109,
     110,   111,   112,   115,   116,   117,   118,   120,   124,   132,
     138,   139,   141,   142,   143,   152,   155,   158,   161,   167,
     168,   172,   173,   174,   175,   176,   180,   181,   182,   183,
     185,   186,   187,   188,   192,   193,   194,   195,   199,   200,
     201,   202,   203,   204,   205,   206,   207
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
    };
    // Last valid token kind.
    const int code_max = 300;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1788 "parser/parser.cc"

#line 210 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
