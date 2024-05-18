#ifndef Grille_h
    #define Grille_h

    #include <stdlib.h>

   typedef struct {
    char contenu[3];  // Pour stocker des chiffres ou des icônes de robot
    int MurVertical;
    int MurHorizontal;
} Cellule;


    Cellule **cellules;
    Cellule **initialiserGrille(int hauteur, int largeur); 
    void placerCiblesEtMurs(Cellule **cellules, int hauteur, int largeur);
    void placerRobots(Cellule **cellules, int hauteur, int largeur); 
    void afficherGrille(int hauteur, int largeur, Cellule **cellules);
    void libererGrille(Cellule **cellules, int hauteur);

    
#endif

