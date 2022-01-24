#define STACK_SIZE 30

typedef struct pile_s {
    int t[STACK_SIZE];
    int sommet;
} Stack;

void stack(Stack *pile);
int push(Stack *pile, int n);
int pop(Stack *pile);
int top(Stack *pile);
int get(Stack *pile, int i);
int isIn(Stack *pile, int n);
int toString(Stack *pile);

int isEmpty(Stack *pile);
