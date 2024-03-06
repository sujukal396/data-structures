#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct LL_Node {
   int data;
   struct LL_Node* next;
   struct LL_Node* prev;
}Node;

typedef struct {
   Node* head;
   Node* tail;
   unsigned int length;
}LinkedList;

Node* createNode(LinkedList* list, int data);
void freeNodes(LinkedList* list);
void append(LinkedList* list, int data);
void prepend(LinkedList* list, int data);
void insert(LinkedList* list, int data, int index);
void removeNode(LinkedList* list, int index);
void printList(LinkedList* list);
#endif
