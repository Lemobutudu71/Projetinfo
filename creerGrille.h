#ifndef Grille_h
    #define Grille_h

    #include <stdlib.h>

    typedef struct {
    int largeur;
    int hauteur;
    char **cases;
    } Grille;

    void creerGrille(Grille *grille);
    void placerMursBords(Grille *grille);
    void placerMursPerpendiculaires(Grille *grille);
    void placerCibles(Grille *grille);
    void placerRobots(Grille *grille);
    void afficherGrille(Grille *grille);
    void freeGrille(Grille grille);
    
#endif