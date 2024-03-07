#ifndef HASHMAP_H
#define HASHMAP_H
#include "linkedList.h"
typedef struct HashMap {
	unsigned int cap;
	LinkedList* hashEntries;
}HashMap;

void HM_init(HashMap* hashmap, unsigned int cap);
long power(int base, int exp);
long hashFunc(str* key);
void insert(HashMap* hashmap, str* key, void* data, Datatype type);
void* getData(HashMap* hashmap, str* key);
int isEmpty(HashMap* hashmap);
void clear(HashMap* hashmap);
#endif
