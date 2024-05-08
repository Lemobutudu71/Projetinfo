#include "interface.h"



int nb_joueur(int nb_joueur){ // demande le nombre de joueur
    printf("Veuillez saisir le nombre de joueur : /n ");
    scanf("%d", &nb_joueur);
    while(nb_joueur <= 0){
        printf("Le nombre de joueur doit etre superieur a 0 /n");
        scanf("%d", &nb_joueur);
    }
    return nb_joueur;
}