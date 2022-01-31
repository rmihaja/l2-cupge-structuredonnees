#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

#define FERME 0
#define OUVERT 1
#define PARCOURU 2

#define LIGNES 5
#define COLONNES 6

// typedef enum possible_neighbors_list {
//     above =
// }

typedef struct pas_s {
    int start;
    int end;
    Stack path;
} Pas;

int isPath() {
    return rand() % 2;
}

int new_laby(int *laby) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            // ferme les contours du labyrinthe
            if ((i == 0) || (j == 0) || (j == COLONNES - 1) || (i == LIGNES - 1)) {
                *(laby + (i * LIGNES) + j) = FERME;
            }
            else {
                *(laby + (i * LIGNES) + j) = isPath();
            }
        }
    }
    *(laby + 1) = OUVERT;
    *(laby + LIGNES * LIGNES - 1) = OUVERT;
    return 0;
}

int printf_laby(int *laby) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++)
        {
            if (*(laby + (i * LIGNES) + j) == FERME) {
                printf("X");
            }
            else if (*(laby + (i * LIGNES) + j) == PARCOURU) {
                printf("o");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int propose(int *laby) {
    char answer;
    // while(answer != 'y') {
        new_laby(laby);
        printf_laby(laby);

        printf("Utiliser le labyrinthe ? [y/N] y\n");
        // scanf("%c\n", &answer);
        // printf("Votre réponse : %c\n", answer);
    // }
    return 0;
}

int coordonnees(int ligne, int colonne) {
    return LIGNES * ligne + colonne;
}

int init_pas(Pas *pas) {
    pas->start = coordonnees(0, 1);
    pas->end = coordonnees(LIGNES - 1, COLONNES - 2);

    pas->path = stack();

    push(pas->path, pas->start);
    push(pas->path, coordonnees(1, 1));

    return 0;
}

Pas *parcourir(int *laby, Pas *pas) {
    // MST
    while (size(pas->path) > 2 || top(pas->path) != pas->end) {
        int left = top(pas->path) - 1;
        int right = top(pas->path) + 1;
        int above = top(pas->path) - COLONNES + 1;
        int bottom = top(pas->path) + COLONNES;

            // check left
        if (laby[left] == OUVERT)
        {
            laby[left] = PARCOURU;
            push(pas->path, left);
        }
        // check right
        else if (laby[right] == OUVERT) {
            laby[right] = PARCOURU;
            push(pas->path, right);
        }
        // check above
        else if (laby[above] == OUVERT && above != coordonnees(0, 1)) {
            laby[above] = PARCOURU;
            push(pas->path, above);
        }
        // check bottom
        else if (laby[bottom] == OUVERT) {
            laby[bottom] = PARCOURU;
            push(pas->path, bottom);
        }
        else {
            // node is dead end
            printf("Aucun chemin pour le node");
            laby[top(pas->path)] = OUVERT;
            pop(pas->path);
        }

        printf("Avancement du parcours :\n");
        printf_laby(laby);
    }

    return pas;

    // DFS
}

int printf_solution(int *laby, Stack path) {
    while(size(path) > 0) {
        laby[top(path)] = PARCOURU;
        pop(path);
    }
    printf_laby(laby);
    return 0;
}

int main() {
    int laby[LIGNES * COLONNES];

    srand(time(NULL));
    propose(laby);

    Pas pas;
    init_pas(&pas);
    parcourir(laby, &pas);

    if(size(pas.path) > 0) {
        printf("Bravo, un chemin a été trouvé!\n");
        printf_solution(laby, pas.path);
    } else {
        printf("Le labyrinthe n'a pas de solution");
    }

    return 0;
}