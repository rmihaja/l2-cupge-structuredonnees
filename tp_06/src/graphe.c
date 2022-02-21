#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "graphe.h"

// properties

struct s_arc {
    Sommet debut;
    Sommet fin;
    char *etiquette;
};

struct s_sommet {
    char *nom;
    // Arc *arcs;
    int etiquette;
};

struct s_graphe {
    Sommet* sommets;
    int** relation;
    int** matriceAdjacence;
    int taille;
};

// * constructor

int** initMatriceAdjacence(int taille) {
    int** adjacence = (int**) malloc( sizeof(int*));
    for (int i = 0; i < taille; i++) {
        adjacence[i] = (int*) malloc (taille * sizeof(int));
    }

    for (int i; i < taille; i++) {
        for (int j; j < taille; j++) {
            adjacence[i][j] = 0;
        }
    }

    return adjacence;
}

/**
 * @brief Permet d'ajouter des sommets au graphe
 *
 * @param sommet
 */
Graphe initGraphe(void) {
    Graphe G = (Graphe) malloc(sizeof(struct s_graphe));

    G ->sommets = NULL;
    G->taille = 0;
    G->matriceAdjacence = getMatriceAdjacence(G);

    return G;
}

Arc initArc(char* nom_debut, char* nom_fin) {
    Sommet debut = (Sommet) malloc(sizeof(struct s_sommet));
    debut->nom = nom_debut;
    debut->etiquette = NULL;

    Sommet fin = (Sommet) malloc(sizeof(struct s_sommet));
    fin->nom = nom_fin;
    fin->etiquette = NULL;

    Arc arc = (Arc) malloc(sizeof(struct s_arc));
    arc->debut = debut;
    arc->fin = fin;
    arc->etiquette = NULL;

    return arc;
}

// * methods

// matrice adjacence


/**
 * @brief ajoute l'arc a au graphe
 *
 * @param a
 * @param G
 */
void ajouteArc(Arc a, Graphe G) {
    if (isEmpty(G)) {
        G->taille += 2;
        G->matriceAdjacence = getMatriceAdjacence(G->taille);

        a->debut->etiquette = 1;
        a->fin->etiquette = 2;
        a->etiquette = "12";

        // G->sommets
    }

}

/**
 * @brief supprime l'arc au graphe
 *
 * @param a
 * @param g
 */
void supprimeArc(Arc a, Graphe g) {

}

/**
 * @brief retourne 1 si le sommet s existe dans le graphe
 *
 * @param s
 * @param G
 * @return int
 */
int existeSommet(Sommet s, Graphe G) {
    int isIn = 0;
    for (int i = 0; i < G->taille && isIn == 0; i++) {
        if (strcmp(G->sommets[i]->nom, s->nom)) {
            isIn = 1;
        }
    }
    return isIn;
}

/**
 * @brief retourne 1 si l'arc a existe dans le graphe
 *
 * @param a
 * @param G
 * @return int
 */
int existeArc(Arc a, Graphe G) {
    if (existeSommet(a->debut, G) && existeSommet(a->fin, G)) {
        return 1;
    }
    return 0;
}


// * fonctions auxiliaires

/**
 * @brief retourne 0 si G est vide, >= 1 sinon
 *
 * @param G
 * @return int
 */
int isEmpty(Graphe G) {
    return G->taille;
}