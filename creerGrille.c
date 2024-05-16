#include "creerGrille.h"

#define MUR_VERTICAL '|'
#define MUR_HORIZONTAL '-'
#define MIN 15 // franchement ici je trouve pas intéressant de define ces valeurs, vaut mieux les mettre direct sinon ça peut nous gêner
#define MAX 20 // pareil ici
#define NB_CIBLES 18
#define NB_ROBOTS 4



Grille *creerGrille() {
    Grille *grille = malloc(sizeof(Grille));
    if (grille == NULL) {
        printf("Erreur d'allocation mémoire");
        exit(1);
    }

    grille->largeur = MIN + rand() % (MAX - MIN + 1);
    grille->hauteur = MIN + rand() % (MAX - MIN + 1);

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
void placerMursPerpendiculaires(Grille *grille) { // A modifié affiche pas
    // Pour chaque côté de la grille, place deux murs perpendiculaires de manière aléatoire

    // Bord supérieur
    int x1 = 1 + rand() % (grille->largeur - 3); // Coordonnée x aléatoire pour le premier mur
    int x2 =  2 + rand() % (grille->largeur - 3); // Coordonnée x aléatoire pour le deuxième mur, 
    grille->cases[0][x1] = MUR_VERTICAL;
    grille->cases[0][x2] = MUR_VERTICAL;

    // Bord droit
    int y1 = 1 + rand() % (grille->hauteur - 3); // Coordonnée y aléatoire pour le premier mur
    int y2 = 2 + rand() % (grille->hauteur - 3) ; // Coordonnée y  aléatoire pour le deuxième mur
    grille->cases[y1][grille->largeur - 2] = MUR_HORIZONTAL;
    grille->cases[y2][grille->largeur - 2] = MUR_HORIZONTAL;

    // Bord inférieur
    x1 = 1 + rand() % (grille->largeur - 3); // Coordonnée x aléatoire pour le premier mur
    x2 = 2 + rand() % (grille->largeur - 3); // Coordonnée x aléatoire pour le deuxième mur, 
    grille->cases[grille->hauteur - 2][x1] = MUR_VERTICAL;
    grille->cases[grille->hauteur - 2][x2] = MUR_VERTICAL;

    // Bord gauche
    y1 = 1 + rand() % (grille->hauteur - 3); // Coordonnée y aléatoire pour le premier mur
    y2 = 2 + rand() % (grille->hauteur - 3); // Coordonnée y aléatoire pour le deuxième mur, 
    grille->cases[y1][0] = MUR_HORIZONTAL;
    grille->cases[y2][0] = MUR_HORIZONTAL;
}


void placerCibles(Grille *grille) {
    int placer = 0;//compte le nombre de cible placer correctement 
    while (placer < NB_CIBLES) {//boucle continue tant que les 18 cibles ne sont pas placées 
        int x = 1 + rand() % (grille->largeur - 2);// selectionne coordonnés x et y pour placer la cible de façon aléatoires en evitant les bordures (+1)
        int y = 1 + rand() % (grille->hauteur - 2);

        // vérification qu'il n'y a pas de cibles à coté 
        int valide = 1;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (grille->cases[y + dy][x + dx] != ' ') {
                    valide = 0;// case non valide 
                    break;
                }
            }
            if (!valide) break;
        }

        if (valide) {
            grille->cases[y][x] = 'A' + (placer); // cible placée sur la grille numérotées
            placer++;

            // place deux murs qui forment un angle droit autour de la cible de façon aléatoire
            if (rand() % 2) {
                grille->cases[y + 1][x] = MUR_HORIZONTAL;
                grille->cases[y][x + 1] = MUR_VERTICAL;
            } else {
                grille->cases[y - 1][x] = MUR_HORIZONTAL;
                grille->cases[y][x - 1] = MUR_VERTICAL;
            }
        }
    }
}

void placerRobots(Grille *grille) {
    int placed = 0;
    while (placed < NB_ROBOTS) {
        int x = rand() % grille->largeur;
        int y = rand() % grille->hauteur;

        if (grille->cases[y][x] == ' ') {
            grille->cases[y][x] = 'R'; // R for robot
            placed++;
        }
    }
}

void afficherGrille(Grille *grille) {
    for (int i = 0; i < grille->hauteur; i++) {
        for (int j = 0; j < grille->largeur; j++) {
            printf("%c ", grille->cases[i][j]);
        }
        printf("\n");
    }
}


void freeGrille(Grille grille){ // libère le mémoire 
    for (int i = 0; i < grille.hauteur; i++) {
        free(grille.cases[i]);
    }
    free(grille.cases);
    
}

