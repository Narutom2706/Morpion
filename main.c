#include <stdio.h>
#include "void.h"

int main() {
    char tableau[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int ligne, colonne;
    char continuer = 'o';

    printf("=== Jeu du Morpion ===\n");
    Tableau(tableau);

    while (continuer == 'o') { // ? condition temporaire 
        printf("Votre tour (X)\n");
        printf("Entrez la ligne (1-3) : ");
        scanf("%d", &ligne);
        printf("Entrez la colonne (1-3) : ");
        scanf("%d", &colonne);

        if (ligne < 1 || ligne > 3 || colonne < 1 || colonne > 3) {
            printf("Coordonnée invalide\n");
            continue;
        }

        Jouer(tableau, ligne - 1, colonne - 1, 'X'); // j'ai ajouté -1 pour permettre de passé de (0-2) à (1-3) car je trouve ça plus ludique pour le joueur
        Tableau(tableau);

        printf("Tour de l’IA...\n");
        IA(tableau);
        Tableau(tableau);

        printf("Voulez vous continuer ? (o/n) : "); // ! ne verifie pas si on a gagné
        scanf(" %c", &continuer);
    }

    return 0;
}