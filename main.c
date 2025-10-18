#include <stdio.h>
#include <stdlib.h>
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

    while (continuer == 'o') { 
        bool coupValide = false;
        while (!coupValide) { //on continue la tant que le coup est valide
            printf("Votre tour (X)\n");
            printf("Entrez la colonne (1-3) : ");
            scanf("%d", &colonne);
            printf("Entrez la ligne (1-3) : ");
            scanf("%d", &ligne);
            if (ligne < 1 || ligne > 3 || colonne < 1 || colonne > 3) { // on verifie que l'uilisateur arrive a lire les consignes (mdr)
                printf("Coordonnée invalide\n");
                continue;
            }

            coupValide = Jouer(tableau, colonne - 1, ligne - 1, 'X'); // j'ai ajouté -1 pour permettre de passé de (0-2) à (1-3) car je trouve ça plus ludique pour le joueur
        }

        Tableau(tableau);

        // Vérifie victoire du joueur
        if (Verifier(tableau, 'X')) {
            printf("Tu as gagné \n");
            break;
        }

        // Vérifie égalité avant que l'IA ne joue (car si on verifie apres, ça fait une boucle infini)
        if (TableauPlein(tableau)) {
            printf("Égalité \n");
            break;
        }

        IA(tableau);
        Tableau(tableau);

        // Vérifie victoire de l'IA
        if (Verifier(tableau, 'O')) {
            printf("L'IA a gagné,tu as perdu et sachant que l'ia joue de maniere aleatoire t'es vraiment nul\n");
            break;
        }

        // Vérifie égalité après le tour de l'IA
        if (TableauPlein(tableau)) {
            printf("Égalité \n");
            break;
        }

        printf("Voulez-vous continuer ? (o/n) : "); 
        scanf(" %c", &continuer);
    }
    return 0;
}
