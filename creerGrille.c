#include "creerGrille.h"

 #define MUR_VERTICAL '|'
 #define MUR_HORIZONTAL '-'



Grille *creerGrille() {
    Grille *grille = malloc(sizeof(Grille));
    if (grille == NULL) {
        printf("Erreur d'allocation mémoire");
        exit(1);
    }

    grille->largeur = 15 + rand() % (20 - 15 + 1);
    grille->hauteur = 15 + rand() % (20 - 15 + 1);

    grille->cases = malloc(grille->hauteur * sizeof(char *));
    if (grille->cases == NULL) {
        printf("Erreur d'allocation mémoire");
        exit(1);
    }

    for (int i = 0; i < grille->hauteur; i++) {
        grille->cases[i] = malloc(grille->largeur * sizeof(char));
        if (grille->cases[i] == NULL) {
            printf("Erreur d'allocation mémoire");
            exit(1);
        }
        for (int j = 0; j < grille->largeur; j++) {
            grille->cases[i][j] = ' ';
        }
    }

    return grille;
}


void afficherGrille(Grille *grille) {
    for (int i = 0; i < grille->hauteur; i++) {
        for (int j = 0; j < grille->largeur; j++) {
            printf("%c ", grille->cases[i][j]);
        }
        printf("\n");
    }
}

void placerMursBords(Grille *grille) {
    for (int i = 0; i < grille->largeur; i++) {
        grille->cases[0][i] = MUR_HORIZONTAL; // Mur horizontal haut
        grille->cases[grille->hauteur - 1][i] = MUR_HORIZONTAL; // Mur horizontal bas
    }
    for (int j = 0; j < grille->hauteur; j++) {
        grille->cases[j][0] = MUR_VERTICAL; // Mur vertical gauche
        grille->cases[j][grille->largeur - 1] = MUR_VERTICAL; // Mur vertical droit
    }
}



void freeGrille(Grille grille){ // libère le mémoire 
    for (int i = 0; i < grille.hauteur; i++) {
        free(grille.cases[i]);
    }
    free(grille.cases);
    
}

