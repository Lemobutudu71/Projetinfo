
#ifndef Interface_h
#define Interface_h

#include "couleur.h"

#include "creerGrille.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  int ligne;
  int col;
  char signe;
} Robot;

typedef struct {
  int ligne;
  int col;
  char signe;
} Cible;

void NombreJoueurs(int *nb_joueur);
void ChoisirRobotCible(char **grille, int hauteur, int largeur, Robot *robot,
                       Cible *cible);
void chronometrer(int duree_chrono);
int choixdifficulte(int niveau_difficulte);
void choix_joueur(int **nmbMouv, int m_bJoueur, char **grille, Robot *robot,
          Cible *cible, int *player);
int MIN(int My_array[], int len);

void deplacement(Robot *robot, Cible *cible, int direction,
                      MurInterdit *murInterdits, int nombreMursInterdits, char ** grille, int hauteur, int largeur);
int choix_direction(int direction);
 void JoueurTour(char **grille, int hauteur, int largeur, Robot *robot, Cible *cible, MurInterdit *mursInterdits, int nombreMursInterdits, int *nmbMouv, int joueurActuel, int *pointsJoueurs, int **MurRandH,
 int **MurRandV, int MurH_Cibles[CIBLES][2],
 int MurV_Cibles[CIBLES][2]);

void Points(int *pointsJoueurs, int nb_joueurs, int joueurActuel, int nb_deplacements, int nb_deplacements_effectues, int robotAtteintCible);

void AfficherGagnant(int *pointsJoueurs, int nb_joueurs);
#endif



