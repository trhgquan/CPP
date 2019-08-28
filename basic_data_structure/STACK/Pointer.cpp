/**
 * This program implement Stack using pointer.
 * To use custom data, please check the comments below.
 * (This file use stack_pointer.inp)
 */

#include <stdio.h>
#include <stdlib.h>

typedef int item;

// Read data from file.
FILE *fo = fopen("stack_pointer.inp", "r+");

struct Node {
    item data;
    Node *next;
};

struct Stack {
    Node *top;
};

void Init(Stack &s);
void Push(Stack &s, item x);
int Peek(Stack s);
int Pop(Stack &s);
int Len(Stack s);
Node *MakeNode(item x);
bool isEmpty(Stack s);

void Input(Stack &s) {
    // Uncomment to import data manually.
    // int i = 0;
    item x;

    do {
        // Uncomment to import data manually
        // i++;
        // printf("Items number %d: ", i);
        // scanf("%d", &x);
        fscanf(fo, "%d", &x);
        if (x != 0) Push(s, x);
    } while (x != 0); // Input ends when user type 0.
}

void Output(Stack s) {
    Node *p = s.top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    Stack S;
    Init(S);
    Input(S);
    Output(S);

    int choice;
    printf("Here are things you can do with the Stack:");
    printf("\n1: Check if the stack is empty");
    printf("\n2: Get the stacks length");
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
                printf("Stacks length: %d", Len(S));
                break;
            }
            case 3: {
                item x;
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
    s.top = NULL;
}

void Push(Stack &s, item x) {
    Node *p = MakeNode(x);
    p->next = s.top;
    s.top = p;
}

int Peak(Stack s) {
    return s.top->data;
}

int Pop(Stack &s) {
    if (!isEmpty(s)) {
        item x = s.top->data;
        s.top = s.top->next;
        return x;
    }
    return 0;
}

int Len(Stack s) {
    Node *p = s.top;
    int i = 0;

    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

Node *MakeNode(item x) {
    Node *p = (Node*) malloc(sizeof(Node));
    p->next = NULL;
    p->data = x;
    return p;
}

bool isEmpty(Stack s) {
    return (s.top == NULL);
}
