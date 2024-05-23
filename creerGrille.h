#ifndef Grille_h
    #define Grille_h

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include "couleur.h"
    #define ROBOTS 4
    #define CIBLES 18

typedef struct {
    int ligne;
    int col;
}MurInterdit;

void initialiserGrille(char ***grille, int hauteur, int largeur);
void initialiserMurInterdit(int ***MurInterdit, int hauteur, int largeur);
void placerCibles(char **grille, int hauteur, int largeur, int CordCibles[][2], int MurH_Cibles[][2], int MurV_Cibles[][2], MurInterdit **murInterdits, int *nombreMursInterdits);
void placerRobots(char **grille, int hauteur, int largeur, MurInterdit *murInterdits, int nombreMursInterdits); 
void afficherGrille(char **grille, int hauteur, int largeur, int MurRandH[4],
int MurRandV[4],int MurH_Cibles[CIBLES][2], int MurV_Cibles[CIBLES][2]);
int estPositionValide(char **grille, int hauteur, int largeur, int ligne, int col, MurInterdit *murInterdits, int nombreMursInterdits);
void murExterieur(int hauteur, int largeur, MurInterdit **murInterdits, int *nombreMursInterdits, int MurRandH[4], int MurRandV[4]);
    
#endif
