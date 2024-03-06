#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(LinkedList* list, int data){
   Node* newNode = (Node*) malloc(sizeof(Node));
   newNode->data = data;
   newNode->prev = NULL;
   newNode->next = NULL;
}

void freeNodes(LinkedList* list) {
   Node* curr = list->head;
   while (curr != NULL) {
      Node* temp = curr;
      free(curr);
      curr = temp->next;
   }
   list->length = 0;
}

void append(LinkedList* list, int data) {
   Node* newNode = createNode(list, data);
   if(list->head == NULL) {
     list->head = newNode;
     list->tail = newNode;
   }else {
      list->tail->next = newNode;
      newNode->prev = list->tail;
      list->tail = newNode;
   }
   list->length++;
}

void prepend(LinkedList* list, int data) { 
   Node* newNode = createNode(list, data);
   if(list->head == NULL) {
      list->head = newNode;
      list->tail = newNode;
   }else {
      newNode->next = list->head;
      list->head->prev = newNode;
      list->head = newNode;
   }
   list->length++;
}

void insert(LinkedList* list, int data, int index) {
  Node* newNode = createNode(list, data);
  if(list->head == NULL) {
      list->head = newNode;
      list->tail = newNode;
   }else if(index >= list->length) {
      append(list, data);
   }else if(index <= 0) {
      prepend(list, data);
   }else {
      Node* before = list->head;
      for(int i=0;i<index;i++) {
         before = before->next;
      }
      Node* after = before->next;
      before->next = newNode;
      after->prev = newNode;
      newNode->prev = before;
      newNode->next = after;
   }
   list->length++;
}

void removeNode(LinkedList* list, int index) {
   if(list->head != NULL && index <list->length && index>0) {
      Node* curr = list->head;
      for(int i=0;i<=index;i++) {
         curr = curr->next;
      }
      Node* before = curr->prev;
      Node* after = curr->next;
      free(curr);
      before->next = after;
      after->prev = before;
      list->length--;
   }
}

void printList(LinkedList* list) {
   Node* curr = list->head;
   while (curr->next != NULL) {
      printf("%d ", curr->data);
   }
}
