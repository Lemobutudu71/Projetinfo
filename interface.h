#ifndef Interface_h
    #define Interface_h

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
	#include "couleur.h"
    
   int NombreJoueurs(int nb_joueur);
   void choisirRobotCible(char **grille, int hauteur, int largeur, char *robot, char *cible);
   void chronometrer(int duree_chrono); // Chronométrer
   int choixdifficulte(int niveau_difficulte);

    
#endif
