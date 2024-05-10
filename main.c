#include <stdio.h>

#include <time.h>

#include "interface.h"
#include "creerGrille.h"




int main(){
    srand(time(NULL));
    int joueur = nb_joueur(joueur);
    
    creerGrille(grille);
    placerMursBords(grille);
    afficherGrille(grille);




    return 0;
}