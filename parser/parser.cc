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

  case 21: // commande: AVANCE expression unite_opt
#line 114 "parser/parser.yy"
                                  { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[1].value.as < ExpressionPtr > (), TypeMouvement::AVANCE); }
#line 1007 "parser/parser.cc"
    break;

  case 22: // commande: RECULE expression unite_opt
#line 115 "parser/parser.yy"
                                  { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[1].value.as < ExpressionPtr > (), TypeMouvement::RECULE); }
#line 1013 "parser/parser.cc"
    break;

  case 23: // commande: SAUTE expression unite_opt
#line 116 "parser/parser.yy"
                                  { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[1].value.as < ExpressionPtr > (), TypeMouvement::SAUTE); }
#line 1019 "parser/parser.cc"
    break;

  case 24: // commande: TOURNE expression unite_opt
#line 117 "parser/parser.yy"
                                  { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(yystack_[1].value.as < ExpressionPtr > (), TypeMouvement::TOURNE); }
#line 1025 "parser/parser.cc"
    break;

  case 25: // commande: AVANCE unite_special
#line 119 "parser/parser.yy"
                           { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::AVANCE); }
#line 1031 "parser/parser.cc"
    break;

  case 26: // commande: RECULE unite_special
#line 120 "parser/parser.yy"
                           { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::RECULE); }
#line 1037 "parser/parser.cc"
    break;

  case 27: // commande: SAUTE unite_special
#line 121 "parser/parser.yy"
                           { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(1.0), TypeMouvement::SAUTE); }
#line 1043 "parser/parser.cc"
    break;

  case 28: // commande: TOURNE unite_special
#line 122 "parser/parser.yy"
                           { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(90.0), TypeMouvement::TOURNE); }
#line 1049 "parser/parser.cc"
    break;

  case 29: // commande: TOURNE direction
#line 124 "parser/parser.yy"
                        {
        double angle = (yystack_[0].value.as < Direction > () == Direction::GAUCHE) ? -90.0 : 90.0;
        yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(std::make_shared<Constante>(angle), TypeMouvement::TOURNE);
      }
#line 1058 "parser/parser.cc"
    break;

  case 30: // commande: TOURNE direction expression unite_opt
#line 128 "parser/parser.yy"
                                            {
         ExpressionPtr angle = yystack_[1].value.as < ExpressionPtr > ();
         if (yystack_[2].value.as < Direction > () == Direction::GAUCHE) {
             angle = std::make_shared<ExpressionUnaire>(yystack_[1].value.as < ExpressionPtr > (), OperateurUnaire::neg);
         }
         yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeMouvement>(angle, TypeMouvement::TOURNE);
    }
#line 1070 "parser/parser.cc"
    break;

  case 31: // commande: TORTUES expression
#line 136 "parser/parser.yy"
                         { yylhs.value.as < InstructionPtr > () = std::make_shared<Bloc>(); }
#line 1076 "parser/parser.cc"
    break;

  case 32: // commande: COULEUR COLOR_HEX
#line 137 "parser/parser.yy"
                        { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeCouleur>(yystack_[0].value.as < std::vector<double> > ()[0], yystack_[0].value.as < std::vector<double> > ()[1], yystack_[0].value.as < std::vector<double> > ()[2]); }
#line 1082 "parser/parser.cc"
    break;

  case 33: // commande: COULEUR VAR_NAME
#line 138 "parser/parser.yy"
                       { yylhs.value.as < InstructionPtr > () = std::make_shared<CommandeCouleur>(255, 0, 0); }
#line 1088 "parser/parser.cc"
    break;

  case 34: // commande: JARDIN VAR_NAME
#line 140 "parser/parser.yy"
                        { driver.nouveauJardin(yystack_[0].value.as < std::string > ()); yylhs.value.as < InstructionPtr > () = std::make_shared<Bloc>(); }
#line 1094 "parser/parser.cc"
    break;

  case 35: // commande: VAR_NAME args_appel
#line 141 "parser/parser.yy"
                          { yylhs.value.as < InstructionPtr > () = std::make_shared<AppelFonction>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ExpressionPtr> > ()); }
#line 1100 "parser/parser.cc"
    break;

  case 36: // commande: commande AROBASE expression
#line 142 "parser/parser.yy"
                                  {
        Bloc* b = new Bloc();
        b->ajouter(std::make_shared<CommandeSelectionTortue>(yystack_[0].value.as < ExpressionPtr > ()));
        b->ajouter(yystack_[2].value.as < InstructionPtr > ());
        yylhs.value.as < InstructionPtr > () = std::shared_ptr<Instruction>(b);
    }
#line 1111 "parser/parser.cc"
    break;

  case 37: // structure_controle: SI condition DP NL liste_instructions END SI
#line 151 "parser/parser.yy"
                                                   {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleSi>(yystack_[5].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1119 "parser/parser.cc"
    break;

  case 38: // structure_controle: SI condition DP NL liste_instructions SINON DP NL liste_instructions END SI
#line 154 "parser/parser.yy"
                                                                                  {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleSi>(yystack_[9].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[6].value.as < Bloc* > ()), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1127 "parser/parser.cc"
    break;

  case 39: // structure_controle: TANT QUE condition DP NL liste_instructions END TANT QUE
#line 157 "parser/parser.yy"
                                                               {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleTantQue>(yystack_[6].value.as < ConditionPtr > (), std::shared_ptr<Instruction>(yystack_[3].value.as < Bloc* > ()));
      }
#line 1135 "parser/parser.cc"
    break;

  case 40: // structure_controle: REPETE expression DP NL liste_instructions END REPETE
#line 160 "parser/parser.yy"
                                                            {
          yylhs.value.as < InstructionPtr > () = std::make_shared<ControleRepete>(yystack_[5].value.as < ExpressionPtr > (), std::shared_ptr<Instruction>(yystack_[2].value.as < Bloc* > ()));
      }
#line 1143 "parser/parser.cc"
    break;

  case 41: // args_appel: args_appel expression
#line 166 "parser/parser.yy"
                            { yylhs.value.as < std::vector<ExpressionPtr> > () = yystack_[1].value.as < std::vector<ExpressionPtr> > (); yylhs.value.as < std::vector<ExpressionPtr> > ().push_back(yystack_[0].value.as < ExpressionPtr > ()); }
#line 1149 "parser/parser.cc"
    break;

  case 42: // args_appel: %empty
#line 167 "parser/parser.yy"
                 { }
#line 1155 "parser/parser.cc"
    break;

  case 43: // condition: condition_base
#line 171 "parser/parser.yy"
                     { yylhs.value.as < ConditionPtr > () = yystack_[0].value.as < ConditionPtr > (); }
#line 1161 "parser/parser.cc"
    break;

  case 44: // condition: PAS condition_base
#line 172 "parser/parser.yy"
                         { yylhs.value.as < ConditionPtr > () = yystack_[0].value.as < ConditionPtr > (); }
#line 1167 "parser/parser.cc"
    break;

  case 45: // condition: condition ET condition
#line 173 "parser/parser.yy"
                             { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionBinaire>(yystack_[2].value.as < ConditionPtr > (), yystack_[0].value.as < ConditionPtr > (), OperateurBinaireBool::et); }
#line 1173 "parser/parser.cc"
    break;

  case 46: // condition: condition OU condition
#line 174 "parser/parser.yy"
                             { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionBinaire>(yystack_[2].value.as < ConditionPtr > (), yystack_[0].value.as < ConditionPtr > (), OperateurBinaireBool::ou); }
#line 1179 "parser/parser.cc"
    break;

  case 47: // condition: LPAR condition RPAR
#line 175 "parser/parser.yy"
                          { yylhs.value.as < ConditionPtr > () = yystack_[1].value.as < ConditionPtr > (); }
#line 1185 "parser/parser.cc"
    break;

  case 48: // condition_base: MUR direction
#line 180 "parser/parser.yy"
                    { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, yystack_[0].value.as < Direction > ()); }
#line 1191 "parser/parser.cc"
    break;

  case 49: // condition_base: VIDE direction
#line 181 "parser/parser.yy"
                     { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, yystack_[0].value.as < Direction > ()); }
#line 1197 "parser/parser.cc"
    break;

  case 50: // condition_base: PAS MUR direction
#line 182 "parser/parser.yy"
                        { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, yystack_[0].value.as < Direction > ()); }
#line 1203 "parser/parser.cc"
    break;

  case 51: // condition_base: PAS VIDE direction
#line 183 "parser/parser.yy"
                         { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, yystack_[0].value.as < Direction > ()); }
#line 1209 "parser/parser.cc"
    break;

  case 52: // condition_base: MUR direction AROBASE expression
#line 185 "parser/parser.yy"
                                       { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, yystack_[2].value.as < Direction > (), yystack_[0].value.as < ExpressionPtr > ()); }
#line 1215 "parser/parser.cc"
    break;

  case 53: // condition_base: VIDE direction AROBASE expression
#line 186 "parser/parser.yy"
                                        { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, yystack_[2].value.as < Direction > (), yystack_[0].value.as < ExpressionPtr > ()); }
#line 1221 "parser/parser.cc"
    break;

  case 54: // condition_base: PAS MUR direction AROBASE expression
#line 187 "parser/parser.yy"
                                           { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::VIDE, yystack_[2].value.as < Direction > (), yystack_[0].value.as < ExpressionPtr > ()); }
#line 1227 "parser/parser.cc"
    break;

  case 55: // condition_base: PAS VIDE direction AROBASE expression
#line 188 "parser/parser.yy"
                                            { yylhs.value.as < ConditionPtr > () = std::make_shared<ConditionCapteur>(TypeCapteur::MUR, yystack_[2].value.as < Direction > (), yystack_[0].value.as < ExpressionPtr > ()); }
#line 1233 "parser/parser.cc"
    break;

  case 56: // condition_base: expression EGAL expression
#line 190 "parser/parser.yy"
                                 { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::egal); }
#line 1239 "parser/parser.cc"
    break;

  case 57: // condition_base: expression DIFFERENT expression
#line 191 "parser/parser.yy"
                                      { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::different); }
#line 1245 "parser/parser.cc"
    break;

  case 58: // condition_base: expression INF expression
#line 192 "parser/parser.yy"
                                { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::pluspetit); }
#line 1251 "parser/parser.cc"
    break;

  case 59: // condition_base: expression SUP expression
#line 193 "parser/parser.yy"
                                { yylhs.value.as < ConditionPtr > () = std::make_shared<TestBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBool::plusgrand); }
#line 1257 "parser/parser.cc"
    break;

  case 60: // direction: DEVANT
#line 197 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::DEVANT; }
#line 1263 "parser/parser.cc"
    break;

  case 61: // direction: DERRIERE
#line 198 "parser/parser.yy"
               { yylhs.value.as < Direction > () = Direction::DERRIERE; }
#line 1269 "parser/parser.cc"
    break;

  case 62: // direction: GAUCHE
#line 199 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::GAUCHE; }
#line 1275 "parser/parser.cc"
    break;

  case 63: // direction: DROITE
#line 200 "parser/parser.yy"
             { yylhs.value.as < Direction > () = Direction::DROITE; }
#line 1281 "parser/parser.cc"
    break;

  case 64: // expression: NUMBER
#line 204 "parser/parser.yy"
             { yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < double > ()); }
#line 1287 "parser/parser.cc"
    break;

  case 65: // expression: VAR_NAME
#line 205 "parser/parser.yy"
               { yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ()); }
#line 1293 "parser/parser.cc"
    break;

  case 66: // expression: DOLLAR NUMBER
#line 206 "parser/parser.yy"
                    { yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>("$" + std::to_string((int)yystack_[0].value.as < double > ())); }
#line 1299 "parser/parser.cc"
    break;

  case 67: // expression: expression PLUS expression
#line 207 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::plus); }
#line 1305 "parser/parser.cc"
    break;

  case 68: // expression: expression MOINS expression
#line 208 "parser/parser.yy"
                                  { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::moins); }
#line 1311 "parser/parser.cc"
    break;

  case 69: // expression: expression MULT expression
#line 209 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::multiplie); }
#line 1317 "parser/parser.cc"
    break;

  case 70: // expression: expression DIV expression
#line 210 "parser/parser.yy"
                                { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::divise); }
#line 1323 "parser/parser.cc"
    break;

  case 71: // expression: MOINS expression
#line 211 "parser/parser.yy"
                                 { yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (), OperateurUnaire::neg); }
#line 1329 "parser/parser.cc"
    break;

  case 72: // expression: LPAR expression RPAR
#line 212 "parser/parser.yy"
                           { yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > (); }
#line 1335 "parser/parser.cc"
    break;


#line 1339 "parser/parser.cc"

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









  const signed char  Parser ::yypact_ninf_ = -105;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
    -105,    10,   145,  -105,  -105,     1,     1,   259,     1,     9,
      88,   -30,   -24,    45,    11,    88,  -105,    23,    67,     3,
    -105,  -105,    -8,    88,    88,  -105,  -105,  -105,     6,  -105,
       6,  -105,  -105,  -105,  -105,  -105,    88,     6,  -105,     6,
    -105,  -105,   188,  -105,    15,   249,   249,   237,    45,    19,
    -105,   105,    45,   152,    88,  -105,  -105,    44,  -105,    88,
    -105,  -105,   115,  -105,    88,    88,    88,    88,  -105,  -105,
    -105,     6,  -105,  -105,    46,    29,    47,   249,   249,    57,
    -105,   -25,    59,    76,    45,    45,    88,    88,    88,    88,
      41,    89,   188,  -105,   188,  -105,   223,   223,  -105,  -105,
    -105,   235,    88,    88,    75,    83,   249,   249,  -105,   235,
    -105,    87,   188,   188,   188,   188,   111,   235,  -105,   161,
     125,   188,   188,    88,    88,   104,   133,    97,   235,   182,
    -105,   149,   163,  -105,   188,   188,    88,    88,   160,   150,
     198,   162,  -105,  -105,   188,   188,  -105,   192,   181,  -105,
     235,   194,   219,  -105,   185,  -105
  };

  const signed char
   Parser ::yydefact_[] =
  {
       8,     0,     2,     1,     6,    19,    19,    19,    19,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,    14,
      15,    20,     0,     0,     0,    64,    65,    25,    16,    26,
      16,    60,    61,    62,    63,    28,    29,    16,    27,    16,
      33,    32,    31,    34,     0,     0,     0,     0,     0,     0,
      43,     0,     0,     0,    35,     7,     3,     0,     5,     0,
      66,    71,     0,    17,     0,     0,     0,     0,    18,    21,
      22,    16,    24,    23,     0,    48,    49,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     4,    36,    72,    67,    68,    69,    70,
      30,     0,     0,     0,    48,    49,     0,     0,    47,     0,
      45,    46,    56,    57,    58,    59,     0,     0,    13,     0,
       0,    52,    53,     0,     0,    50,    51,     0,     0,     0,
      12,     0,     0,    11,    52,    53,     0,     0,     0,     0,
       0,     0,     9,    10,    54,    55,    37,     0,     0,    40,
       0,     0,     0,    39,     0,    38
  };

  const short
   Parser ::yypgoto_[] =
  {
    -105,  -105,  -105,  -105,  -104,    -2,   -14,   116,  -105,  -105,
    -105,   -31,   166,   -38,    -4
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,     1,     2,    17,   119,   120,    69,    27,    19,    20,
      54,    49,    50,    36,    51
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      18,    28,    30,    37,    39,   127,    42,    75,    76,   108,
       3,    53,    43,   129,    84,    85,    70,    81,    44,    61,
      62,    90,    21,    72,   140,    73,    55,    63,    52,    22,
      59,    23,    71,    60,    24,    64,    65,    66,    67,   104,
     105,    74,    25,    26,    82,    83,   152,    93,    68,   101,
      92,    40,    41,   110,   111,    94,   102,   100,    84,    85,
      96,    97,    98,    99,    45,    46,    47,   116,   125,   126,
      56,    57,    58,    22,   103,    23,   106,   107,    48,   109,
      84,    85,   112,   113,   114,   115,    25,    26,    64,    65,
      66,    67,   117,    95,    86,    87,    88,    89,   121,   122,
     130,   138,   123,     5,     6,     7,     8,     9,    10,    11,
     124,    13,   139,    14,   128,    15,    22,   132,    23,   134,
     135,    24,    29,    35,    38,   132,    84,   132,   133,    25,
      26,   136,   144,   145,    64,    65,    66,    67,   132,    16,
      86,    87,    88,    89,    64,    65,    66,    67,     4,    95,
     132,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     137,    14,   142,    15,   130,   131,   143,     5,     6,     7,
       8,     9,    10,    11,   146,    13,   147,    14,    91,    15,
     149,    64,    65,    66,    67,   130,   141,    16,     5,     6,
       7,     8,     9,    10,    11,   150,    13,   151,    14,   155,
      15,   130,   148,    16,     5,     6,     7,     8,     9,    10,
      11,   153,    13,    80,    14,     0,    15,    64,    65,    66,
      67,     0,   130,   154,    16,     5,     6,     7,     8,     9,
      10,    11,     0,    13,     0,    14,     0,    15,   118,     0,
      16,     5,     6,     7,     8,     9,    10,    11,     0,    13,
       0,    14,     0,    15,    66,    67,    77,    78,    79,     0,
       0,    16,     0,     0,     0,    22,     0,    23,     0,     0,
      24,    31,    32,    33,    34,     0,     0,    16,    25,    26,
      21,    31,    32,    33,    34,     0,     0,    22,     0,    23,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
      25,    26
  };

  const short
   Parser ::yycheck_[] =
  {
       2,     5,     6,     7,     8,   109,    10,    45,    46,    34,
       0,    15,    42,   117,    39,    40,    30,    48,    42,    23,
      24,    52,    21,    37,   128,    39,     3,    21,    17,    28,
      27,    30,    36,    41,    33,    29,    30,    31,    32,    77,
      78,    26,    41,    42,    48,    26,   150,     3,    42,     3,
      54,    42,    43,    84,    85,    59,    27,    71,    39,    40,
      64,    65,    66,    67,    19,    20,    21,    26,   106,   107,
       3,     4,     5,    28,    27,    30,    19,    20,    33,     3,
      39,    40,    86,    87,    88,    89,    41,    42,    29,    30,
      31,    32,     3,    34,    35,    36,    37,    38,   102,   103,
       3,     4,    27,     6,     7,     8,     9,    10,    11,    12,
      27,    14,    15,    16,     3,    18,    28,   119,    30,   123,
     124,    33,     6,     7,     8,   127,    39,   129,     3,    41,
      42,    27,   136,   137,    29,    30,    31,    32,   140,    42,
      35,    36,    37,    38,    29,    30,    31,    32,     3,    34,
     152,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      27,    16,    13,    18,     3,     4,     3,     6,     7,     8,
       9,    10,    11,    12,    14,    14,    26,    16,    26,    18,
      18,    29,    30,    31,    32,     3,     4,    42,     6,     7,
       8,     9,    10,    11,    12,     3,    14,    16,    16,    14,
      18,     3,     4,    42,     6,     7,     8,     9,    10,    11,
      12,    17,    14,    47,    16,    -1,    18,    29,    30,    31,
      32,    -1,     3,     4,    42,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    16,    -1,    18,     3,    -1,
      42,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    16,    -1,    18,    31,    32,    19,    20,    21,    -1,
      -1,    42,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,
      33,    22,    23,    24,    25,    -1,    -1,    42,    41,    42,
      21,    22,    23,    24,    25,    -1,    -1,    28,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    46,    47,     0,     3,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    16,    18,    42,    48,    50,    53,
      54,    21,    28,    30,    33,    41,    42,    52,    59,    52,
      59,    22,    23,    24,    25,    52,    58,    59,    52,    59,
      42,    43,    59,    42,    42,    19,    20,    21,    33,    56,
      57,    59,    17,    59,    55,     3,     3,     4,     5,    27,
      41,    59,    59,    21,    29,    30,    31,    32,    42,    51,
      51,    59,    51,    51,    26,    58,    58,    19,    20,    21,
      57,    56,    59,    26,    39,    40,    35,    36,    37,    38,
      56,    26,    59,     3,    59,    34,    59,    59,    59,    59,
      51,     3,    27,    27,    58,    58,    19,    20,    34,     3,
      56,    56,    59,    59,    59,    59,    26,     3,     3,    49,
      50,    59,    59,    27,    27,    58,    58,    49,     3,    49,
       3,     4,    50,     3,    59,    59,    27,    27,     4,    15,
      49,     4,    13,     3,    59,    59,    14,    26,     4,    18,
       3,    16,    49,    17,     4,    14
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    45,    46,    47,    47,    47,    47,    47,    47,    48,
      49,    49,    49,    49,    50,    50,    51,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     3,     4,     3,     2,     3,     0,     7,
       3,     2,     2,     1,     1,     1,     0,     1,     1,     0,
       1,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       4,     2,     2,     2,     2,     2,     3,     7,    11,     9,
       7,     2,     0,     1,     2,     3,     3,     3,     2,     2,
       3,     3,     4,     4,     5,     5,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     2,     3
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
  "definition_fonction", "liste_instructions", "instruction", "unite_opt",
  "unite_special", "commande", "structure_controle", "args_appel",
  "condition", "condition_base", "direction", "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    68,    68,    76,    77,    78,    79,    80,    81,    85,
      91,    92,    93,    94,    98,    99,   102,   104,   105,   108,
     110,   114,   115,   116,   117,   119,   120,   121,   122,   124,
     128,   136,   137,   138,   140,   141,   142,   151,   154,   157,
     160,   166,   167,   171,   172,   173,   174,   175,   180,   181,
     182,   183,   185,   186,   187,   188,   190,   191,   192,   193,
     197,   198,   199,   200,   204,   205,   206,   207,   208,   209,
     210,   211,   212
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

} // yy
#line 1825 "parser/parser.cc"

#line 215 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
