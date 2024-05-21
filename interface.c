#include "interface.h"
#include "creerGrille.h"


int NombreJoueurs(int nb_joueur){ // demande le nombre de joueur
    printf("Veuillez saisir le nombre de joueur : \n");
    scanf("%d", &nb_joueur);
    while(nb_joueur <= 1){
        printf("Le nombre de joueur doit etre superieur a 1 \n");
        scanf("%d", &nb_joueur);
    }
    return nb_joueur;
}

int choixdifficulte(int niveau_difficulte){
	int duree_chrono=0;
	printf("Veuillez choisir le niveau de difficulté :\nniv 1 = 30\nniv 2 = 20\nniv 3 = 10\n");
    scanf("%d", &niveau_difficulte);
    while(niveau_difficulte < 1 || niveau_difficulte > 4){
        printf("Le niveau de difficulte doit etre compris entre 1 et 4 \n");
        scanf("%d", &niveau_difficulte);
    }
    switch (niveau_difficulte) {
        case 1:
            duree_chrono = 30;
            break;
        case 2:
            duree_chrono = 20;
            break;
        case 3:
            duree_chrono = 10;
            break;
        default:
            duree_chrono = 20;
    }
    return duree_chrono;
}

void choisirRobotCible(char **grille, int hauteur, int largeur, char *robot, char *cible) {
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
    
    printf("\nRobot sélectionné : %c\n", *robot);
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

