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
    do {
        x = rand() % 18 + 1; 
        y = rand() % 18 + 1;
    } while (grille[y][x] != ' '); 
    robot->x = x;
    robot->y = y;
    grille[y][x] = 'R'; // Marque la position du robot sur la grille

    do { 
        x = rand() % 18 + 1;
        y = rand() % 18 + 1;
    } while (grille[y][x] != ' ');
    cible->x = x;
    cible->y = y;
    grille[y][x] = 'C'; 

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%c ", grille[i][j]);
        }
        printf("\n");
    }
}

void chronometrer(int duree_chrono) {
    printf("Le chronomètre est lancé pendant %d secondes\n", duree_chrono);
    sleep(duree_chrono);
}

void demanderMouvements(char grille[][20], Position *robot) {
    int dx, dy;
    printf("Entrez les mouvements nécessaires (dx dy) : ");
    scanf("%d %d", &dx, &dy);

    int nouvelle_x = robot->x + dx;
    int nouvelle_y = robot->y + dy;
    if (nouvelle_x >= 1 && nouvelle_x <= 18 && nouvelle_y >= 1 && nouvelle_y <= 18 && grille[nouvelle_y][nouvelle_x] != '|' && grille[nouvelle_y][nouvelle_x] != '-' && grille[nouvelle_y][nouvelle_x] != 'R') {
        robot->x = nouvelle_x;
        robot->y = nouvelle_y;
    } else {
        printf("Mouvement invalide. IL ne pas traverser de murs ou d'autres robots.\n");
        demanderMouvements(grille, robot); 
    }
}


