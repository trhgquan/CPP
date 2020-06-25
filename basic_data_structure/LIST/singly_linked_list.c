/**
 * Singly Linked List (data structure).
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Node struct.
 */
struct node {
    int value;
    struct node* next;
} typedef node;

/**
 * This struct store the linked list.
 * with node* head is the first node.
 */
struct linkedList {
    struct node* head;
} typedef linkedList;

/**
 * This function create and initialise a linked list.
 * @return pointer to a newly-created linked list.
 */
linkedList* createLinkedList() {
    // Allocate memory for the list.
    linkedList* list = (linkedList*)malloc(sizeof(linkedList));

    // Update head of list to NULL.
    list->head = NULL;

    // Return the list.
    return list;
}

/**
 * This function create a node.
 *
 * @param  value value of the node.
 * @return       pointer to the newly-created node.
 */
node* createNode(int value) {
    // Allocate memory for the new node.
    node* temp = (node*)malloc(sizeof(node));

    // Set that node's value.
    temp->value = value;

    // Since we are inserting nodes to the end of linked list,
    // next node at this time will be NULL.
    temp->next  = NULL;

    // Return the newly-created node.
    return temp;
}

/**
 * Find last node of a linked list.
 * @param  list a variable storing a linked list.
 * @return      pointer to the last node of that linked list.
 */
node* getLastNode(linkedList list) {
    node* lastNode = list.head;

    // Get list last node.
    while (lastNode->next != NULL) lastNode = lastNode->next;

    // Return last node.
    return lastNode;
}

/**
 * This function insert value to the front of a linked list,
 * return a pointer to a node, since this new node will become
 * the new linked list-leader node.
 *
 * @param  linkedList pointer to the linked list.
 * @param  value      value to insert.
 * @return            pointer to the new node - new linked list front node.
 */
void insertToFront(linkedList* linkedList, int value) {
    node* newNode = createNode(value);

    // New node's next will be linked list current head.
    newNode->next = linkedList->head;

    // Linked list head will become the new node.
    linkedList->head = newNode;
}

/**
 * This function insert value to the back of a linked addToList.
 *
 * @param linkedList pointer to the linked list.
 * @param value      value to insert.
 */
void insertToBack(linkedList* linkedList, int value) {
    // Get last node of current list.
    node* lastNode = getLastNode(*linkedList);

    // If the list is empty, insert to front aka first node.
    if (lastNode == NULL) {
        printf("Last node is NULL\n");
        insertToFront(linkedList, value);
    }
    else {
        // Create a new node.
        node* newNode = createNode(value);

        // Point current last node to new node,
        // make the new node become the last node.
        lastNode->next = newNode;
    }

}

/**
 * Insert a value to the linked list.
 *
 * @param linkedList     pointer to the linked list.
 * @param linkedListSize size of linked list.
 * @param value          value of new element.
 * @param position       position to insert into linked list.
 * @Return               new updated linked list.
 */
void insertToList(linkedList* linkedList, int* linkedListSize, int value, int position) {
    if (position == 0)
        insertToFront(linkedList, value);
    else if (position == *linkedListSize)
        insertToBack(linkedList, value);
    else {
        // Create a new node.
        node* newNode = createNode(value);

        // Variable to store previous node.
        node* prevNode = linkedList->head;

        // Position of previous node.
        int pos = 0;

        // Get previous node.
        while (pos < position - 1) {
            ++pos;
            prevNode = prevNode->next;
        }

        // Insert new node to list.
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    ++(*linkedListSize);
}

/**
 * This function delete the head node of a list.
 * @param linkedList pointer to the linked list.
 */
void deleteHeadNode(linkedList* linkedList) {
    // Get next node of the head node.
    node* head = linkedList->head->next;

    // Free the head node.
    free(linkedList->head);

    // Update new head node.
    linkedList->head = head;
}

/**
 * This function delete the last node of list.
 * @param linkedList pointer to the linked list.
 */
void deleteLastNode(linkedList* linkedList) {
    node* lastNode = getLastNode(*linkedList);
    free(lastNode);
}

/**
 * Delete a node at a position
 * @param linkedList     Pointer to the linked list.
 * @param linkedListSize Pointer to the linked list size.
 * @param position       Position to delete.
 */
void deletePositionNode(linkedList* linkedList, int* linkedListSize, int position) {
    // Delete the first position
    if (position == 0) deleteHeadNode(linkedList);
    // Delete the last position
    else if (position == *linkedListSize) deleteLastNode(linkedList);
    else {
        // Pointer to the previous node
        node* prevNode = linkedList->head;

        // Current position
        int currentPos = 0;

        // Get the previous node.
        while (currentPos < position - 1) {
            ++currentPos;
            prevNode = prevNode->next;
        }

        // Get new next node.
        node* nextNode = prevNode->next->next;

        // Delete a node.
        free(prevNode->next);

        // And update the order.
        prevNode->next = nextNode;

    }
    --(*linkedListSize);
}

/**
 * This function print the linked list to console.
 * Notice that we just need the first node of all list.
 *
 * @param firstNode pointer to the first node.
 */
void printList(linkedList list) {
    node* currentNode = list.head;
    // While the current node is not the end.
    while (currentNode != NULL) {
        // Print to the console.
        printf("%d ", currentNode->value);

        // Jump to next node.
        currentNode = currentNode->next;
    }
    printf("\n");
}

/**
 * This function release memory allocated to a linked list.
 *
 * @param linkedList pointer to the linked list.
 */
void releaseLinkedList(linkedList* list) {
    while (list->head != NULL) deleteHeadNode(list);
    free(list); list = NULL;
}

int main() {
    // Get total elements.
    printf("Total elements of the linked list: ");
    int x; int n; scanf("%d", &n);

    // First node of the linked list.
    linkedList* list = createLinkedList();

    // Add nodes to the linked list.
    for (int i = 0; i < n; ++i) {
        printf("Element no.%d: ", i + 1); scanf("%d", &x);
        if (i == 0) insertToFront(list, x);
        else insertToBack(list, x);
    }

    // Get the position and value of the new element.
    int position = -1;
    do {
        printf("Position to insert new element: "); scanf("%d", &position);
        if (position < 0 || position > n) {
            printf("Notice that 0 <= position <= %d\n", n);
            continue;
        }
        printf("New element\'s value: "); scanf("%d", &x);
    } while (position < 0 || position > n);

    // Insert element to the linked list.
    insertToList(list, &n, x, position);

    // Print the new linked list to screen.
    printf("Here\'s your linked list, size is %d:\n", n);
    printList(*list);


    position = -1;
    do {
        printf("Position to delete an element: "); scanf("%d", &position);
        if (position < 0 || position > n) {
            printf("Notice that 0 <= position <= %d\n", n);
            continue;
        }
    } while (position < 0 || position > n);

    // Delete element from the list.
    deletePositionNode(list, &n, position);


    // Print the new linked list to screen.
    printf("Here\'s your updated linked list, size is %d: ", n);
    printList(*list);

    // Release the linked list.
    releaseLinkedList(list);

    return 0;
}
