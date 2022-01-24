#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

#define FERME 0
#define OUVERT 1

#define LIGNES 5
#define COLONNES 6

typedef struct pas_s {
    int start_x;
    int start_y;
    int end_x;
    int end_y;
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
    while(answer != 'y') {
        printf("\n");
        printf("test\n");
        new_laby(laby);
        printf_laby(laby);

        printf("Utiliser le labyrinthe ? [y/N] ");
        scanf("%c\n", &answer);
    }
    return 0;
}

int coordonnees(int ligne, int colonne) {
    return LIGNES * ligne + colonne;
}

int init_pas(Pas *pas) {
    printf("0");
    pas->start_x = 0;
    pas->start_y = 1;
    pas->end_x = LIGNES;
    pas->end_y = COLONNES - 1;

    printf("1");
    stack(&pas->path);
    printf("2");
    push(&pas->path, coordonnees(0, 1));
    push(&pas->path, coordonnees(1, 1));
    printf("3");

    toString(&pas->path);
    return 0;
}

int main() {
    int laby[LIGNES * COLONNES];

    srand(time(NULL));
    propose(laby);

    Pas pas;
    init_pas(&pas);

    return 0;
}