#include <stdio.h>
#include <stdlib.h>
#include "hashMap.h" // Assuming you have a header file for your HashMap implementation
#include "linkedList.h"

int main() {
    // Creating a HashMap
    HashMap* hashmap;
    hashmap = (HashMap*)malloc(sizeof(HashMap));
    HM_init(hashmap, 10); // Initialize with a capacity of 10

    // Inserting data into the HashMap
    str key1 = {4, "key1"}; // Assuming you have defined str struct somewhere
    //str* key1;
    //key1->length = 4;
    //key1->data = "key1"; 
    int data1 = 100;
    insert(hashmap, &key1, &data1, INT);

    // Retrieving data from the HashMap
    int *result = (int *)getData(hashmap, &key1);
    if (result != NULL) {
        printf("Data associated with key1: %d\n", *result);
    } else {
        puts("Key not found.");
    }

    // Checking if the HashMap is empty
    if (isEmpty(hashmap)) {
        puts("HashMap is empty.");
    } else {
        puts("HashMap is not empty.");
    }

    // Clearing the HashMap
    //clear(hashmap); The structs will be stack allocated, but i keep this here as I am a cowardly man
    free(hashmap);
    
    puts("HashMap cleared");

    return 0;
}

