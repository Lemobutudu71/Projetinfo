#include "interface.h"
#include "creerGrille.h



int nb_joueur(int nb_joueur){ // demande le nombre de joueur
    printf("Veuillez saisir le nombre de joueur : /n ");
    scanf("%d", &nb_joueur);
    while(nb_joueur <= 1){
        printf("Le nombre de joueur doit etre superieur a 1 /n");
        scanf("%d", &nb_joueur);
    }
    return nb_joueur;
}

void choisirRobotEtCible(char **grille, int hauteur, int largeur, char *robot, char *cible) {
    int robotTrouve = 0;
    int cibleTrouvee = 0;
    int robotLigne, robotCol, cibleLigne, cibleCol;
    
    // Choisir un robot aléatoire
    while (!robotTrouve) {
        robotLigne = rand() % hauteur;
        robotCol = rand() % largeur;
        if (grille[robotLigne][robotCol] >= '1' && grille[robotLigne][robotCol] <= '4') {
            *robot = grille[robotLigne][robotCol];
            robotTrouve = 1;
        }
    }
    
    // Choisir une cible aléatoire
    while (!cibleTrouvee) {
        cibleLigne = rand() % hauteur;
        cibleCol = rand() % largeur;
        if (grille[cibleLigne][cibleCol] >= 'A' && grille[cibleLigne][cibleCol] <= 'R') {
            *cible = grille[cibleLigne][cibleCol];
            cibleTrouvee = 1;
        }
    }
    
    printf("Robot sélectionné : %c\n", *robot);
    printf("Cible sélectionnée : %c\n", *cible);
}

void chronometrer(int secondes) {
    printf("Temps de réflexion : %d secondes\n", secondes);
    for (int i = secondes; i > 0; i--) {
        printf("%d\n", i);
        sleep(1);
    }
    printf("Temps écoulé \n");
}


void demanderMouvements(char grille[][20], Position *robot) {// a changer
    int dx;
    int dy;
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


