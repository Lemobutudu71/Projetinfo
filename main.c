#include <stdio.h>

#include <time.h>

#include "interface.h"
#include "creerGrille.h"

int main(){

int largeur, hauteur;
char **grille;
int **MurInterdit;
int MurRandH[4];
int MurRandV[4];
int CordCibles[CIBLES][2];
int MurH_Cibles[CIBLES][2];
int MurV_Cibles[CIBLES][2];

    srand(time(NULL));
    hauteur = rand() % 6 + 15; // Génère un nombre entre 15 et 20
    largeur = rand() % 6 + 15;  // Génère un nombre entre 15 et 20
    for(int i=0; i<4; i++){
            MurRandH[i]=rand() % (hauteur - 2) + 1; 
            MurRandV[i]=rand() % (largeur - 2) + 1;
    }
            
    initialiserGrille(&grille, hauteur, largeur);
    initialiserMurInterdit(&MurInterdit, hauteur, largeur);  
    placerCibles(grille, hauteur, largeur, CordCibles, MurH_Cibles, MurV_Cibles);
    afficherGrille(grille, hauteur, largeur, MurRandH, MurRandV,MurH_Cibles, MurV_Cibles);
    placerRobots(grille, hauteur, largeur);
	placerCibles(grille, hauteur, largeur, CordCibles, MurH_Cibles, MurV_Cibles);
    int nb_joueur;
    int niveau_difficulte = 2;
     NombreJoueurs( nb_joueur);
    char robot, cible;
    choisirRobotCible(grille, hauteur, largeur, &robot, &cible);
    choixdifficulte( niveau_difficulte);
    chronometrer(choixdifficulte(niveau_difficulte));

    for (int i = 0; i < hauteur; i++) {
        free(grille[i]);
    }
    free(grille);

    for (int i = 0; i < hauteur; i++) {
            free(MurInterdit[i]);
    }
    free(MurInterdit);

return 0;
}
