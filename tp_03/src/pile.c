#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pile.h"

void stack(Stack *pile) {
    pile->sommet = -1;
    return;
}

// ? méthode élémentaire
// 0 := vide
// 1 := non vide
int isEmpty(Stack *pile) {
    if(top(pile) == -1) {
        return 0;
    }
    return 1;
}

int push(Stack *pile, int n) {
    // ? vérification qu'on peut empiler
    // * implémentation assert
    assert(top(pile) < STACK_SIZE - 1);

    // empilation
    pile->t[++pile->sommet] = n;
    return 0;
}

int pop(Stack *pile) {
    // * implémentation assert
    assert(!isEmpty(pile));

    // suppression
    pile->sommet--;
    return 0;
}

int top(Stack *pile) {
    assert(!isEmpty(pile));
    return pile->sommet;
}

int get(Stack *pile, int i) {
    return pile->t[i];
}

// 0 := is in
// 1 := is not in
int isIn(Stack *pile, int n)
{
    assert(!isEmpty(pile));
    for (int i = 0; i < top(pile); i++) {
        if (get(pile, i) == n) {
            return 0;
        }
    }
    return 1;
}

int toString(Stack *pile) {
    assert(!isEmpty(pile));
    printf("[");
    for (int i = 0; i < top(pile) - 1; i++)
    {
        printf("%d, ", get(pile, i));
    }
    printf("%d]\n", get(pile, top(pile)));
}

#ifdef DEBUG

int main() {
    Stack p;
    stack(&p);
}

#endif