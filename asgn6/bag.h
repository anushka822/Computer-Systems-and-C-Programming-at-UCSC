#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "crawler.h"





#ifndef BAG_H_
#define BAG_H_


// Structure for a (key, item) pair
typedef struct {
    char *key;
    void *item;
} pair_t;

// Structure for a bag
typedef struct bag {
    pair_t *pairs;
    size_t count;
    size_t capacity;
} bag_t;


// Structure for a webpage
typedef struct {
    char *url;
    char *html;
    size_t length;
    int depth;
} webpage_t;



/* Create a new (empty) bag; return NULL if error. */
bag_t* bag_new(void);

/* Insert item, identified by a key (string), into the given bag.
 * The key string is copied for use by the bag.
 * Return false if key exists, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool bag_insert(bag_t *bag, const char *key, void *item);

/* Return the item associated with the given key;
 * return NULL if bag is NULL, key is NULL, or key is not found.
 */
void *bag_find(bag_t *bag, const char *key);

/* Print the whole bag; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL bag.
 * Print a bag with no items if NULL itemprint.
*/
void bag_print(bag_t *bag, FILE *fp,
               void (*itemprint)(FILE *fp, const char *key, void *item) );

/* Iterate over all items in the bag, in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If bag==NULL or itemfunc==NULL, do nothing.
 */
void bag_iterate(bag_t *bag, void *arg, void (*itemfunc)(void *arg, const char *key, void *item));


/* Delete the whole bag; ignore NULL bag.
 * Provide a function that will delete each item (may be NULL).
 */
void bag_delete(bag_t *bag, void (*itemdelete)(webpage_t *item));


int bag_is_empty(const bag_t *bag);


void bag_remove(bag_t *bag, const char *key);



#endif // BAG_H_
