#ifndef Interface_h
    #define Interface_h

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    
   int nb_joueur(int nb_joueur);
   void choisirRobotCible(char **grille, int hauteur, int largeur, char *robot, char *cible);
   void chronometrer(int duree_chrono); // Chronométrer
   void demanderMouvements(Grille *grille, Position *robot);

    
#endif
