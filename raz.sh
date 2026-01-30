#!/bin/bash

echo "=== 1. NETTOYAGE BRUTAL ==="
# On supprime les fichiers générés pour être sûr qu'ils soient recréés
rm -f parser/parser.cc parser/parser.hh parser/scanner.cc
rm -f parser/*.o

echo "=== 2. GÉNÉRATION DU PARSER (Bison) ==="
# C'est l'étape que tu avais oubliée !
bison -o parser/parser.cc --defines=parser/parser.hh parser/parser.yy

echo "=== 3. GÉNÉRATION DU SCANNER (Flex) ==="
flex -o parser/scanner.cc parser/scanner.ll

echo "=== 4. COMPILATION (Make) ==="
make

echo "=== 5. TEST ==="
# On teste avec l'exemple 4 qui posait problème
./tortue exemples/exemple4.txt
