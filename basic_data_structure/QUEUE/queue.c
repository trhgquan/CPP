/**
 * Queue implementation, using doubly-linked-list.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Structure of a doubly-linked-list node.
 */
struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} typedef Node;

/**
 * Structure of a queue.
 */
struct Queue {
    Node* head;
    Node* tail;
} typedef Queue;

/**
 * This function initalise a new queue.
 * @return pointer to the newly-created queue.
 */
Queue* initQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

/**
 * Create a new doubly-linked node.
 * @param  value value of the new node.
 * @return       pointer to the newly-created node.
 */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Set value to the new node.
    newNode->value = value;
    // Default next and prev node will be NULL.
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/**
 * This function check if a queue is empty or not.
 * @param  q queue to check.
 * @return   1 if the queue is empty, 0 otherwise.
 */
int isEmpty(Queue q) {
    return q.head == NULL;
}

/**
 * Get the front node of the queue.
 * @param  q queue
 * @return   pointer to the front node.
 */
Node* front(Queue q) {
    return q.head;
}

/**
 * Add a value to the queue.
 * @param q     pointer to the queue.
 * @param value value to add.
 */
void enqueue(Queue* q, int value) {
    // Create a new node.
    Node* newNode = createNode(value);

    if (isEmpty(*q)) {
        // If the queue is currently empty, then the first will also be the last node.
        q->head = newNode;
        q->tail = newNode;
    } else {
        // Else, insert the new node to the tail.
        newNode->prev = q->tail;
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

/**
 * Remove the front node of the queue.
 * @param  q pointer to the queue.
 */
void dequeue(Queue* q) {
    Node* frontValue = front(*q);

    if (frontValue->next == NULL) {
        // This is the last node, so deleting it makes the queue empty.
        q->head = NULL;
        q->tail = NULL;
    } else {
        // Next node will become the head node.
        q->head = frontValue->next;
        frontValue->next->prev = NULL;
    }

    free(frontValue);
}

/**
 * This function free all memory allocated for the queue.
 * @param q pointer to the queue.
 */
void freeQueue(Queue* q) {
    // While the queue is not empty, dequeue.
    while (q->head != NULL) dequeue(q);

    // then free the queue.
    free(q);
}

/**
 * This function print all elements in the queue.
 * @param q queue to print.
 */
void printQueue(Queue q) {
    Node* thisNode = q.head;
    while (thisNode != NULL) {
        printf("%d ", thisNode->value);
        thisNode = thisNode->next;
    }
    printf("\n");
}

/**
 * This function print the menu to console.
 */
void printConsoleInfo() {
    printf("Here are things that you can do with the holy queue:\n");
    printf("1. Enqueue.\n");
    printf("2. Dequeue.\n");
    printf("3. Print queue.\n");
    printf("4. Free all queue (yey!) and exit.\n");
}

int main() {
    int ans = -1;
    Queue* queue = initQueue();
    do {
        printConsoleInfo();
        printf("Your choice: "); scanf("%d", &ans);
        switch (ans) {
            case 1: {
                int data;
                printf("Data to add to queue: "); scanf("%d", &data);
                enqueue(queue, data);
                break;
            }
            case 2: {
                if (!isEmpty(*queue)) {
                    dequeue(queue);
                    printf("Queue popped!\n");
                } else printf("Queue is empty!\n");
                break;
            }
            case 3: {
                if (isEmpty(*queue)) {
                    printf("Queue is empty!\n");
                    break;
                }

                printQueue(*queue);
                break;
            }
            case 4: {
                freeQueue(queue);
                break;
            }

            default: continue;
        }
        system("pause"); system("cls");
        if (ans == 4) break;
    } while (1);

    return 0;
}
