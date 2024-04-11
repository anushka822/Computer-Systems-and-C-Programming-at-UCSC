#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lru.h"
#include "set.h"
#include "hashtable.h"

// Function to create a new (empty) LRU; return NULL if error
lru_t *lru_new(const int capacity) {
    if (capacity <= 0) {
        return NULL;
    }

    // allocate memory for new lru
    lru_t *lru = malloc(sizeof(lru_t));
    if (!lru) {
        return NULL;
    }

    lru->usage_order = set_new(); // making a set
    lru->items = hashtable_new(capacity); // making a hashtable and setting its size
    lru->capacity = capacity;
    lru->head = NULL; // set to Null so it's empty
    lru->tail = NULL;

    // return empty lru
    return lru;
}

/* Insert item, identified by key (string), into the given lru.
 * The key string is copied for use by the lru.
 * Return false if key exists in ht, any parameter is NULL, or error;
 * return true iff a new item was inserted.
 */
bool lru_insert(lru_t *lru, const char *key, void *item) {
    if (!lru || !key || !item || hashtable_find(lru->items, key) != NULL) {
        return false;
    }

    if (lru->usage_order->count == (size_t)lru->capacity) {
        // Find the least recently used key
        char *old_key = lru->usage_order->pairs[0].key;

        // Remove the least recently used item from the set and hashtable
        set_delete(lru->usage_order, free);
        hashtable_delete(lru->items, NULL); // No need to free old_key again

        // Remove the least recently used item from the linked list
        lru_node_t *old_node = lru->head;
        lru_node_t *prev_node = NULL;

        while (old_node != NULL && strcmp(old_node->key, old_key) != 0) {
            prev_node = old_node;
            old_node = old_node->next;
        }

        if (prev_node != NULL) {
            prev_node->next = old_node->next;
        } else {
            lru->head = old_node->next;
        }

        free(old_node->key);
        free(old_node);
    }

    // Insert the new item into the LRU
    hashtable_insert(lru->items, key, item);
    set_insert(lru->usage_order, key, item);

    // Add the new item to the linked list
    lru_node_t *new_node = malloc(sizeof(lru_node_t));
    new_node->key = strdup(key);
    new_node->item = item;
    new_node->next = lru->head;
    lru->head = new_node;

    return true;
}

// Function to return the item associated with the given key
void *lru_find(lru_t *lru, const char *key) {
    if (!lru || !key) {
        return NULL;
    }

    // Move the corresponding node to the front of the usage order
    lru_node_t *node = hashtable_find(lru->items, key);
    if (node) {
        // Update the set without deleting and reinserting
        set_delete(lru->usage_order, free);
        set_insert(lru->usage_order, strdup(key), NULL);
    }

    return hashtable_find(lru->items, key);
}

// Function to print the whole LRU
void lru_print(lru_t *lru, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item)) {
    if (!lru || !fp) {
        return;
    }

    lru_node_t *current = lru->head;
    while (current) {
        itemprint(fp, current->key, current->item);
        current = current->next;
    }
}

// Function to iterate over all items in the LRU
void lru_iterate(lru_t *lru, void *arg, void (*itemfunc)(void *arg, const char *key, void *item)) {
    if (!lru || !itemfunc) {
        return;
    }
    set_iterate(lru->usage_order, arg, itemfunc);
}

// Function to delete the whole LRU
void lru_delete(lru_t *lru, void (*itemdelete)(void *item)) {
    if (!lru) {
        return;
    }

    lru_node_t *current = lru->head;
    while (current) {
        lru_node_t *next = current->next;
        if (itemdelete) {
            itemdelete(current->item);
        }
        free(current->key);
        free(current);
        current = next;
    }

    set_delete(lru->usage_order, free);
    hashtable_delete(lru->items, NULL); // No need to free items here, it will be deleted in lru_delete
    free(lru);
}
