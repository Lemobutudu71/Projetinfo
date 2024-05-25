#include "interface.h"
#include "creerGrille.h"

void NombreJoueurs(int *nb_joueur) { // demande le nombre de joueur
  printf("Veuillez saisir un nombre de joueur entre 1 et 4 : \n");
  if (scanf("%d", &(*nb_joueur)) != 1) {
    printf("Erreur \n");
    exit(1);
  }
  while (*nb_joueur <= 1 && *nb_joueur > 4) {
    printf("Le nombre de joueur doit etre compris entre 1 et 4 \n");

    if (scanf("%d", &(*nb_joueur)) != 1) {
      printf("Erreur \n");
      exit(1);
    }
  }
}

int choixdifficulte(int niveau_difficulte) {
  int duree_chrono = 0;
  printf("\nVeuillez choisir le niveau de difficulté :\nniv 1 = 30\nniv 2 = "
         "20\nniv 3 = 10\n");
  if (scanf("%d", &niveau_difficulte) != 1) {
    printf("Erreurr \n");
    exit(1);
  }
  while (niveau_difficulte < 1 || niveau_difficulte > 3) {
    printf("Le niveau de difficulte doit etre compris entre 1 et 3 \n");
    if (scanf("%d", &niveau_difficulte) != 1) {
      printf("Erreurr \n");
      exit(1);
    }
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

void ChoisirRobotCible(char **grille, int hauteur, int largeur, Robot *robot,
                       Cible *cible) {
  int robotTrouve = 0;
  int cibleTrouvee = 0;

  // Choisir un robot aléatoire
  while (!robotTrouve) {
    robot->ligne = rand() % hauteur;
    robot->col = rand() % largeur;
    if (grille[robot->ligne][robot->col] >= '1' &&
        grille[robot->ligne][robot->col] <= '4') {
      robot->signe = grille[robot->ligne][robot->col];
      robotTrouve = 1;
    }
  }

  // Choisir une cible aléatoire
  while (!cibleTrouvee) {
    cible->ligne = rand() % hauteur;
    cible->col = rand() % largeur;
    if (grille[cible->ligne][cible->col] >= 'A' &&
        grille[cible->ligne][cible->col] <= 'R') {
      cible->signe = grille[cible->ligne][cible->col];
      cibleTrouvee = 1;
    }
  }

  printf("\nRobot sélectionné : %c\n", robot->signe);
  printf("Cible sélectionnée : %c\n", cible->signe);
}

void chronometrer(int duree_chrono) {
  printf("Temps de réflexion : %d secondes\n", duree_chrono);
  for (int i = duree_chrono; i > 0; i--) {
    printf("%d\n", i);
    sleep(1);
    printf("\033[F\033[J");
  }
  clrscr();
  clrscr();
  clrscr();
  printf("Temps écoulé \n");
}
int MIN(int My_array[], int len) {
  int num = My_array[0];
  for (int i = 1; i < len; i++) {
    if (My_array[i] < num) {
      num = My_array[i];
    }
  }
  return num;
}

void choix_joueur(int **nmbMouv, int nb_Joueur, char **grille, Robot *robot,
                  Cible *cible, int *player) {
  *nmbMouv = malloc(nb_Joueur * sizeof(int *));
  for (int i = 0; i < nb_Joueur; i++) {
    printf("Combien de mouvement voulez vous faire joueur %d ?\n", i + 1);
    if (scanf("%d", &(*nmbMouv)[i]) != 1) {
      printf("Erreur de saisie. Veuillez saisir un entier.\n");
      exit(1);
    }
  }
  for (int i = 0; i < nb_Joueur; i++) {
    if ((*nmbMouv)[i] == MIN(*nmbMouv, nb_Joueur)) {
      *player = i;
      printf("Joueur %d à toi de jouer\n", i + 1);
    }
  }
}

int choix_direction(int direction) {
  int result;

  do {
    printf("Veuillez entrer une direction (NORD=1, EST=2, SUD=3, OUEST=4):\n");
    result = scanf("%d", &direction);

    if (result != 1) {
      printf("Entrée invalide. Veuillez entrer un nombre entier.\n");
      clearInputBuffer(); // Vider le buffer d'entrée
    } else if (direction < 1 || direction > 4) {
      printf("Entrée hors limites. Veuillez entrer un nombre entre 1 et 4.\n");
      clearInputBuffer(); // Vider le buffer d'entrée
    } else {
      break; // Entrée valide
    }
  } while (1);

  printf("La direction est %d\n", direction);
  return direction;
}

void deplacement(Robot *robot, Cible *cible, int direction,
                 MurInterdit *mursInterdits, int nombreMursInterdits,
                 char **grille, int hauteur, int largeur) {
  
  int exligne = robot->ligne;
  int excol = robot->col;
  int obstacle = 0;

  switch (direction) {
  case 1: // Nord
    while (robot->ligne > 0) {
      robot->ligne--;
      obstacle = 0;
      for (int i = 0; i < nombreMursInterdits; i++) {
        if (robot->ligne == mursInterdits[i].ligne &&
            robot->col == mursInterdits[i].col) {
          obstacle = 1;
          break;
        }
      }
      if (obstacle)
        break;
    }
    break;
  case 2: // Est
    while (robot->col < largeur - 1) {
      robot->col++;
      obstacle = 0;
      for (int i = 0; i < nombreMursInterdits; i++) {
        if (robot->ligne == mursInterdits[i].ligne &&
            robot->col == mursInterdits[i].col) {
          obstacle = 1;
          break;
        }
      }
      if (obstacle)
        break;
    }
    break;
  case 3: // Sud
    while (robot->ligne < hauteur - 1) {
      robot->ligne++;
      obstacle = 0;
      for (int i = 0; i < nombreMursInterdits; i++) {
        if (robot->ligne == mursInterdits[i].ligne &&
            robot->col == mursInterdits[i].col) {
          obstacle = 1;
          break;
        }
      }
      if (obstacle)
        break;
    }
    break;
  case 4: // Ouest
    while (robot->col > 0) {
      robot->col--;
      obstacle = 0;
      for (int i = 0; i < nombreMursInterdits; i++) {
        if (robot->ligne == mursInterdits[i].ligne &&
            robot->col == mursInterdits[i].col) {
          obstacle = 1;
          break;
        }
      }
      if (obstacle)
        break;
    }
    break;
  default:
    printf("Erreur de déplacement\n");
    return;
  }

  // Mettre à jour la grille
  grille[exligne][excol] = ' '; // Vider l'ancienne position
  grille[robot->ligne][robot->col] = robot->signe; // Mettre le robot à la nouvelle position
}
   


void Points(int *pointsJoueurs, int nb_joueurs, int joueurActuel, int nb_deplacements, int nb_deplacements_effectues, int robotAtteintCible) {

  for (int i = 0; i < nb_joueurs; i++) {
    pointsJoueurs[i] = 0;
  }

  if (robotAtteintCible) {
    if (nb_deplacements_effectues == nb_deplacements) {
      pointsJoueurs[joueurActuel] += 2;
    } else if (nb_deplacements_effectues < nb_deplacements) {
      pointsJoueurs[joueurActuel] -= 1;
    }
  }  else {
    for (int i = 0; i < nb_joueurs; i++) {
      if (i != joueurActuel) {
        pointsJoueurs[i] += 1;
      }
    }
  }
  }

  // Fonction pour gérer le tour du joueur et les mouvements
  void JoueurTour(char **grille, int hauteur, int largeur, Robot *robot, Cible *cible, MurInterdit *mursInterdits, int nombreMursInterdits, int *nmbMouv, int joueurActuel, int *pointsJoueurs, int **MurRandH,
int **MurRandV, int MurH_Cibles[CIBLES][2],
int MurV_Cibles[CIBLES][2]) {
  int direction;
  int deplacementsEffectues = 0;
  int robotAtteintCible = 0;

  while (deplacementsEffectues < nmbMouv[joueurActuel]) {
    direction = choix_direction(direction);
    deplacement(robot, cible, direction, mursInterdits, nombreMursInterdits, grille, hauteur, largeur);
    deplacementsEffectues++;

    if (robot->ligne == cible->ligne && robot->col == cible->col) {
      robotAtteintCible = 1;
      break;
    }
    afficherGrille(grille, hauteur, largeur, MurRandH, MurRandV, MurH_Cibles, MurV_Cibles);
  }

  Points(pointsJoueurs, 4, joueurActuel, nmbMouv[joueurActuel], deplacementsEffectues, robotAtteintCible);
  }


