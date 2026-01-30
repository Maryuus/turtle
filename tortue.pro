TEMPLATE = app
TARGET = tortue
QT += widgets

CONFIG += c++17 console
QMAKE_CXXFLAGS += -std=c++17

INCLUDEPATH += $$PWD/expressions $$PWD/parser $$PWD/GUI .

# --- SOURCES (.cc) ---
SOURCES += parser/main.cc \
           parser/driver.cc \
           parser/parser.cc \
           parser/scanner.cc \
           GUI/tortue.cc \
           GUI/jardinHandler.cc \
           GUI/jardinRendering.cc \
           GUI/jardin.cc \
           expressions/capteurs.cc \
           expressions/contexte.cc \
           expressions/constante.cc \
           expressions/variable.cc \
           expressions/expressionBinaire.cc \
           expressions/expressionUnaire.cc \
           expressions/expressionTernaire.cc \
           expressions/conditionBinaire.cc \
           expressions/testBinaire.cc

# --- HEADERS (.hh) ---
HEADERS += parser/scanner.hh \
           parser/driver.hh \
           parser/parser.hh \
           GUI/tortue.hh \
           GUI/jardinHandler.hh \
           GUI/jardinRendering.hh \
           GUI/jardin.hh \
           expressions/instructions.hh \
           expressions/capteurs.hh \
           expressions/types.hh \
           expressions/contexte.hh \
           expressions/expression.hh \
           expressions/expressionBinaire.hh \
           expressions/constante.hh \
           expressions/variable.hh \
           expressions/condition.hh \
           expressions/conditionBinaire.hh \
           expressions/testBinaire.hh \
           expressions/expressionUnaire.hh \
           expressions/expressionTernaire.hh
