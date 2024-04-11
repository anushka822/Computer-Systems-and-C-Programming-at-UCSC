#ifndef CRAWLER_H
#define CRAWLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>  // For sleep function
#include "crawler.h" // declares our functions
#include "curl.h" // Downloads webpages

#include "pagedir.h"
#include "bag.h"
#include "hashtable.h"
#include "url.h"



/**
 * Parses command-line arguments, placing the corresponding values into the pointer arguments seedURL,
 * pageDirectory and maxDepth. argc and argv should be passed in from the main function.
 */
static void parseArgs(const int argc, char *argv[], char **seedURL, char **pageDirectory, int *maxDepth);

// Function to delete a webpage and free its memory
void webpage_delete(webpage_t *page);

// Function to crawl the web
void crawl(char *seedURL, char *pageDirectory, const int maxDepth);

// Function to scan a webpage for URLs
static void pageScan(webpage_t *page, bag_t *pagesToCrawl, hashtable_t *pagesSeen);

// Function to create a webpage
webpage_t *create_webpage(const char *url, int depth);

#endif //CRAWLER_H 
