#include <stdio.h>
#include "void.h"

void Tableau(char tableau[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", tableau[i][0], tableau[i][1], tableau[i][2]);
        if (i < 2)
            printf("\n-----------\n");
    }
    printf("\n\n");
}

void Jouer(char tableau[3][3], int ligne, int colonne, char symbole) {
    if (tableau[ligne][colonne] == ' ') {
        tableau[ligne][colonne] = symbole;
    } else {
        printf("Case deja prise\n");
    }
}
