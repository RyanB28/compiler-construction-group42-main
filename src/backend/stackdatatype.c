
typedef struct Stack {
    char** data;
    int top;
    int size;
} Stack;

void initStack(Stack stack, int size) {
    stack.data = (char**)malloc(size * sizeof(char*));
    stack.top = -1;
    stack.size = size;
}

int isStackFull(Stack stack) {
    return stack.top == stack.size - 1;
}

void pushStack(Stack stack, const char* value) {
    if (isStackFull(stack)) {
        stack.size *= 2;
        stack.data = (char**)realloc(stack.data, stack.size * sizeof(char*));
    }
    stack.top++;
    stack.data[stack.top] = strdup(value);
}

char* popStack(Stack stack) {
    if (stack.top == -1) {
        return 0x0;
    }
    char* value = stack.data[stack.top];
    stack.top--;
    return value;
}
