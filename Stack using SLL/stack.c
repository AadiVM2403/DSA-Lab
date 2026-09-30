#include <assert.h>
#include <stddef.h>
#include "stack.h"

/* Pass objects by reference for efficiency */
Stack stack_new(int32_t size) {
    size = (size > 0 && size < MAX_DEPTH) ? size : MAX_DEPTH;
    Stack s = { size, -1, {0} };
    return s;
}

int32_t stack_full(const Stack *stk) {
    assert(stk != NULL);
    return (stk->top == stk->size - 1);
}

int32_t stack_empty(const Stack *stk) {
    assert(stk != NULL);
    return (stk->top == -1);
}

Stack* stack_push(Stack *stk, float data, StackResult *result) {
    assert(stk != NULL);
    if (stk->top + 1 < stk->size) {
        stk->top++;
        stk->data[stk->top] = data;
        result->data = data;
        result->status = STACK_OK;
    } else {
        result->data = data;
        result->status = STACK_FULL;
    }
    return stk;
}

Stack* stack_pop(Stack *stk, StackResult *result) {
    assert(stk != NULL);
    if (stk->top > -1) {
        result->data = stk->data[stk->top];
        result->status = STACK_OK;
        stk->top--;
    } else {
        result->status = STACK_EMPTY;
    }
    return stk;
}

Stack* stack_peek(const Stack *stk, StackResult *result) {
    assert(stk != NULL);
    if (stk->top > -1) {
        result->data = stk->data[stk->top];
        result->status = STACK_OK;
    } else {
        result->status = STACK_EMPTY;
    }
    return stk;
}
