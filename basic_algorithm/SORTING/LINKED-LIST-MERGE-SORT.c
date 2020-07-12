/**
 * Sort a linked list, using Merge Sort implementation.
 * This also used the Floyd fast & slow pointer technique,
 * to find the middle element of a linked list.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node* next;
} typedef Node;

struct singlyLinkedList {
    struct Node* head;
} typedef singlyLinkedList;

/**
 * This function create a new singly-linked-list.
 * @return pointer to the newly-created list.
 */
singlyLinkedList* createList() {
    singlyLinkedList* newList = (singlyLinkedList*)malloc(sizeof(singlyLinkedList));
    newList->head = NULL;
    return newList;
}

/**
 * This function create a new node.
 * @param  value value of the new node.
 * @return       pointer to the newly-created node.
 */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/**
 * This function check if a list is empty.
 * @param  list pointer to the list.
 * @return      1 if the list is empty, 0 otherwise.
 */
int isEmpty(singlyLinkedList* list) {
    return list->head == NULL;
}

/**
 * This function create a new node and insert it into the back of the list.
 * @param list  pointer to the list.
 * @param value value to insert.
 */
void insertToBack(singlyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(list))
        list->head = newNode;
    else {
        // Find current last node.
        Node* currentLastNode = list->head;
        while (currentLastNode->next != NULL)
            currentLastNode = currentLastNode->next;

        // Insert new node after the last node.
        currentLastNode->next = newNode;
    }
}

/**
 * This function delete the head of a list.
 * @param list pointer to the list.
 */
void deleteHead(singlyLinkedList* list) {
    if (isEmpty(list)) return;

    Node* currentHead = list->head;
    if (currentHead->next == NULL)
        list->head = NULL;
    else list->head = currentHead->next;

    free(currentHead);
}

/**
 * This function free the list.
 * @param list pointer to the list.
 */
void freeList(singlyLinkedList* list) {
    while (!isEmpty(list)) deleteHead(list);
    free(list);
}

/**
 * This function print the linked list.
 * @param list pointer to the list.
 */
void printList(singlyLinkedList* list) {
    Node* thisNode = list->head;
    while (thisNode != NULL) {
        printf("%d ", thisNode->value);
        thisNode = thisNode->next;
    }
    printf("\n");
}

/**
 * This function divides a list into 2 part.
 * @param head   Pointer to head of the original list.
 * @param first  Pointer to the pointer holds the head of the first list.
 * @param second Pointer to the pointer holds the head of the second list.
 */
void divide(Node* head, Node** first, Node** second) {
    Node* slow = head;
    Node* fast = head->next;

    // Using Floyd's fast & slow pointer approach
    // to find the middle node.
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Separating aka write the head of each list into a pointer.
    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

/**
 * This function merge two list, using two head pointers.
 * @param  first  pointer to the head of first list.
 * @param  second pointer to the head of second list.
 * @return        a pointer to the new-merged list.
 */
Node* merge(Node* first, Node* second) {
    // If one in both list is NULL, return the other.
    if (first == NULL) return second;
    if (second == NULL) return first;

    // Else, merge two list, using recursion.
    Node* result = NULL;
    if (first->value < second->value) {
        result = first;
        result->next = merge(first->next, second);
    } else {
        result = second;
        result->next = merge(first, second->next);
    }

    return result;
}

/**
 * The MergeSort.
 * @param pointer to the pointer to the head of the list. (can be replaced with C++ reference).
 */
void mergeSort(Node** headList) {
    Node* head = *headList;
    Node* first;
    Node* second;

    // List is empty / has 1 node only.
    if (head == NULL || head->next == NULL)
        return;

    // Divide the list into 2 part.
    divide(head, &first, &second);

    // Sort 2 part.
    mergeSort(&first);
    mergeSort(&second);

    // Then merge back to the original head.
    *headList = merge(first, second);
}

int main() {
    freopen("SORT.INP", "r+", stdin);
    singlyLinkedList* list = createList();
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int nodeValue; scanf("%d", &nodeValue);
        insertToBack(list, nodeValue);
    }

    printList(list);
    mergeSort(&list->head);
    printList(list);
    freeList(list);

    return 0;
}
