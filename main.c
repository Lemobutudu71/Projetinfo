#include <stdio.h>

#include <time.h>

#include "interface.h"
#include "creerGrille.h"




int main(){
    srand(time(NULL));
    int joueur = nb_joueur(joueur);
    int hauteur = 15 + rand() % (20 - 15 + 1);
    int largeur = 15 + rand() % (20 - 15 + 1);

    Cellule **cellules = initialiserGrille(hauteur, largeur);
    placerCiblesEtMurs(cellules, hauteur, largeur);
    placerRobots(cellules, hauteur, largeur);
    afficherGrille(hauteur, largeur, cellules);
    libererGrille(cellules, hauteur);

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
