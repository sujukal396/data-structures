#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void LL_init(LinkedList *list) {
   list->length = 0;
   list->head = NULL;
}

Node* createNode(str* key, void* data, Datatype type) {
   Node* newNode = (Node*) malloc(sizeof(Node));
   newNode->key = key; //passing in char[] as a parameter leads to funkiness which makes this code broke
   newNode->data = data;
   newNode->next = NULL;
	newNode->type = type;
	return newNode;
}

void freeNodes(LinkedList *list) {
   Node *curr = list->head;
   while (curr->next != NULL) {
      Node *temp = curr->next;
      free(curr);
      curr = temp;
   }
   list->length = 0;
   //printf("List Cleared\n");
}

void prepend(LinkedList *list, str *key, void* data, Datatype type) {
   Node *newNode = createNode(key, data, type);
   newNode->next = list->head;
   list->head = newNode;
   list->length++;
}

void removeNode(LinkedList *list, unsigned int index) {
   Node *temp;
   if(index >= list->length) {
      return;
   }
   if(index == 0) {
      temp = list->head;
      list->head = list->head->next;
   }else {
      Node *before = list->head;
      for(unsigned int i = 0; i < index-1; i++) {
         before = before->next;
      }
      temp = before->next;
      if(index == list->length-1) {
         before->next = NULL;
      }else {
         before->next = before->next->next;
      }
   }
   free(temp);
   list->length--;
   //printf("Element removed\n");
}

void printListData(LinkedList *list) {
   if(list->head == NULL) {
      printf("List is Empty\n");
      return;
   }
//   if(list->head->next == NULL) {
//      printf("%d\n", list->head->data);
//      return;
//   }
   Node *curr = list->head;
   do {
		switch(curr->type) {
			case INT:
				printf("%d ",	*(int*)curr->data);
				break;
			case FLOAT:
				printf("%f ", *(float*)curr->data);
				break;
			case DOUBLE:
				printf("%lf ", *(double*)curr->data);
				break;
			case CHAR:
				printf("%c ", *(char*)curr->data);
				break;
			default:
				printf("Unsupported data type\n");
				return;
		}	
      curr = curr->next;
   }while(curr != NULL);
}
