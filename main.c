#include <stdio.h>

#include <time.h>

#include "interface.h"
#include "creerGrille.h"




int main(){
    srand(time(NULL));

    int hauteur = rand() % 6 + 15; // Génère un nombre entre 15 et 20
    int largeur = rand() % 6 + 15;  // Génère un nombre entre 15 et 20
    initialiserGrille(grille, hauteur, largeur);
    placerCibles(grille, hauteur, largeur);
    placerRobots(grille, hauteur, largeur);

    afficherGrille(grille, hauteur, largeur);

    for (int i = 0; i < hauteur; i++) {
        free(grille[i]);
    }
    free(grille);

    return 0;

    Position robot, cible;
    choisirRobotCible(grille, &robot, &cible);
   
    int niveau_difficulte = 2;
    int duree_chrono;
    switch (niveau_difficulte) {
        case 1:
            duree_chrono = 10;
            break;
        case 2:
            duree_chrono = 20;
            break;
        case 3:
            duree_chrono = 30;
            break;
        default:
            duree_chrono = 20;
    }
    chronometrer(duree_chrono);
    
    demanderMouvements(grille, &robot);

    freeGrille(grille);

    return 0;





    
}
