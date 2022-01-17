#include <stdio.h>
#include <stdlib.h>
#define NBRE_CARTE 32;

typedef enum liste_numero_carte
{
    SEPT = 0,
    HUIT = 1,
    NEUF = 2,
    DIX = 3,
    VALET = 4,
    DAME = 5,
    ROI = 6,
    AS = 7,

} valeur_carte;

typedef enum liste_couleur_carte
{
    TREFLE = 0,
    CARREAU = 1,
    PIQUE = 2,
    COEUR = 3,
} couleur_carte;

typedef struct carte {
    valeur_carte numero;
    couleur_carte couleur;
} Carte;

// remplit le tableau avec les 32 cartes
void initjeu(Carte jeu[]) {
    int carte_init = 0;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            jeu[carte_init].numero = j;
            jeu[carte_init].couleur = i;
            carte_init++;
        }
    }
}

// génère un entier aléatoire compris entre 0 et 31
int alea32() {
    return rand() % 32;
}

// permute 2 cartes
void permute(Carte *carte1, Carte *carte2) {
    // affiche_carte(*carte1);
    // affiche_carte(*carte2);

    Carte carte = *carte1;
    *carte1 = *carte2;
    *carte2 = carte;
    // free(carte);
}

// mélange les cartes
void melange(Carte jeu[]) {
    int shuffle = 0;
    do {
        permute(jeu + alea32(), jeu + alea32());
    } while (++shuffle < 50);
}

// affiche une carte (valeur, couleur)
void affiche_carte(Carte x) {
    switch (x.numero)
    {
    case SEPT:
        printf("Sept");
        break;
    case HUIT:
        printf("Huit");
        break;
    case NEUF:
        printf("Neuf");
        break;
    case DIX:
        printf("Dix");
        break;
    case VALET:
        printf("Valet");
        break;
    case DAME:
        printf("Dame");
        break;
    case ROI:
        printf("Roi");
        break;
    case AS:
        printf("As");
        break;

    default:
        printf("undefined");
        break;
    }

    printf(" de ");

    switch (x.couleur)
    {
    case TREFLE:
        printf("Trèfle");
        break;
    case CARREAU:
        printf("Carreau");
        break;
    case PIQUE:
        printf("Pique");
        break;
    case COEUR:
        printf("Coeur");
        break;

    default:
        printf("undefined");
        break;
    }

    printf("\n");
}

// affiche N cartes
void affiche(Carte jeu[], int N) {
    for (int i = 0; i < N; i++)  {
        affiche_carte(jeu[i]);
    }
}

// distribue les cartes aux deux joueurs
void distribue(Carte jeu[], Carte jeu1[], Carte jeu2[]) {
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < 32; i++)
    {
        if (i % 2 == 0) {
            jeu1[n1] = jeu[i];
            n1++;
        }
        else {
            jeu2[n2] = jeu[i];
            n2++;
        }
    }

}

// gère le résultat d'une bataille (1 coup)
void joue1coup(Carte jeu1[], Carte jeu2[], int *N1, int *N2) {
    Carte *gagnant;
    Carte *perdant;
    int *n_gagnant;
    int *n_perdant;

    printf("\nCarte du joueur 1: ");
    affiche_carte(jeu1[0]);
    printf("Carte du joueur 2: ");
    affiche_carte(jeu2[0]);
    printf("Résultat:\n");

    if (jeu1[0].numero > jeu2[0].numero || (jeu1[0].numero == jeu2[0].numero && jeu1[0].couleur > jeu2[0].couleur))
    {
        printf("J1 gagne la manche\n");
        gagnant = jeu1;
        n_gagnant = N1;
        perdant = jeu2;
        n_perdant = N2;
    }
    else if (jeu1[0].numero < jeu2[0].numero || (jeu1[0].numero == jeu2[0].numero && jeu1[0].couleur < jeu2[0].couleur))
    {
        printf("    J2 gagne la manche\n");
        gagnant = jeu2;
        n_gagnant = N2;
        perdant = jeu1;
        n_perdant = N1;
    }
    else {
        for (int i = 0; i < *N1; i++) {
            permute(jeu1 + i, jeu1 + i + 1);
        }
        for (int i = 0; i < *N2; i++) {
            permute(jeu2 + i, jeu2 + i + 1);
        }
        return;
    }

    *(n_gagnant) += 1;
    gagnant[*n_gagnant] = jeu2[0];
    for (int i = 0; i < *n_gagnant; i++) {
        permute(gagnant + i, gagnant + i + 1);
    }
    for (int i = 0; i < *n_perdant; i++) {
        permute(perdant + i, perdant + i + 1);
    }
    *(n_perdant) -= 1;
    printf("    J1: %d cartes\n    J2: %d cartes\n", *N1, *N2);
}

int main() {
    Carte jeu[32];
    Carte jeu1[32]; // cartes du joueur 1
    Carte jeu2[32];
    int N1 = 15; // indice de la dernière carte joueur 1
    int N2 = 15;

    initjeu(jeu);
    srand(time(NULL));
    melange(jeu);

    printf("Deck:");
    affiche(jeu, 32);

    distribue(jeu, jeu1, jeu2);

    int manche = 1;
    while (N2 != 0 && N1 != 0)
    {
        manche++;
        // tant que la partie n'est pas terminée
        joue1coup(jeu1, jeu2, &N1, &N2);
    }
    printf("\nJeu terminé!\n");
    printf("Manche joué : %d\n", manche);



    // affiche qui gagne et en combien de coups
    return 0;
}
