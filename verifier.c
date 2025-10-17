#include <stdbool.h>
#include "verifier.h"

char Verifier(char tableau[3][3]) {
    // --- Lignes ---
    for (int i = 0; i < 3; i++) {
        if (tableau[i][0] != ' ' && tableau[i][0] == tableau[i][1] && tableau[i][1] == tableau[i][2])
            return tableau[i][0];
    }

    // --- Colonnes ---
    for (int j = 0; j < 3; j++) {
        if (tableau[0][j] != ' ' && tableau[0][j] == tableau[1][j] && tableau[1][j] == tableau[2][j])
            return tableau[0][j];
    }

    // --- Diagonales ---
    if (tableau[0][0] != ' ' && tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2])
        return tableau[0][0];
    if (tableau[0][2] != ' ' && tableau[0][2] == tableau[1][1] && tableau[1][1] == tableau[2][0])
        return tableau[0][2];

    // --- Vérifie égalité ---
    bool plein = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tableau[i][j] == ' ')
                plein = false;
        }
    }

    if (plein)
        return 'E'; // Égalité

    return ' '; // Partie non terminée
}
