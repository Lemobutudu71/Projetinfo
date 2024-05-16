#include "interface.h"



int nb_joueur(int nb_joueur){ // demande le nombre de joueur
    printf("Veuillez saisir le nombre de joueur : /n ");
    scanf("%d", &nb_joueur);
    while(nb_joueur <= 1){
        printf("Le nombre de joueur doit etre superieur a 1 /n");
        scanf("%d", &nb_joueur);
    }
    return nb_joueur;
}

int choisir_niveau_difficulte(){ // demande le niveau 
    int niveau;
    printf("Choisissez le niveau de difficulté :\n");
    printf("1 : Facile\n");
    printf("2 : Moyen\n");
    printf("3 : Difficile\n");
    scanf("%d", &niveau);
    while (niveau < 1 || niveau > 3) {
        printf("Veuillez choisir un niveau entre 1 et 3.\n");
        scanf("%d", &niveau);
    }
    return niveau;
}


