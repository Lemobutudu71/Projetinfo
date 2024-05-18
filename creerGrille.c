#include "creerGrille.h"

#define MAX_CIBLES 18
#define MAX_ROBOTS 4


void afficherGrille(int hauteur, int largeur, Cellule **cellules) {
    // Affiche le bord supérieur de la grille
    for (int j = 0; j < largeur; j++) {
        printf("+---");
    }
    printf("+\n");

    for (int i = 0; i < hauteur; i++) {
        // Affiche le bord supérieur de chaque ligne de cellule
        for (int j = 0; j < largeur; j++) {
            // Affiche '+' seulement s'il est sur le bord ou connecté à un mur
            if (j == 0 || cellules[i][j].MurHorizontal || (j > 0 && cellules[i][j - 1].MurHorizontal)) {
                printf("+");
            } else {
                printf(" ");
            }

            if (cellules[i][j].MurHorizontal) {
                printf("---");
            } else {
                printf("   ");
            }
        }
        printf("+\n");

        // Affiche le contenu de la cellule et les murs verticaux
        for (int j = 0; j < largeur; j++) {
            if (j == 0 || cellules[i][j].MurVertical) {
                printf("|");
            } else {
                printf(" ");
            }
            printf("%2s ", cellules[i][j].contenu);
        }
        printf("|\n");
    }

    // Affiche le bord inférieur de la grille
    for (int j = 0; j < largeur; j++) {
        printf("+---");
    }
    printf("+\n");
}

Cellule **initialiserGrille(int hauteur, int largeur) {
    Cellule **cellules = malloc(hauteur * sizeof(Cellule *));
    for (int i = 0; i < hauteur; i++) {
        cellules[i] = malloc(largeur * sizeof(Cellule));
        for (int j = 0; j < largeur; j++) {
            strcpy(cellules[i][j].contenu, " ");
            cellules[i][j].MurVertical = 0;
            cellules[i][j].MurHorizontal = 0;
        }
    }
    return cellules;
}

void libererGrille(Cellule **cellules, int hauteur) {
    for (int i = 0; i < hauteur; i++) {
        free(cellules[i]);
    }
    free(cellules);
}

void placerCiblesEtMurs(Cellule **cellules, int hauteur, int largeur) {
    int ciblesPlacees = 0;
    while (ciblesPlacees < MAX_CIBLES) {
        int x = 2 + rand() % (largeur - 4);  // Évite de placer sur les bords
        int y = 2 + rand() % (hauteur - 4);  // Évite de placer sur les bords

        // Vérifie si la cellule actuelle ou ses voisins adjacents et diagonaux contiennent déjà une cible
        if (strcmp(cellules[y][x].contenu, " ") == 0 &&
            strcmp(cellules[y-1][x].contenu, " ") == 0 &&
            strcmp(cellules[y+1][x].contenu, " ") == 0 &&
            strcmp(cellules[y][x-1].contenu, " ") == 0 &&
            strcmp(cellules[y][x+1].contenu, " ") == 0 &&
            strcmp(cellules[y-1][x-1].contenu, " ") == 0 &&
            strcmp(cellules[y-1][x+1].contenu, " ") == 0 &&
            strcmp(cellules[y+1][x-1].contenu, " ") == 0 &&
            strcmp(cellules[y+1][x+1].contenu, " ") == 0) {
            sprintf(cellules[y][x].contenu, "%d", ciblesPlacees + 1);
            ciblesPlacees++;

            // Détermine aléatoirement l'orientation des murs en angle droit
            int typeMur = rand() % 4;
            switch (typeMur) {
                case 0:
                    cellules[y][x].MurVertical = 1;
                    cellules[y][x].MurHorizontal = 1;
                    break;
                case 1:
                    cellules[y][x].MurVertical = 1;
                    cellules[y+1][x].MurHorizontal = 1;
                    break;
                case 2:
                    cellules[y][x].MurHorizontal = 1;
                    cellules[y][x+1].MurVertical = 1;
                    break;
                case 3:
                    cellules[y][x+1].MurVertical = 1;
                    cellules[y+1][x].MurHorizontal = 1;
                    break;
            }
        }
    }
}

void placerRobots(Cellule **cellules, int hauteur, int largeur) {
    char Robots[4][3] = {"R1", "R2", "R3", "R4"};
    int robotsPlaces = 0;
    while (robotsPlaces < MAX_ROBOTS) {
        int x = 1 + rand() % (largeur - 2);  // Évite de placer sur les bords
        int y = 1 + rand() % (hauteur - 2);  // Évite de placer sur les bords
        if (strcmp(cellules[y][x].contenu, " ") == 0) {
            strcpy(cellules[y][x].contenu, Robots[robotsPlaces % 4]);
            robotsPlaces++;
        }
    }
}

