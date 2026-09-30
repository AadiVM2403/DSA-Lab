#ifndef _INCLUDED_STACK_H_
#define _INCLUDED_STACK_H_

#include <stdint.h>

#define MAX_DEPTH 32

/* Stack data structure */
struct _Stack {
    int32_t size;               /* Requested stack depth */
    int32_t top;                /* Index of the top element */
    float data[MAX_DEPTH];      /* Actual content array */
};

typedef struct _Stack Stack;

/* Status bits used in result structure */
#define RESULT_INVALID 0
#define STACK_OK       1
#define STACK_FULL     2
#define STACK_EMPTY    4

/* Operation result container */
struct _Stack_Result {
    float data;
    int32_t status;
};

typedef struct _Stack_Result StackResult;

/* Abstract Data Type (ADT) Interface */
Stack stack_new(int32_t size);
int32_t stack_full(const Stack *stk);
int32_t stack_empty(const Stack *stk);

Stack* stack_push(Stack *stk, float data, StackResult *result);
Stack* stack_pop(Stack *stk, StackResult *result);
Stack* stack_peek(const Stack *stk, StackResult *result);

#endif /* _INCLUDED_STACK_H_ */
