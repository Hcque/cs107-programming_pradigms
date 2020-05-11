typedef struct {
	int *elems;
        int elemSize;
        int logicLen;
        int allocLen;
} stack;
void StackNew(stack *s);
void StackDispose(stack *s);
void StackPush(stack *s, int value);
void StackPop(stack *s);


