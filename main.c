#include "creerGrille.h"
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main() {

  MurInterdit *murInterdits = NULL;
  int largeur, hauteur;
  char **grille;

  int CordCibles[CIBLES][2];
  int MurH_Cibles[CIBLES][2];
  int MurV_Cibles[CIBLES][2];
  int nombreMursInterdits = 0;

  int *MurRandH = NULL;
  int *MurRandV = NULL;

  srand(time(NULL));
  hauteur = rand() % 6 + 15; // Génère un nombre entre 15 et 20
  largeur = rand() % 6 + 15; // Génère un nombre entre 15 et 20
  printf("Le tableau contient %d lignes et %d colonnes\n", hauteur, largeur);

  MurRandH = (int *)malloc(4 * sizeof(int)); // alloc dynamique
  MurRandV = (int *)malloc(4 * sizeof(int)); // alloc dynamique

  for (int i = 0; i < 4; i++) {
    do {
      MurRandH[i] = rand() % (hauteur - 2) + 1;
      MurRandV[i] = rand() % (largeur - 2) + 1;
      int unique = 1;
      for (int j = 0; j < i; j++) {
        if (MurRandH[j] == MurRandH[i] || MurRandV[j] == MurRandV[i]) {
          unique = 0;
          break;
        }
      }
      if (unique) {
        break;
      }
    } while (1);

    printf("MurRandH[%d] = %d\n", i, MurRandH[i]);
    printf("MurRandV[%d] = %d\n", i, MurRandV[i]);
  }

  initialiserGrille(&grille, hauteur, largeur);

  placerCibles(grille, hauteur, largeur, CordCibles, MurH_Cibles, MurV_Cibles,
               &murInterdits, &nombreMursInterdits);
  placerRobots(grille, hauteur, largeur, murInterdits, nombreMursInterdits);

  // Check for NULL pointers before dereferencing
  if (murInterdits != NULL && MurRandH != NULL && MurRandV != NULL) {
    murExterieur(hauteur, largeur, &murInterdits, &nombreMursInterdits,
                 &MurRandH, &MurRandV);
  } else {
    // Handle NULL pointers error
    printf("Error: One or more pointers are NULL.\n");
  }

 // printf("Coordonnées des murs interdits :\n");
 // for (int i = 0; i < nombreMursInterdits; i++) {
 //   printf("Mur %d: Ligne %d, Col %d\n", i + 1, murInterdits[i].ligne,
 //          murInterdits[i].col);}
  
  afficherGrille(grille, hauteur, largeur, &MurRandH, &MurRandV, MurH_Cibles,
     MurV_Cibles);
  // début du jeu Z'ESSTTT PARTIIII !!!
   int nb_joueur = 1;
    int niveau_difficulte = 2;
    int *nmbMouv = NULL;
    int duree_chrono = 0;
    int joueurActuel = 0;
    int *pointsJoueurs;
    NombreJoueurs(&nb_joueur);
    Robot robot;
    Cible cible;

    pointsJoueurs = malloc(nb_joueur * sizeof(int));
    if (pointsJoueurs == NULL) {
      printf("Erreur d'allocation mémoire\n");
      exit(1);
    }
    for (int i = 0; i < nb_joueur; i++) {
      pointsJoueurs[i] = 0;
    }
    printf("Début du jeu\n");

    for (int i = 0; i < 5; i++) { // Par exemple 5 manches
      printf("Manche %d\n", i + 1);

      ChoisirRobotCible(grille, hauteur, largeur, &robot, &cible);
      duree_chrono = choixdifficulte(niveau_difficulte);
      afficherGrille(grille, hauteur, largeur, &MurRandH, &MurRandV, MurH_Cibles, MurV_Cibles);
      chronometrer(duree_chrono);

      choix_joueur(&nmbMouv, nb_joueur, grille, &robot, &cible, &joueurActuel);
      printf("Le joueur %d va faire %d mouvements\n", joueurActuel + 1, nmbMouv[joueurActuel]);

      JoueurTour(grille, hauteur, largeur, &robot, &cible, murInterdits, nombreMursInterdits, nmbMouv, joueurActuel, pointsJoueurs, &MurRandH, &MurRandV, MurH_Cibles, MurV_Cibles);

      // Afficher les points après chaque manche
      printf("Points après la manche %d:\n", i + 1);
      for (int j = 0; j < nb_joueur; j++) {
        printf("Joueur %d: %d points\n", j + 1, pointsJoueurs[j]);
      }
    }


   AfficherGagnant(pointsJoueurs, nb_joueur);


    for (int i = 0; i < hauteur; i++) {
      free(grille[i]);
    }
    free(grille);
    free(murInterdits);
    free(MurRandH);
    free(MurRandV);
    free(pointsJoueurs);
    free(nmbMouv);

    return 0;
  }
