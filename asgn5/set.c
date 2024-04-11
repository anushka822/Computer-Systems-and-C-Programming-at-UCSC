
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"

/* Create a new (empty) set; return NULL if error. */
set_t* set_new(void){

    // dynamic list/set
    set_t *new_set = malloc(sizeof(set_t)); 

    // if already Null or error return NULL
    if (new_set == NULL) {
        return NULL;
    }

    // Set Everything to NULL or 0
    new_set->pairs = NULL;
    
    new_set->count = 0;
    
    new_set->capacity = 0;

    // return new_set
    return new_set;
}



/* Return the item associated with the given key;
 * return NULL if set is NULL, key is NULL, or key is not found.
 */
void *set_find(set_t *set, const char *key) {
    
    // if set/key null return null;
    if( set == NULL || key == NULL){
        return NULL;
    }


    // loop trough set 
    // if found key matches key entered by user then return item

    for (size_t i = 0; i < set->count; i++) {
        // strcmp compares strings
        if (strcmp(key, set->pairs[i].key) == 0) {
            return set->pairs[i].item;
        }
    }

    // if no key found then return null
    return NULL;
}





/* Insert item, identified by a key (string), into the given set.
 * The key string is copied for use by the set.
 * Return false if key exists, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool set_insert(set_t *set, const char *key, void *item){
    // if set/key/item null return null;
    // can't insert stuff if theres nothing in the first place. 
    if( set == NULL || key == NULL || item == NULL){
        return false;
    }


   // while not empty
    // Check if the key already exists in the set
    for (size_t i = 0; i < set->count; i++) {
        if ( strcmp( key, set -> pairs[ i].key) == 0) {
            return false;  // Key already exists
        }
    }

    // Resize the array 
    if (set->count == set->capacity) {
        set->capacity *= 2;
        set->pairs = realloc(set->pairs, set->capacity * sizeof(pair_t));
        if (set->pairs == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for the set\n");
            exit(EXIT_FAILURE);
        }
    }

    // Create a new pair and copy the key
    set->pairs[set->count].key = strdup(key);
    if (set->pairs[set->count].key == NULL) {
        fprintf(stderr, "Error: Unable to copy the key\n");
        exit(EXIT_FAILURE);
    }
    set->pairs[set->count].item = item;
    set->count++;

    return true;
}

/* Print the whole set; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL set.
 * Print a set with no items if NULL itemprint.
*/
void set_print(set_t *set, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item) ){
    if (fp == NULL) {
        return;
    }

    if (set == NULL) {
        fprintf(fp, "(null)\n");
        return;
    }

    for (size_t i = 0; i < set->count; i++) {
        itemprint(fp, set->pairs[i].key, set->pairs[i].item);
    }

}

/* Iterate over all items in the set, in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If set==NULL or itemfunc==NULL, do nothing.
 */
void set_iterate(set_t *set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) ){
    
    if (set == NULL || itemfunc == NULL) {
        return; // do nothing
    }


    // iterate over all iteams
    for (size_t i = 0; i < set->count; i++) {
        itemfunc(arg, set->pairs[i].key, set->pairs[i].item);
    }
                
}

/* Delete the whole set; ignore NULL set.
 * Provide a function that will delete each item (may be NULL).
 */
void set_delete(set_t *set, void (*itemdelete)(void *item) ){
    if (set == NULL) {
        return;
    }
    
    if (itemdelete != NULL) {
        for (size_t i = 0; i < set->count; i++) {
            itemdelete(set->pairs[i].item);
        }
    }

    for (size_t i = 0; i < set->count; i++) {
        free(set->pairs[i].key); // get rid of item
    }


    free(set->pairs);
    free(set);

}



