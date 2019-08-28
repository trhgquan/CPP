/**
 * This program implement Stack using array.
 * To use custom data, please check the comments below.
 */

#include <stdio.h>

#define MAX 100 // maximum stack size is 100 items
typedef int item; // item has type int.

struct Stack {
    int top;
    item data[MAX];
};

// Read data from file.
FILE *fo = fopen("stack.inp", "r+");

void Init(Stack &s);
void Push(Stack &s, item x);
int Pop(Stack &s);
int Peek(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);

void Input(Stack &s) {
    int n;
    item x;

    /**
     * To manually import data, uncomment some codes below.
     */

    // Uncomment to import data manually
    // do {
    //     printf("Stack items (< %d): ", MAX);
    //     scanf("%d", &n);
    // } while (n > MAX || n < 1);
    fscanf(fo, "%d", &n);

    for (int i = 0; i < n; ++i) {
        // Uncomment to manually import data
        // printf("Item number %d: ", i + 1);
        // scanf("%d", &x);
        fscanf(fo, "%d", &x);
        Push(s, x);
    }
}

void Output(Stack s) {
    for (int i = s.top - 1; i >= 0; --i)
        printf("%d ", s.data[i]);
    printf("\n");
}

int main(int argc, char const *argv[]) {
    Stack S;
    Init(S);
    Input(S);
    Output(S);

    int choice;
    printf("Here are things you can do with the stack:");
    printf("\n1: Check if the stack is empty");
    printf("\n2: Check if the stack is full");
    printf("\n3: Add an item to stack");
    printf("\n4: Pop an item out of stack");
    printf("\n5: Print the stack");
    printf("\n6: Exit");

    do {
        printf("\nYou choose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                if (isEmpty(S)) printf("The stack is empty");
                else printf("The stack is not empty");
                break;
            }
            case 2: {
                if (isFull(S)) printf("The stack is full");
                else printf("The stack is not full");
                break;
            }
            case 3: {
                int x;
                printf("Add an item to stack: ");
                scanf("%d", &x);
                Push(S, x);
                break;
            }
            case 4: {
                Pop(S);
                break;
            }
            case 5: {
                Output(S);
                break;
            }
            case 6: break;
        }
    } while (choice != 6);
    return 0;
}

void Init(Stack &s) {
    s.top = 0;
}

void Push(Stack &s, item x) {
    if (!isFull(s)) {
        s.data[s.top] = x;
        s.top++;
    }
}

int Peak(Stack &s) {
    return s.data[s.top - 1];
}

int Pop(Stack &s) {
    if (!isEmpty(s)) {
        s.top--;
        return s.data[s.top];
    }
    return 0;
}

bool isEmpty(Stack s) {
    return (s.top == 0);
}

bool isFull(Stack s) {
    return (s.top == MAX);
}
