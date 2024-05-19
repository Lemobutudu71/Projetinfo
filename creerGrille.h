#ifndef Grille_h
    #define Grille_h

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>


    char **grille;
    char **initialiserGrille(char **grille, int hauteur, int largeur);
    void placerCibles(char **grille, int hauteur, int largeur);
    void placerRobots(char **grille, int hauteur, int largeur);

    void afficherGrille(char **grille, int hauteur, int largeur);

    
#endif

