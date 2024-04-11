#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pagedir.h"
#include "bag.h"
#include "crawler.h"

/**
 * Initializes the page directory so that webpages can be saved in it.
 * Returns true if initialization succeeded, false otherwise.
 */
bool pagedir_init(const char *pageDirectory) {


    // Construct the file path for the .crawler file
    char filepath[100];  // Adjust the size accordingly
    snprintf(filepath, sizeof(filepath), "%s/.crawler", pageDirectory);

    // Open the .crawler file for writing
    FILE *fp = fopen(filepath, "w");

    // If file not created, return false and remove the directory
    if (fp == NULL) {
        fprintf(stderr, "Error: .crawler file couldn't be opened.\n");
        // Remove the directory
        rmdir(pageDirectory);
        return false;
    }

    // Close the file
    fclose(fp);

    // Initialization succeeded
    return true;
}

/**
 * Saves a given webpage to a given page directory with a given document ID.
 */
void pagedir_save(const webpage_t *page, const char *pageDirectory, const int documentID) {
    // Check for invalid arguments
    if (page == NULL || pageDirectory == NULL) {
        fprintf(stderr, "Error: Invalid arguments.\n");
        return;
    }

    // Construct the filename for the webpage
    char filename[100];  // Adjust the size accordingly
    snprintf(filename, sizeof(filename), "%s/%d", pageDirectory, documentID);

    // Open the file for writing
    FILE *file = fopen(filename, "w");

    // If file not created, return error message
    if (file == NULL) {
        fprintf(stderr, "Error: File couldn't be opened.\n");
        return;
    }

    // Write URL, depth, and HTML content to file
    fprintf(file, "URL: %s\n", page->url);
    fprintf(file, "Depth: %d\n", page->depth);
    fprintf(file, "HTML Content:\n%s\n", page->html);

    // Close the file
    fclose(file);
}
