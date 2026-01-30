#!/bin/bash

echo "=== NETTOYAGE DU FICHIER SOURCE OBSOLÈTE ==="

# On vide le fichier jardinRendering.cc car l'interface est maintenant virtuelle pure
# (Il ne doit plus contenir de code, mais le fichier doit exister pour le Makefile)
echo '#include "jardinRendering.hh"' > GUI/jardinRendering.cc

echo "=== RECOMPILATION PROPRE ==="
rm -f jardinRendering.o jardin.o main.o
make

echo "=== TEST ==="
./tortue test_visuel.txt
