// Step 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bag.h"
#include "hashtable.h"


unsigned long hash_string(const char *str);


/* Create a new (empty) hashtable; return NULL if error. */
hashtable_t *hashtable_new(const int num_slots) {
    if (num_slots == 0 || num_slots < 0) {
        return NULL; // Invalid number of slots
    }


    // alocate memory, cos dynamic bag
    hashtable_t *ht = malloc(sizeof(hashtable_t));
    ht -> bins = malloc( num_slots * sizeof(bag_t *) );
    
    if (ht == NULL || ht-> bins == NULL) {
        free(ht);
        return NULL; // Can not allocate memory
    }


    int i;
    for (i = 0; i < num_slots; i++) {

        // empty
        ht->bins[i] = bag_new();

        // Check for memory allocation failure
        if (ht->bins[i] == NULL) {
            goto clean; // J
        }
    }



    ht->num_slots = num_slots;
    return ht;

    clean:
    for (int j = 0; j < i; j++) {
        // delete using bag
        bag_delete(ht->bins[j], NULL);
    }


    free(ht->bins);
    free(ht);
    return NULL; // Memory allocation failure
}


/* Insert item, identified by key (string), into the given hashtable.
* The key string is copied for use by the hashtable.
* Return false if key exists in ht, any parameter is NULL, or error;
* return true iff new item was inserted.
*/
bool hashtable_insert(hashtable_t *ht, const char *key, void *item) {
    
    // Calculate the index using hash function

    int index = labs((long)hash_string(key)) % ht->num_slots;

    
    if ( key == NULL || item == NULL || ht == NULL ) {
        return false; // Invalid parameters
    }



    // need copy or else it gives errors
    char *new = strdup(key);

    if (new == NULL) {
        return false; // Memory allocation failure
    }

    if (!bag_insert(ht->bins[index], new, item)) {
        free(new);
        return false; // Memory allocation failure
    }

    return true;
}

/* Return the item associated with the given key;
* return NULL if hashtable is NULL, key is NULL, key is not found.
*/
void *hashtable_find(hashtable_t *ht, const char *key) {

    // get index
    int index = labs((long)hash_string(key)) % ht->num_slots;

    // return null 
    if (ht == NULL || key == NULL || bag_find(ht->bins[index], key) == NULL) {
        return NULL;
    }

    
    
    //return item 
    return bag_find(ht->bins[index], key);
}

/* Print the whole table; provide the output file and func to print each item.
* Ignore if NULL fp. Print (null) if NULL ht.
* Print a table with no items if NULL itemprint.
*/
void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item)) {
    if (ht == NULL) {
        //Print (null) if NULL ht.
        fprintf(fp, "(null)\n");
    }
    if (fp == NULL) {
        //Ignore if NULL fp. 
        return;
    }

    if (itemprint == NULL) {
        // Print a table with no items if NULL itemprint.
        fprintf(fp, "\n");
    }


    for (int x = 0; x < ht -> num_slots; x++) {
        //print using bag file
        bag_print( ht->bins[x], fp, itemprint);
    }
}

/* Iterate over all items in the table; in undefined order.
* Call the given function on each item, with (arg, key, item).
* If ht==NULL or itemfunc==NULL, do nothing.
*/
void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item)) {
    
    if (ht == NULL || itemfunc == NULL) {
        // do nothing
        return; 
    }

    //Iterate over all items in the table; in undefined order.
    for (int a = 0; a < ht->num_slots; a++) {
        bag_iterate( ht->bins[a], arg, itemfunc);
    }
}

/* Delete the whole hashtable; ignore NULL ht.
* Provide a function that will delete each item (may be NULL).
*/
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item)) {
    // Ignore NULL ht
    if (ht == NULL) {
        return; 
    }

    for (int b = 0; b < ht->num_slots; b++) {
        // use bag to delet 
        bag_delete(ht->bins[b], itemdelete);
    }
 
    

    free(ht->bins);
    
}

/* Hash function for strings */
unsigned long hash_string(const char *str) {

    //Considered seed value which is common for hash 
    unsigned long hash = 5381;

    while (*str) {
        hash = (hash * 33) + *str;
        str++;
    }
    return hash;
}



