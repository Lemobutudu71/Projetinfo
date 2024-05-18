
#include "creerGrille.h"

#define CIBLES 18
#define ROBOTS 4



// Fonction pour initialiser la grille
void initialiserGrille(char **grille; int hauteur; int largeur) {
    grille = (char **)malloc(hauteur * sizeof(char *));
    for (int i = 0; i < hauteur; i++) {
        grille[i] = (char *)malloc(largeur * sizeof(char));
        for (int j = 0; j < largeur; j++) {
            grille[i][j] = ' ';
        }
    }
}


// Fonction pour vérifier si une position est valide pour placer une cible ou un robot
int estPositionValide(int ligne, int col) {
    // S'assurer que la position n'est pas sur la bordure et est vide
    if (ligne <= 0 || ligne >= hauteur - 1 || col <= 0 || col >= largeur - 1 || grille[ligne][col] != ' ') {
        return 0;
    }
    // Vérifier les cellules environnantes pour éviter les cibles/robots adjacents
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (grille[ligne + i][col + j] != ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Fonction pour placer les cibles
void placerCibles(char **grille; int hauteur; int largeur) {
    for (int num = 0; num < CIBLES; num++) {
        int ligne, col;
        do {
            ligne = rand() % (hauteur - 2) + 1;
            col = rand() % (largeur - 2) + 1;
        } while (!estPositionValide(ligne, col));
        grille[ligne][col] = 'A' + num;
    }
}

// Fonction pour placer les robots
void placerRobots(char **grille; int hauteur; int largeur) {
    for (int num = 0; num < ROBOTS; num++) {
        int ligne, col;
        do {
            ligne = rand() % (hauteur - 2) + 1;
            col = rand() % (largeur - 2) + 1;
        } while (grille[ligne][col] != ' ');
        grille[ligne][col] = '1' + num; // Utiliser des chiffres pour différencier les robots
    }
}

// Fonction pour afficher la grille
void afficherGrille() {
    couleur("47"); // Fond blanc
    for (int ligne = 0; ligne < hauteur; ligne++) {
        // Afficher la bordure supérieure de chaque cellule
        for (int col = 0; col < largeur; col++) {
            if (ligne == 0 || ligne == hauteur ) {
                couleur("35"); // Texte bleu pour les bordures extérieures horizontales
            } else {
                couleur("33"); // Texte noir pour les lignes internes
            }
            printf("+---");
        }
        printf("+\n");
        // Afficher le contenu des cellules
        for (int col = 0; col < largeur; col++) {
            if (col == 0 ) {
                couleur("35"); // Texte bleu pour les bordures extérieures verticales
            } else {
                couleur("33"); // Texte noir pour les séparateurs internes
            }
            printf("|");
            printf(" %c ", grille[ligne][col]);
        }
        couleur("35");
        printf("|\n");
    }
    // Afficher la bordure inférieure de la dernière ligne
    for (int col = 0; col < largeur; col++) {
        couleur("35"); // Texte bleu pour les bordures extérieures horizontales
        printf("+---");
    }
    printf("+\n");
}



