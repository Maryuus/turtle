import re
import sys

# Règles identiques au dernier scanner.ll
rules = [
    ('COMMENT',     r'(--|//|%|#).*'),
    ('NL',          r'\n'),
    ('WS',          r'[ \t]+'),
    ('JARDIN',      r'jardin\b'),
    ('STR_DOUBLE',  r'"[^"\n]*"'),
    ('STR_SINGLE',  r"'[^'\n]*'"),
    ('VAR_NAME',    r'[a-zA-Z_][a-zA-Z0-9_\./-]*'),
    ('NUMBER',      r'[0-9]+(\.[0-9]+)?'),
    ('OTHER',       r'.'),
]

def analyze(filename):
    with open(filename, 'r') as f:
        content = f.read()

    print(f"Analyse de : {content.strip()}")
    pos = 0
    line = 1

    while pos < len(content):
        match = None
        for name, pattern in rules:
            regex = re.compile(pattern)
            m = regex.match(content, pos)
            if m:
                match = m
                val = m.group(0)
                if name == 'NL':
                    line += 1
                elif name != 'WS' and name != 'COMMENT':
                    # On affiche le token trouvé
                    print(f"Ligne {line}: Token [{name}] = '{val}'")

                pos = m.end()
                break

        if not match:
            print(f"ERREUR: Caractère bloquant à la position {pos} : '{content[pos]}'")
            pos += 1

if __name__ == "__main__":
    analyze(sys.argv[1])
