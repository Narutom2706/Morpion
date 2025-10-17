#include <stdio.h>
#include "void.h"

int main() {
    char tableau[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    Tableau(tableau);

    int ligne, colonne;
    printf("Entrez la ligne (0-2) : ");
    scanf("%d", &ligne);
    printf("Entrez la colonne (0-2) : ");
    scanf("%d", &colonne);

    Jouer(tableau, ligne, colonne, 'X');

    Tableau(tableau);

    return 0;
}

