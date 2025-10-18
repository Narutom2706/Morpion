#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "void.h"

void Tableau(char tableau[3][3]) { // Affiche le tableau
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
        printf("Case déjà prise\n");
        return false;
    }
}

// Vérifie s’il reste au moins une case libre
bool TableauPlein(char tableau[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tableau[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Vérifie si un joueur a gagné (j'ai fait que une seul fonction car au debut j'en avait fait deux, une pour chaque joueur mais ça bugait)
bool Verifier(char tableau[3][3], char symbole) {
    for (int i = 0; i < 3; i++) {
        if (tableau[i][0] == symbole && tableau[i][1] == symbole && tableau[i][2] == symbole)
            return true;
        if (tableau[0][i] == symbole && tableau[1][i] == symbole && tableau[2][i] == symbole)
            return true;
    }
    if (tableau[0][0] == symbole && tableau[1][1] == symbole && tableau[2][2] == symbole)
        return true;
    if (tableau[0][2] == symbole && tableau[1][1] == symbole && tableau[2][0] == symbole)
        return true;

    return false;
}

void IA(char tableau[3][3]) {
    // Vérifie d’abord s’il reste des cases libres car sinont l'ia va boucler infiniement (ce qui est pas tres fun)
    if (TableauPlein(tableau)) {
        printf("Égalité\n");
        exit(0); 
    }

    int ligne, colonne;
    srand(time(NULL));

    do { // Pour choisir une case libre aléatoire
        colonne = rand() % 3;
        ligne = rand() % 3;
    } while (tableau[ligne][colonne] != ' ');

    tableau[ligne][colonne] = 'O';
    printf("L'IA joue en colonne %d, ligne %d\n", colonne + 1, ligne + 1); // j'ai ajouté +1 pour retablir les vrai valeurs et non pas (0-2)
}
