#include <assert.h>
#include <stdio.h>
#include "stack.h"

void test_capacity_one_stack(void) {
    Stack stk_instance = stack_new(1);
    Stack *stk = &stk_instance;
    StackResult result;

    assert(stack_empty(stk));
    assert(!stack_full(stk));

    /* Test peek on empty stack */
    stack_peek(stk, &result);
    assert(result.status == STACK_EMPTY);

    /* Test pop on empty stack */
    stack_pop(stk, &result);
    assert(result.status == STACK_EMPTY);

    /* Test push 1 element */
    stack_push(stk, 99.0f, &result);
    assert(result.status == STACK_OK);
    assert(stack_full(stk));

    /* Test push on full stack */
    stack_push(stk, 11.0f, &result);
    assert(result.status == STACK_FULL);

    /* Test peek on non-empty stack */
    stack_peek(stk, &result);
    assert(result.data == 99.0f && result.status == STACK_OK);

    /* Test pop valid element */
    stack_pop(stk, &result);
    assert(result.data == 99.0f && result.status == STACK_OK);

    assert(stack_empty(stk));
}

void test_arbitrary_stack(void) {
    Stack stk_instance = stack_new(0); /* Default to MAX_DEPTH */
    Stack *stk = &stk_instance;
    StackResult result = { 0, RESULT_INVALID };
    int i;

    /* Push until full */
    for (i = 0; i < MAX_DEPTH; ++i) {
        stack_push(stk, (float)i, &result);
        assert(result.status == STACK_OK);
        result.status = RESULT_INVALID;
    }

    /* Overflow attempt */
    stack_push(stk, (float)i, &result);
    assert(result.status == STACK_FULL);

    /* Verify top element via peek */
    for (i = 0; i < MAX_DEPTH; ++i) {
        result.status = RESULT_INVALID;
        stack_peek(stk, &result);
        assert(result.status == STACK_OK);
        assert(result.data == (float)(MAX_DEPTH - 1));
        result.status = RESULT_INVALID;
    }

    /* Pop all items */
    for (i = 0; i < MAX_DEPTH; ++i) {
        stack_pop(stk, &result);
        assert(result.status == STACK_OK);
    }

    assert(stack_empty(stk));
}

int main(void) {
    test_capacity_one_stack();
    test_arbitrary_stack();
    printf("All stack tests passed successfully!\n");
    return 0;
}
