#!/bin/bash
OUTPUT="PROJET_COMPLET.txt"
echo "GÉNÉRATION DU FICHIER CONCATÉNÉ LE $(date)" > "$OUTPUT"
find . -maxdepth 3 -not -path '*/.*' | sort >> "$OUTPUT"
echo -e "\n\n" >> "$OUTPUT"
find . -type f \( -name "*.pro" -o -name "*.hh" -o -name "*.h" -o -name "*.cc" -o -name "*.cpp" -o -name "*.ll" -o -name "*.yy" -o -name "*.txt" \) \
    -not -name "$OUTPUT" \
    -not -path "*/build/*" \
    -not -path "*/.git/*" \
    | sort | while read -r file; do
    echo "==================================================" >> "$OUTPUT"
    echo "FICHIER : $file" >> "$OUTPUT"
    echo "==================================================" >> "$OUTPUT"
    cat "$file" >> "$OUTPUT"
    echo -e "\n\n" >> "$OUTPUT"
done
