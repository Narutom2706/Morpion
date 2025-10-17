#include <stdio.h>

void Tableau(char tableau[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) { // Parcourt chaque ligne
        printf(" %c | %c | %c ", tableau[i][0], tableau[i][1], tableau[i][2]); // Affiche les éléments de la ligne
        if (i < 2)
            printf("\n-----------\n");
    }
    printf("\n\n");
}

int main() {
    char tableau[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    Tableau(tableau);

    return 0;
}
