
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bag.h"




// Function to remove an item from the bag
void bag_remove(bag_t *bag, const char *key) {
    if (bag == NULL || key == NULL) {
        return;  // Nothing to remove
    }

    // Use a boolean variable to track whether the key is found
    bool keyFound = false;

    // Search for the key in the bag
    for (size_t i = 0; i < bag->count; i++) {
        if (strcmp(bag->pairs[i].key, key) == 0) {
            keyFound = true;

            // Free the item (you might want to adapt this based on your item structure)
            free(bag->pairs[i].item);

            // Shift the remaining items to fill the gap
            for (size_t j = i; j < bag->count - 1; j++) {
                bag->pairs[j] = bag->pairs[j + 1];
            }

            // Decrement the count
            bag->count--;
            break;  // Exit the loop once the key is found and removed
        }
    }

    // If the key is not found, you might want to handle that case
    if (!keyFound) {
        // Handle key not found case if needed
    }
}

int bag_is_empty(const bag_t *bag) {
    return bag->count == 0;
}
 
/* Create a new (empty) bag; return NULL if error. */
bag_t* bag_new(void){

    // dynamic list/bag
    bag_t *new_bag = malloc(sizeof(bag_t)); 

    // if already Null or error return NULL
    if (new_bag == NULL) {
        return NULL;
    }

    // bag Everything to NULL or 0
    new_bag->pairs = NULL;
    
    new_bag->count = 0;
    
    new_bag->capacity = 0;

    // return new_bag
    return new_bag;
}



/* Return the item associated with the given key;
 * return NULL if bag is NULL, key is NULL, or key is not found.
 */
void *bag_find(bag_t *bag, const char *key) {
    
    // if bag/key null return null;
    if( bag == NULL || key == NULL){
        return NULL;
    }


    // loop trough bag 
    // if found key matches key entered by user then return item

    for (size_t i = 0; i < bag->count; i++) {
        // strcmp compares strings
        if (strcmp(key, bag->pairs[i].key) == 0) {
            return bag->pairs[i].item;
        }
    }

    // if no key found then return null
    return NULL;
}





/* Insert item, identified by a key (string), into the given bag.
 * The key string is copied for use by the bag.
 * Return false if key exists, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool bag_insert(bag_t *bag, const char *key, void *item){
    // if bag/key/item null return null;
    // can't insert stuff if theres nothing in the first place. 
    if( bag == NULL || key == NULL || item == NULL){
        return false;
    }


   // while not empty
    // Check if the key already exists in the bag
    for (size_t i = 0; i < bag->count; i++) {
        if ( strcmp( key, bag -> pairs[ i].key) == 0) {
            return false;  // Key already exists
        }
    }

    // Resize the array bag
  
    if (bag->count == bag->capacity) {
        bag->capacity *= 2;
        bag->pairs = realloc(bag->pairs, bag->capacity * sizeof(pair_t));
        if (bag->pairs == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for the bag\n");
            exit(EXIT_FAILURE);
        }
    }

    // Create a new pair and copy the key
    char *dup_key = strdup(key);
    if (dup_key == NULL) {
        fprintf(stderr, "Error: Unable to duplicate the key\n");
        exit(EXIT_FAILURE);
    }

    bag->pairs[bag->count].key = dup_key;
    bag->pairs[bag->count].item = item;
    bag->count++;
    if (bag->pairs[bag->count].key == NULL) {
        fprintf(stderr, "Error: Unable to copy the key\n");
        exit(EXIT_FAILURE);
    }
    bag->pairs[bag->count].item = item;
    bag->count++;

    return true;
}

/* Print the whole bag; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL bag.
 * Print a bag with no items if NULL itemprint.
*/
void bag_print(bag_t *bag, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item) ){
    if (fp == NULL) {
        return;
    }

    if (bag == NULL) {
        fprintf(fp, "(null)\n");
        return;
    }

    for (size_t i = 0; i < bag->count; i++) {
        itemprint(fp, bag->pairs[i].key, bag->pairs[i].item);
    }

}

/* Iterate over all items in the bag, in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If bag==NULL or itemfunc==NULL, do nothing.
 */
void bag_iterate(bag_t *bag, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) ){
    
    if (bag == NULL || itemfunc == NULL) {
        return; // do nothing
    }


    // iterate over all iteams
    for (size_t i = 0; i < bag->count; i++) {
        itemfunc(arg, bag->pairs[i].key, bag->pairs[i].item);
    }
                
}

/* Delete the whole bag; ignore NULL bag.
 * Provide a function that will delete each item (may be NULL).
 */
void bag_delete(bag_t *bag, void (*itemdelete)(webpage_t *item) ){
    if (bag == NULL) {
        return;
    }
    
    if (itemdelete != NULL) {
        for (size_t i = 0; i < bag->count; i++) {
            itemdelete(bag->pairs[i].item);
        }
    }

    for (size_t i = 0; i < bag->count; i++) {
        free(bag->pairs[i].key); // get rid of item
    }


    free(bag->pairs);
    free(bag);

}



