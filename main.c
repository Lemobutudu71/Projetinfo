#include "creerGrille.h"
#include <stdio.h>
#include <time.h>
#include "interface.h"


int main(){

MurInterdit *murInterdits = NULL;
int largeur, hauteur;
char **grille;


int CordCibles[CIBLES][2];
int MurH_Cibles[CIBLES][2];
int MurV_Cibles[CIBLES][2];
int nombreMursInterdits = 0;

    int *MurRandH ;
    int *MurRandV ;

    srand(time(NULL));
    hauteur = rand() % 6 + 15; // Génère un nombre entre 15 et 20
    largeur = rand() % 6 + 15;  // Génère un nombre entre 15 et 20
   
            
    initialiserGrille(&grille, hauteur, largeur);
    initialiserMurInterdit(&murInterdits, hauteur, largeur);  
        placerCibles(grille, hauteur, largeur, CordCibles, MurH_Cibles, MurV_Cibles, &murInterdits, &nombreMursInterdits);
            placerRobots(grille, hauteur, largeur, murInterdits, nombreMursInterdits);
   
            murExterieur(hauteur, largeur, &murInterdits, &nombreMursInterdits, &MurRandH, &MurRandV);
            afficherGrille(grille, hauteur, largeur, &MurRandV, &MurRandH, MurH_Cibles, MurV_Cibles);
        
        printf("Coordonnées des murs interdits :\n");
            for (int i = 0; i < nombreMursInterdits; i++) {
                printf("Mur %d: Ligne %d, Col %d\n", i + 1, murInterdits[i].ligne, murInterdits[i].col);
            }

    int nb_joueur;
    int niveau_difficulte = 2;
     NombreJoueurs( nb_joueur);
    char robot, cible;
    choisirRobotCible(grille, hauteur, largeur, &robot, &cible);
    
    chronometrer(choixdifficulte(niveau_difficulte));
    printf("Ok");
    Joueur *joueur = NULL; 

     nombresMouv(nb_joueur, &joueur);


    printf("Ok");
    
        for (int i = 0; i < hauteur; i++) {
                free(grille[i]);
               
            }

            free(joueur);
            free(grille);
            free(murInterdits);
            free(MurRandH);
            free(MurRandV);
    

return 0;
}

