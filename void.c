#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
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

// Retourne true si le coup est valide, false sinon
bool Jouer(char tableau[3][3], int colonne, int ligne, char symbole) {
    if (tableau[ligne][colonne] == ' ') {
        tableau[ligne][colonne] = symbole;
        return true;
    } else {
        printf("Case déjà prise !\n");
        return false;
    }
}

void IA(char tableau[3][3]) {
    int ligne, colonne;
    srand(time(NULL));

    do {
        colonne = rand() % 3;
        ligne = rand() % 3;
    } while (tableau[ligne][colonne] != ' ');

    tableau[ligne][colonne] = 'O';
    printf("L'IA joue en colonne %d, ligne %d\n", colonne + 1, ligne + 1);
}

