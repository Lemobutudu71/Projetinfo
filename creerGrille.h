#ifndef Grille_h
    #define Grille_h

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include "couleur.h"
    #define ROBOTS 4
    #define CIBLES 18


void initialiserGrille(char ***grille, int hauteur, int largeur);
void initialiserMurInterdit(int ***MurInterdit, int hauteur, int largeur);
void placerCibles(char **grille, int hauteur, int largeur, int CordCibles[CIBLES][2], int MurH_Cibles[CIBLES][2], int MurV_Cibles[CIBLES][2]);
void placerRobots(char **grille, int hauteur, int largeur);
void afficherGrille(char **grille, int hauteur, int largeur, int MurRandH[4],
int MurRandV[4],int MurH_Cibles[CIBLES][2], int MurV_Cibles[CIBLES][2]);
int estPositionValide(char **grille, int hauteur, int largeur, int ligne, int col);

    
#endif
