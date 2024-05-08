#include <stdio.h>
<<<<<<< HEAD
#include <time.h>

#include "interface.h"
#include "creerGrille.h"




int main(){
    srand(time(NULL));
    int joueur = nb_joueur(joueur);
    
    creerGrille(grille);
    placerMursBords(grille);
    afficherGrille(grille);



    
=======
#include <stdlib.h>
#include <time.h>

typedef struct {
    int largeur;
    int hauteur;
    int **cases;
}Grille; // structure pour définir la taille de la grille 

void creerGrille( Grille *grille){  // procédure pour créer la grille de taille aléatoire;
    grille->largeur = 15 + rand() % (15 - 20 + 1);
    grille->hauteur  = 15 + rand() % (15 - 20 + 1);

    grille->cases = malloc( grille->hauteur * sizeof(int*));
    if(grille->cases == NULL){
        printf("erreur d'allocation memoire");
        exit(1);
    }
    for(int i = 0; i<grille->hauteur; i++){
        grille->cases[i] = malloc(grille->largeur * sizeof(int*));
        if(grille->cases[i]== NULL){
            printf("erreur d'allocation mémoire");
            exit(1);
        }
        for (int j = 0; j < grille->largeur; j++) {
            grille->cases[i][j] = ' ';

    }
  }
}
int main(){
    int nb_joueur;
    printf("Veuillez saisir le nombre de joueur : /n ");
    scanf("%d", &nb_joueur);
    while(nb_joueur <= 0){
        printf("Le nombre de joueur doit etre superieur a 0 /n");
        scanf("%d", &nb_joueur);
    }

    srand(time(NULL));
    Grille grille;
    creerGrille(&grille);



    for (int i = 0; i < grille.hauteur; i++) {
        free(grille.cases[i]);
    }
    free(grille.cases);
>>>>>>> 8253b70e99d9ecec67cf7b8de4eef142edb528d0

    return 0;
}