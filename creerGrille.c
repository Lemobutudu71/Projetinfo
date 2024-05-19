#define couleur(param) printf("\033[%sm",param)

#define CIBLES 18
#define ROBOTS 4

// Fonction pour initialiser la grille
void initialiserGrille() {
    grille = (char **)malloc(hauteur * sizeof(char *));
    for (int i = 0; i < hauteur; i++) {
        grille[i] = (char *)malloc(largeur * sizeof(char));
        for (int j = 0; j < largeur; j++) {
            grille[i][j] = ' ';
        }
    }
}

// Fonction pour vérifier si une position est valide pour placer une cible ou un robot
int estPositionValide(char **grille, int hauteur, int largeur, int ligne, int col) {
    if (ligne <= 0 || ligne >= hauteur - 1 || col <= 0 || col >= largeur - 1 || grille[ligne][col] != ' ') {
        return 0;
    }
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
void placerCibles(char **grille, int hauteur, int largeur) {
    for (int num = 0; num < CIBLES; num++) {
        int ligne, col;
        do {
            ligne = rand() % (hauteur - 2) + 1;
            col = rand() % (largeur - 2) + 1;
            
        } while (!estPositionValide(grille, hauteur, largeur, ligne, col));
        grille[ligne][col] = 'A' + num;
        CordCibles[num][0]=ligne;
        CordCibles[num][1]=col;
        
        int choix = rand() % 4;
            switch(choix) {
                case 0 : // Haut Gauche
                    MurH_Cibles[num][0]=ligne;
                    MurH_Cibles[num][1]=col;
                    MurV_Cibles[num][0]=col;
                    MurV_Cibles[num][1]=ligne;
                    break;
                case 1 : // Haut Droite
                    MurH_Cibles[num][0]=ligne;
                    MurH_Cibles[num][1]=col;
                    MurV_Cibles[num][0]=col + 1;
                    MurV_Cibles[num][1]=ligne;
                    break;
                case 2 : // Bas Gauche
                    MurH_Cibles[num][0]=ligne + 1;
                    MurH_Cibles[num][1]=col;
                    MurV_Cibles[num][0]=col;
                    MurV_Cibles[num][1]=ligne;
                    break;
                case 3 : // Bas Droite
                    MurH_Cibles[num][0]=ligne + 1;
                    MurH_Cibles[num][1]=col;
                    MurV_Cibles[num][0]=col + 1;
                    MurV_Cibles[num][1]=ligne;
                    break;
                default :
                    printf("Erreur d'allocation MurCibles\n");
                    break;
            }
            
            
    }
}

// Fonction pour placer les robots
void placerRobots(char **grille, int hauteur, int largeur) {
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
void afficherGrille(char **grille, int hauteur, int largeur) {
    couleur("47"); // Fond blanc
    for (int ligne = 0; ligne <=hauteur; ligne++) {
        // Afficher la bordure supérieure de chaque cellule
        for (int col = 0; col < largeur; col++) {
            if ((ligne == 0) || (ligne == hauteur )) {
                couleur("31"); // Texte rouge pour les lignes des bords supérieur et inférieur
            } else {
                couleur("34"); // Texte bleu pour les lignes internes
            }
            if (col == 0 || col == largeur) {
                couleur("31"); // Texte rouge pour la bordure gauche et droite
            }
            printf("+");
            if ((ligne == 0) || ligne == hauteur ) {
                couleur("31"); // Texte rouge pour les lignes des bords supérieur et inférieur
            } 
            else if (ligne==MurRandH[0] && col==0 || ligne==MurRandH[1] && col==0 
            || ligne==MurRandH[2] && col==largeur - 1 || ligne==MurRandH[3] && col==largeur - 1){
                couleur("31"); // Texte rouge pour les 4 mur horizontaux Rand
            }
            
            else {
                couleur("34"); // Texte bleu pour les lignes internes
            }
            for(int i=0; i<CIBLES; i++){
                if(MurH_Cibles[i][0]==ligne && MurH_Cibles[i][1]==col){
                    couleur("31"); // Texte rouge pour murs cibles
                }
            }
            printf("---");
        }
        couleur("31"); // Texte rouge pour les lignes des bords supérieur et inférieur
        printf("+\n");

        if (ligne == hauteur) break; // Pour éviter de dessiner une ligne de contenu en trop

        // Afficher le contenu des cellules
        for (int col = 0; col < largeur; col++) {
            if (col == 0 ) {
                couleur("31"); // Texte rouge pour la bordure gauche et droite
            } 
            else if ( ligne==0 && col==MurRandV[0] || ligne==0 && col==MurRandV[1] 
            || ligne==hauteur - 1 && col==MurRandV[2]
            || ligne==hauteur - 1 && col==MurRandV[3]){
                couleur("31"); // Texte rouge pour les 4 murs verticaux Rand
            }
            else {
                couleur("30"); // Texte noir pour le contenu des cellules
            }
            for(int i=0; i<CIBLES; i++){
                if(MurV_Cibles[i][0]==col && MurV_Cibles[i][1]==ligne){
                    couleur("31"); // Texte rouge pour colonnes cibles
                }
            }
            printf("|");
            if (grille[ligne][col] == ' ') {
                printf("   "); // Espace pour les murs internes
            } else {
                couleur("31");
                printf(" %c ", grille[ligne][col]); // Contenu des cellules
            }
        }
        couleur("31"); // Texte rouge pour la bordure gauche et droite
        printf("|\n");
    }
}

