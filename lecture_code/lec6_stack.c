#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lec6_stack.h"

void stackNew(stack *s) {
        s->logicLen = 0;
	s->allocLen = 4;
        s->elemSize = 4;
        s->elems = (int*)malloc(4*sizeof(int));
        assert(s->elems != NULL);

}
void stackDispose(stack *s) {
    free(s->elems);
}

void stackPush(stack *s, int value) {
    if (s->allocLen == s->logicLen) {
        s->allocLen *= 2;
        s->elems = (int*)realloc(s->elems, 4*s->allocLen);
        assert(s->elems != NULL);
    }
    s->elems[s->logicLen] = value;
    s->logicLen++;
}

int stackPop(stack *s) {
    assert(s->logicLen > 0);
    s->logicLen--;
    return s->elems[s->logicLen];
}
int main() {
        stack s;
        stackNew(&s);
        for (int i = 0; i < 5; i++) {
            stackPush(&s, i);
        }
        printf("%d", stackPop(&s));
        stackDispose(&s);
        return 0;
}

