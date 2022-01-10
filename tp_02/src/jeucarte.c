#include <stdio.h>
#include <stdlib.h>

typedef enum liste_numero_carte
{
    Deux,
    Trois,
    Quatre,
    Cinq,
    Six,
    Sept,
    Huit,
    Neuf,
    Dix,
    Valet,
    Dame,
    Roi,
    As,

} valeur_carte;

typedef enum liste_couleur_carte
{
    Trefle,
    Carreau,
    Pique,
    Coeur
} couleur_carte;

typedef struct carte {
    valeur_carte numero;
    couleur_carte couleur;
} Carte;

// remplit le tableau avec les 32 cartes
void initjeu(Carte jeu[]) {

}

// génère un entier aléatoire compris entre 0 et 31
int alea32() {

}

// permute 2 cartes
void permute(Carte *carte1, Carte *carte2) {

}

// mélange les cartes
void melange(Carte jeu[]) {

}

// affiche une carte (valeur, couleur)
void affiche_carte(Carte x) {

}

// affiche N cartes
void affiche(Carte jeu[], int N) {

}

// distribue les cartes aux deux joueurs
void distribue(Carte jeu[], Carte jeu1[], Carte jeu2[]) {

}

// gère le résultat d'une bataille (1 coup)
void joue1coup(Carte jeu1[], Carte jeu2[], int *N1, int *N2) {

}

int main() {
    Carte jeu[32];
    Carte jeu1[32]; // cartes du joueur 1
    Carte jeu2[32];
    int N1 = 15; // indice de la dernière carte joueur 1
    int N2 = 15;

    initjeu(jeu);
    srand(12500);
    melange(jeu);
    distribue(jeu, jeu1, jeu2);

    while() {
        // tant que la partie n'est pas terminée
        joue1coup(jeu1, jeu2, &N1, &N2);
    }

    // affiche qui gagne et en combien de coups
    return 0;
}
