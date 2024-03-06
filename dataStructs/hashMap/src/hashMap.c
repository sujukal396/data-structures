#include "linkedList.h"
#include "hashMap.h"
#include <stdlib.h>

void HM_init(HashMap* hashmap, unsigned int cap) {
   hashmap->cap = cap;
	hashmap->hashEntries = (LinkedList*)malloc(cap * sizeof(LinkedList));
}//potentially automatically create the HashMap* within HM_init rather than what i have here

long power(int base, int exp) {
	long res = 1;
	for(int i=0; i < exp; i++) {
		res *= base;
	}
	return res;
}

long hashFunc(str* key) {
	char *input = key->data;
	const unsigned int p = 31;//51 if upper case and lower case
	const unsigned int mod = 1e9 + 9;
	long hash = 0;//I'm not certain ill need more than a long
	for(unsigned int i = 0; i < key->length; i++) {
		hash = (hash + (int)*input * power(p,i)) % mod; 
	}
	return hash;
}

void insert(HashMap* hashmap, str* key, void* data, Datatype type) {
   long hashVal = hashFunc(key);
   int index = hashVal % hashmap->cap;
   prepend(&(hashmap->hashEntries[index]), key, data, type);
}

void* getData(HashMap* hashmap, str* key) {
   long hashVal = hashFunc(key);
   int index = hashVal % hashmap->cap;
   LinkedList* entryArr = hashmap->hashEntries;
   Node* dataNode = entryArr[index].head;
   if(entryArr[index].length == 1) {
      return dataNode->data;
   }else {
      while(dataNode->key->data != key->data) {//TODO: BROKEN MUST FIX
         dataNode = dataNode->next;
      }
      return dataNode->data;//trying not to vomit as this code
   }                        //progressively gets worse
}

int isEmpty(HashMap* hashmap){
   for(unsigned int i = 0; i < hashmap->cap; i++) {//Im so fucking tired why do i loop again?
      if(&(hashmap->hashEntries[i]) == NULL) {//Dude its so joever
         return 1;
      }
   }
   return 0;
}

void clear(HashMap* hashmap) {
   if(isEmpty(hashmap)) {
      return;
   }
   for(unsigned int i = 0; i < hashmap->cap; i++) {
      if(&(hashmap->hashEntries[i]) != NULL) {
         freeNodes(&(hashmap->hashEntries[i]));
         //free(hashMap[i]); I might be a dumbass, so I'll keep this commented for now
      }
   }
}
