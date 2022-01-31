#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pile.h"

typedef struct node_s {
    int value;
    struct node_s *next;
} *Node;

struct stack_s {
    Node top;
    int size;
};

Stack stack() {
    Stack stack = (Stack) malloc(sizeof(struct stack_s));
    stack->size = 0;
    return stack;
}

// 0 := vide
// 1 := non vide
int isEmpty(Stack stack) {
    if (stack->size == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int size(Stack stack) {
    return stack->size;
}

// 0 := element dedans
// 1 := element non dedans
int isIn(Stack stack, int n) {
    Node current_node = stack->top;
    while (current_node != NULL) {
        if (current_node->value == n) {
            return 0;
        }
        current_node = current_node->next;
    }
    return 1;
}

Stack push(Stack stack, int n)
{
    Node new_top = (Node)malloc(sizeof(struct node_s));
    new_top->value = n;
    if (isEmpty(stack)) {
        stack->top = new_top;
        stack->size++;
    }
    else {
        if (isIn(stack, n) == 1) {
            new_top->next = stack->top;
            stack->top = new_top;
            stack->size++;
        }
    }

    return stack;
}
Stack pop(Stack stack) {
    assert(isEmpty(stack));

    Node old_top = stack->top;
    stack->top = stack->top->next;
    free(old_top);

    stack->size--;

    return stack;
}

int top(Stack stack) {
    assert(isEmpty(stack));

    return stack->top->value;
}

#ifdef DEBUG

int
main() {
    Stack p;
    stack(&p);
}

#endif