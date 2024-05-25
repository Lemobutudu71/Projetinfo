#ifndef Grille_h
#define Grille_h

#include "couleur.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROBOTS 4
#define CIBLES 18

typedef struct {
  int ligne;
  int col;
} MurInterdit;

void clearInputBuffer();

void initialiserGrille(char ***grille, int hauteur, int largeur);

void placerCibles(char **grille, int hauteur, int largeur, int CordCibles[][2],
                  int MurH_Cibles[][2], int MurV_Cibles[][2],
                  MurInterdit **murInterdits, int *nombreMursInterdits);

void placerRobots(char **grille, int hauteur, int largeur,
                  MurInterdit *murInterdits, int nombreMursInterdits);

void afficherGrille(char **grille, int hauteur, int largeur, int **MurRandH,
                    int **MurRandV, int MurH_Cibles[CIBLES][2],
                    int MurV_Cibles[CIBLES][2]);

int estPositionValide(char **grille, int hauteur, int largeur, int ligne,
                      int col);

void murExterieur(int hauteur, int largeur, MurInterdit **murInterdits,
                  int *nombreMursInterdits, int **MurRandH, int **MurRandV);

#endif
