#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

// 0 := non vide
// 1 := vide
int isEmpty(Stack stack) {
    if (stack->size == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int size(Stack stack) {
    return stack->size;
}

// 0 := element non dedans
// 1 := element dedans
int isIn(Stack stack, int n) {
    assert(isEmpty(stack) == 0);
    Node current_node = stack->top;
    while (current_node != NULL) {
        if (current_node->value == n) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

Stack push(Stack stack, int n)
{
    Node new_top = (Node)malloc(sizeof(struct node_s));
    new_top->value = n;
    if (isEmpty(stack) == 1) {
        stack->top = new_top;
        stack->size++;
    }
    else {
        if (isIn(stack, n) == 0) {
            new_top->next = stack->top;
            stack->top = new_top;
            stack->size++;
        }
    }
    return stack;
}
Stack pop(Stack stack) {
    assert(isEmpty(stack) == 0);

    Node old_top = stack->top;
    stack->top = old_top->next;
    free(old_top);

    stack->size--;

    return stack;
}

int top(Stack stack) {
    printf("%s", toString(stack));
    assert(isEmpty(stack) == 0);

    return stack->top->value;
}

char *toString(Stack stack) {
    if (isEmpty(stack)) {
        return "[]";
    }
    char *result = "[";
    Node current_top = stack->top;
    while (current_top->next != NULL) {
        sprintf(result, "%d", current_top->value);
        strcat(result, ", ");
        current_top = current_top->next;
    }
    sprintf(result, "%d", current_top->value);
    return strcat(result, "]");
}

#ifdef DEBUG

int
main() {
    Stack p;
    stack(&p);
    push(p, 5);
    push(p, 7);
    top(p);
}

#endif