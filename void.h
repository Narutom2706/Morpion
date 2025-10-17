#ifndef VOID_H
#define VOID_H

#include <stdbool.h>

void Tableau(char tableau[3][3]);
bool Jouer(char tableau[3][3], int ligne, int colonne, char symbole);
void IA(char tableau[3][3]);

#endif
