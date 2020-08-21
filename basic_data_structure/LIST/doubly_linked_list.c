/**
 * Doubly Linked List (data structure).
 * I used the main() driver from singly_linked_list.c
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

struct Node {
  int value;
  struct Node* prev;
  struct Node* next;
} typedef Node;

struct List {
  struct Node* head;
  struct Node* tail;
} typedef List;

/**
 * This function create a list and return a pointer to the newly-created list.
 *
 * @return Pointer to the newly-created list.
 */
List* createLinkedList() {
  List* newList = (List*)malloc(sizeof(List));
  newList->head = NULL;
  newList->tail = NULL;
  return newList;
}

/**
 * This function create a new node
 * and return a pointer to the newly-created node.
 *
 * @param  value Value of the new node.
 * @return       Pointer to the newly-created node.
 */
Node* createNewNode(int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

/**
 * This function create a new node and insert it at the front of the list.
 * @param list  Pointer to the list.
 * @param value Value of new node.
 */
void insertFront(List* list, int value) {
  Node* newNode = createNewNode(value);

  if (list->head == NULL)
    list->head = list->tail = newNode;
  else {
    list->head->prev = newNode;
    newNode->next = list->head;
    list->head = newNode;
  }
}

/**
 * This function create a new node and insert it at position.
 *
 * @param list     Pointer to the list.
 * @param value    Value of new node.
 * @param position Position to insert.
 */
void insertPosition(List* list, int value, int position) {
  Node* newNode = createNewNode(value);

  int index = 0; Node* thisNode = list->head;
  while (index < position - 1) {
    ++index;
    thisNode = thisNode->next;
  }

  newNode->next = thisNode->next;
  thisNode->next->prev = newNode;
  newNode->prev = thisNode;
  thisNode->next = newNode;
}

/**
 * This function create a new node and insert it to the back of the list.
 *
 * @param list  Pointer to the list.
 * @param value Value of the new node.
 */
void insertBack(List* list, int value) {
  Node* newNode = createNewNode(value);

  if (list->tail == NULL)
    list->tail = list->head = newNode;
  else {
    list->tail->next = newNode;
    newNode->prev = list->tail;
    list->tail = newNode;
  }
}

/**
 * This function delete the head of a list.
 *
 * @param list Pointer to the list.
 */
void deleteHead(List* list) {
  Node* thisHead = list->head;

  // List is empty.
  if (thisHead == NULL) return;

  // List only have 1 element.
  if (thisHead->next != NULL) {
    thisHead->next->prev = NULL;
    list->head = thisHead->next;
  }

  else list->head = list->tail = NULL;

  free(thisHead);
}

/**
 * This function delete a list's tail node.
 *
 * @param list Pointer to the list.
 */
void deleteTail(List* list) {
  Node* thisTail = list->tail;

  // List is empty.
  if (thisTail == NULL) return;

  // List only have 1 element.
  if (thisTail->prev == NULL) {
    thisTail->prev->next = NULL;
    list->tail = thisTail->prev;
  }

  else list->tail = list->head = NULL;

  free(list->tail);
}

/**
 * This function delete a list's node at position.
 *
 * @param list     Pointer to the list.
 * @param position Position of the node in the list.
 */
void deletePosition(List* list, int position) {
  int index = 0; Node* thisNode = list->head;

  while (index < position - 1) {
    ++index;
    thisNode = thisNode->next;
  }

  if (thisNode == list->head) deleteHead(list);
  else if (thisNode == list->tail) deleteTail(list);
  else {
    thisNode->prev->next = thisNode->next;
    thisNode->next->prev = thisNode->prev;
  }

  free(thisNode);
}

/**
 * This function free the list.
 *
 * @param list [description]
 */
void freeList(List* list) {
  while (list->head != NULL) deleteHead(list);
  free(list); list = NULL;
}

/**
 * This function print the list, recursive way.
 *
 * @param node Pointer to the list's first node.
 */
void printList(Node* node) {
  if (node != NULL) {
    printf("%d ", node->value);
    printList(node->next);
  } else printf("\n");
  return;
}

int main() {
  // Create new list
  List* list = createLinkedList();

  // Create a list with 10 elements, in which evens came first, descending
  // and odds came later, ascending.
  for (int i = 1; i <= 10; ++i) {
    if (i % 2 == 0) insertFront(list, i);
    else insertBack(list, i);
  }
  printList(list->head);

  // Now insert a "0" in which position is odd.
  for (int i = 1; i <= 10; ++i)
    if (i % 2 != 0) insertPosition(list, 0, i);
  printList(list->head);

  // Now delete the 0s, knowing 0s is in 2 <= i <= 6.
  // (the list will shrink after any deletion).
  for (int i = 2; i <= 6; ++i) deletePosition(list, i);
  printList(list->head);

  // Free the list.
  freeList(list);
  return 0;
}
