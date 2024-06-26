
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"
#include "hashtable.h"

#ifndef LRU_H_
#define LRU_H_



typedef struct lru_node {
    char *key;
    void *item;
    struct lru_node *next; // next node
    struct lru_node *prev; // previous node
} lru_node_t;

typedef struct lru {
    set_t *usage_order;   // To store keys
    hashtable_t *items;   // To store key-value pairs
    lru_node_t *tail;     // back of stuff
    lru_node_t *head;     // head/front
    int capacity;
} lru_t;


/* Create a new (empty) lru; return NULL if error. */
lru_t *lru_new(const int capacity);

/* Insert item, identified by key (string), into the given lru.
 * The key string is copied for use by the lru.
 * Return false if key exists in ht, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool lru_insert(lru_t *ht, const char *key, void *item);

/* Return the item associated with the given key;
 * return NULL if lru is NULL, key is NULL, key is not found.
 */
void *lru_find(lru_t *ht, const char *key);

/* Print the whole table; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL ht.
 * Print a table with no items if NULL itemprint.
 */
void lru_print(lru_t *ht, FILE *fp,
                     void (*itemprint)(FILE *fp, const char *key, void *item));

/* Iterate over all items in the table; in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If ht==NULL or itemfunc==NULL, do nothing.
 */
void lru_iterate(lru_t *ht, void *arg,
               void (*itemfunc)(void *arg, const char *key, void *item) );

/* Delete the whole lru; ignore NULL ht.
 * Provide a function that will delete each item (may be NULL).
 */
void lru_delete(lru_t *ht, void (*itemdelete)(void *item) );


#endif //LRU_H_

