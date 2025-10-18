#ifndef VOID_H
#define VOID_H

#include <stdbool.h>

void Tableau(char tableau[3][3]);
bool Jouer(char tableau[3][3], int colonne, int ligne, char symbole);
void IA(char tableau[3][3]);
bool TableauPlein(char tableau[3][3]);
bool Verifier(char tableau[3][3], char symbole); 

#endif
