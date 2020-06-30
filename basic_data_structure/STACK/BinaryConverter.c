/**
 * This program convert decimal to binary, using stack.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Structure of a node.
 */
struct Node {
    int value;
    struct Node* next;
} typedef Node;

/**
 * Structure of a stack, with top node.
 */
struct Stack {
    struct Node* top;
} typedef Stack;

/**
 * Inititalise a stack
 * @return pointer to newly-created stack.
 */
Stack* initStack() {
    // Basically this is creating a new linked list.
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

/**
 * Create a node (linked list).
 * @param  value value of the node.
 * @return       pointer to the newly-created node.
 */
Node* createNode(int value) {
    // Basically, this is creating a new linked-list node.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

/**
 * Check if the stack is empty or not.
 * @param  s stack to check.
 * @return   1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack s) {
    return s.top == NULL;
}

/**
 * Get the stack's top.
 * @param  s stack to get.
 * @return   value of the stack's top.
 */
int peek(Stack s) {
    return s.top->value;
}

/**
 * Pop the top node out of the stack.
 * @param s pointer to the stack.
 */
void pop(Stack* s) {
    // Basically, this is deleteing a node at the head of linked list.
    Node* newTop = s->top->next;
    free(s->top);
    s->top = newTop;
}

/**
 * Push value to the stack.
 * @param s     stack.
 * @param value value to push.
 */
void push(Stack* s, int value) {
    // Basically, this is inserting a node to head of linked list.
    Node* newNode = createNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

int main() {
    printf("Decimal to convert to binary: ");
    int decimal; scanf("%d", &decimal);

    Stack* binaryStack = initStack();

    // Insert binary to stack.
    while (decimal > 0) {
        push(binaryStack, decimal % 2);
        decimal /= 2;
    }

    // Display the binary.
    while (!isEmpty(*binaryStack)) {
        printf("%d", peek(*binaryStack));
        pop(binaryStack);
    }

    free(binaryStack);
    return 0;
}
