#include <stdio.h>

#include <time.h>

#include "interface.h"
#include "creerGrille.h"

// Déclarer les variables globales
int hauteur,
largeur;
char **grille;
int MurRandH[4];
int MurRandV[4];
int CordCibles[CIBLES][2];
int MurH_Cibles[CIBLES][2];
int MurV_Cibles[CIBLES][2];


int main(){
    srand(time(NULL));
    MurRandH[4];
    MurRandV[4];
    hauteur = rand() % 6 + 15; // Génère un nombre entre 15 et 20
    largeur = rand() % 6 + 15;  // Génère un nombre entre 15 et 20
    for(int i=0; i<4; i++){
            MurRandH[i]=rand() % (hauteur - 2) + 1; 
            MurRandV[i]=rand() % (largeur - 2) + 1;
            }
    initialiserGrille(grille, hauteur, largeur);
    placerCibles(grille, hauteur, largeur);
    placerRobots(grille, hauteur, largeur);

    afficherGrille(grille, hauteur, largeur);
    
    char robot, cible;
    choisirRobotCible(grille, hauteur, largeur, &robot, &cible);
    int niveau_difficulte = 2;
    int duree_chrono;
    printf("Veuillez choisir le niveau de difficulté entre 1 et 4\n");
    scanf("%d", &niveau_difficulte);
    while(niveau_difficulte < 1 || niveau_difficulte > 4){
        printf("Le niveau de difficulte doit etre compris entre 1 et 4 \n");
        scanf("%d", &niveau_difficulte);
    }
    switch (niveau_difficulte) {
        case 1:
            duree_chrono = 10;
            break;
        case 2:
            duree_chrono = 20;
            break;
        case 3:
            duree_chrono = 30;
            break;
        default:
            duree_chrono = 20;
    }
    chronometrer(duree_chrono);
    
    demanderMouvements(grille, &robot);






    
    for (int i = 0; i < hauteur; i++) {
        free(grille[i]);
    }
    free(grille);
    return 0;





    
}
