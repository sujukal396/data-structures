#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef enum {
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	//STRING, //I'm not certain how to make this one work
}Datatype;

typedef struct string {
   unsigned int length;
   char* data;
}str;

typedef struct LL_Node {
   str *key;
   void *data;
	Datatype type;
   struct LL_Node *next;
}Node;

typedef struct linked_list {
   Node *head;
   unsigned int length;
}LinkedList;

void LL_init(LinkedList *list);
Node* createNode(str *key, void* data, Datatype type);//add further functionality to utilize char* rather than string struct
void prepend(LinkedList *list, str *key, void* data, Datatype type);
void removeNode(LinkedList *list, unsigned int index);
void freeNodes(LinkedList *list);
void printListData(LinkedList *list);
#endif
