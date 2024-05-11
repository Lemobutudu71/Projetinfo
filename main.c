#include <stdio.h>

#include <time.h>

#include "interface.h"
#include "creerGrille.h"




int main(){
    srand(time(NULL));
    int joueur = nb_joueur(joueur);
    
    creerGrille(grille);
    placerMursBords(grille);
    placerMursPerpendiculaires(grille);
    placerCibles(grille);
    placerRobots(grille);
    afficherGrille(grille);
    freeGrille(grille);



    return 0;
}