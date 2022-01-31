#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack_s *Stack;

Stack stack();

Stack push(Stack, int);
Stack pop(Stack);
int size(Stack);
int isEmpty(Stack);
int top(Stack);

#endif
