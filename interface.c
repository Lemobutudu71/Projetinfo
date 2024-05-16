#include "interface.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>


int nb_joueur(int nb_joueur){ // demande le nombre de joueur
    printf("Veuillez saisir le nombre de joueur : /n ");
    scanf("%d", &nb_joueur);
    while(nb_joueur <= 1){
        printf("Le nombre de joueur doit etre superieur a 1 /n");
        scanf("%d", &nb_joueur);
    }
    return nb_joueur;
}

void choisirRobotCible(char grille[][20], Position *robot, Position *cible) {
    int x, y;
    // Choisir un robot aléatoirement
    do {
        x = rand() % 18 + 1; // Génère un nombre aléatoire entre 1 et 18
        y = rand() % 18 + 1;
    } while (grille[y][x] != ' '); // Vérifie si la case est vide
    robot->x = x;
    robot->y = y;
    grille[y][x] = 'R'; // Marque la position du robot sur la grille

    // Choisir une cible aléatoirement
    do {
        x = rand() % 18 + 1;
        y = rand() % 18 + 1;
    } while (grille[y][x] != ' ');
    cible->x = x;
    cible->y = y;
    grille[y][x] = 'C'; // Marque la position de la cible sur la grille

    // Afficher la grille avec le robot et la cible
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%c ", grille[i][j]);
        }
        printf("\n");
    }
}

void chronometrer(int duree_chrono) {
    printf("Le chronomètre est lancé pendant %d secondes...\n", duree_chrono);
    sleep(duree_chrono);
}

void demanderMouvements(char grille[][20], Position *robot) {
    int dx, dy;
    printf("Entrez les mouvements nécessaires (dx dy) : ");
    scanf("%d %d", &dx, &dy);

    // Vérifier si le mouvement demandé est valide
    int nouvelle_x = robot->x + dx;
    int nouvelle_y = robot->y + dy;
    if (nouvelle_x >= 1 && nouvelle_x <= 18 && nouvelle_y >= 1 && nouvelle_y <= 18 && grille[nouvelle_y][nouvelle_x] != '|' && grille[nouvelle_y][nouvelle_x] != '-' && grille[nouvelle_y][nouvelle_x] != 'R') {
        // Le mouvement est valide, mettre à jour la position du robot
        robot->x = nouvelle_x;
        robot->y = nouvelle_y;
    } else {
        // Le mouvement est invalide, informer l'utilisateur et redemander les mouvements
        printf("Mouvement invalide. Assurez-vous de ne pas traverser de murs ou d'autres robots.\n");
        demanderMouvements(grille, robot); // Appel récursif pour redemander les mouvements
    }
}


