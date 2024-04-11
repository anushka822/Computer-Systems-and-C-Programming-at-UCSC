#define _XOPEN_SOURCE 500
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For sleep function
#include "crawler.h" // declares our functions
#include "curl.h" // Downloads webpages
#include "pagedir.h"
#include "hashtable.h"
#include "bag.h"
#include "url.h"











/**
 * Parses command-line arguments, placing the corresponding values into the pointer arguments seedURL,
 * pageDirectory and maxDepth. argc and argv should be passed in from the main function.
 */
static void parseArgs(const int argc, char *argv[], char **seedURL, char **pageDirectory, int *maxDepth) {
	
	//Given arguments from the command line, extract them into the function parameters; return only if successful.
	if ( argc != 4) {
        fprintf(stderr, "Error: Wrong number of arguments. >\n");
        exit(1);
    }

	// Assign seedURL, pageDirectory, and parse maxDepth
    *seedURL = argv[1];
    *pageDirectory = argv[2];
    *maxDepth = atoi(argv[3]);

	//for maxDepth, ensure it is an integer in specified range [0 … 10]
	if (*maxDepth <= 0 || *maxDepth >= 10) {
		fprintf(stderr, "Error: Wrong Max depth. >\n");  // Corrected fprint to fprintf
    	exit(1);
	}


	// Call pagedir_init to initialize the page directory
	//if any trouble is found, print an error to stderr and exit non-zero.
    if ( !pagedir_init(*pageDirectory) ) {
        fprintf(stderr, "Error: Failed to initialize page directory\n");
        exit(1);
    }
	
}

void webpage_delete(webpage_t *page) {
    if (page == NULL) {
        return;  // No action needed for NULL input
    }

    // Free the allocated memory for URL and HTML content
    free(page->url);
    free(page->html);

    // Free the webpage structure itself
    free(page);
}

void crawl(char *seedURL, char *pageDirectory, const int maxDepth) {
    // Initialize the bag for web pages.
    bag_t *webPages = bag_new();

    // Add seedURL to the bag of webpages to crawl, marked with depth=0
    bag_insert(webPages, seedURL, create_webpage(seedURL, 0));

    // Add seedURL to the hashtable of URLs seen so far
    hashtable_t *pagesSeen = hashtable_new(1000);
    hashtable_insert(pagesSeen, seedURL, NULL);

    // Process web pages until the bag is empty
    while (1) {
        // Find a webpage (URL, depth) item in the bag
        webpage_t *current = bag_find(webPages, seedURL);

        // Check if bag is empty or key not found
        if (current == NULL) {
            break;  // Exit the loop if bag is empty or key not found
        }

        // Download the webpage content
        size_t size;
        char *downloadedPage = download(current->url, &size);

        // Check if download was successful
        if (downloadedPage != NULL && size > 0) {
            // Update the current webpage with downloaded content
            current->html = downloadedPage;
            current->length = size;

            // Scan the webpage for URLs and add them to the bag
            pageScan(current, webPages, pagesSeen);
        }

        // Remove the current webpage from the bag (assuming you have a removal function)
        bag_remove(webPages, seedURL);  // Replace with the actual removal function

        // Free the current webpage
        webpage_delete(current);
    }

    // Cleanup: Delete the hashtable and the bag
    hashtable_delete(pagesSeen, NULL);
    bag_delete(webPages, webpage_delete);
}



webpage_t *create_webpage(const char *url, int depth) {
    webpage_t *page = malloc(sizeof(webpage_t));
    if (page == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for webpage\n");
        exit(1);
    }

    page->url = strdup(url);
    page->html = NULL; // Initialize html to NULL, it will be populated when downloaded
    page->length = 0;  // Initialize length to 0
    page->depth = depth;

    return page;
}




	/*
    // Initialize the hashtable for seedURL
    hashtable_t *visited = hashtable_new(1000);

    // initialize the hashtable and add the seedURL
    hashtable_insert(visited, seedURL, NULL);

    // Initialize the bag for web pages.
    bag_t *bag = bag_new();

	// webage struct allocate 

	webpage_t *webpage = (webpage_t*)calloc(1,sizeof(webpage_t));
	webpage->url = strdup(seedUrl);
	webpage->depth = 0; 
	bag->page = webpage; 

	bag_t *current = bag;

	while( bag != NULL && bag->page != NULL){
		// pull webpage/url
		webpage_t *new = bag->page; 
		// pull new url 
		char *newURL = new-> url; 
		size_t size = 0; 
		char *downloadedPage = download( newURL, &size); 
		printf("%d%s\n", depth, newURL);

		if( downloadedPage != NULL && size > 0){
			new->html = downloadedPage; 
			new->length = size; 

			if(){

			}


		}
	else {
		bag->next;
	}
	}

    // Add the seed web page to the bag
    char *htmlContent = download(seedURL, NULL);

    if (htmlContent != NULL) {
        webpage_t *seedPage = create_webpage(seedURL, 0);  // You need to define create_webpage function
        bag_insert(webPages, seedPage);
    }

    // Process web pages until the bag is empty
    




*/









/**
 * Scans a webpage for URLs.
 */
static void pageScan(webpage_t *page, bag_t *pagesToCrawl, hashtable_t *pagesSeen) {
    if (page == NULL || pagesToCrawl == NULL || pagesSeen == NULL) {
        return;
    }

    // Define start and end patterns for URL extraction
    const char *startPattern = "<a href=\"";
    const char *endPattern = "\"";

    // Iterate through the HTML content
    size_t pos = 0;
    while (pos < page->length) {
        // Find the first occurrence of the start pattern
        char *startPos = strstr(page->html + pos, startPattern);

        if (startPos == NULL) {
            break;  // No more URLs found
        }

        // Move to the end of the start pattern
        pos = startPos - page->html + strlen(startPattern);

        // Find the end pattern to determine the URL end
        char *endPos = strstr(page->html + pos, endPattern);

        if (endPos != NULL) {
            // Extract the URL
            size_t urlLength = endPos - (page->html + pos);
            char *url = malloc(urlLength + 1);
            strncpy(url, page->html + pos, urlLength);
            url[urlLength] = '\0';

            // Normalize the URL relative to page->url
            char *normalizedURL = normalizeURL(page->url, url);

            // Check if the URL is internal and not already in pagesSeen
            if (isInternalURL(page->url, normalizedURL) && hashtable_insert(pagesSeen, normalizedURL, NULL)) {
                // Create a new webpage for the URL at depth + 1
                webpage_t *newPage = create_webpage(normalizedURL, page->depth + 1);

                // Add the new webpage to pagesToCrawl
                bag_insert(pagesToCrawl, newPage->url, newPage);
            }

            // Free the URLs
            free(url);
            free(normalizedURL);

            // Move to the next occurrence of the start pattern
            pos = endPos - page->html + 1;
        } else {
            break;  // End pattern not found, exit the loop
        }
    }
}


int main(const int argc, char *argv[]) {
    char *seedURL;
    char *pageDirectory;
    int maxDepth;

    // Parse command-line arguments
    parseArgs(argc, argv, &seedURL, &pageDirectory, &maxDepth);

    // Call crawl with the specified parameters
    crawl(seedURL, pageDirectory, maxDepth);

    // Example of how to use pageScan (modify this according to your needs)
    // Create a dummy webpage with the provided seed URL and depth 0
    webpage_t *seedPage = create_webpage(seedURL, 0);

    // Create a dummy bag and add the seed page to it
    bag_t *dummyBag = bag_new();
    bag_insert(dummyBag, seedPage->url, seedPage);

    // Call pageScan with the dummy page and bag
    pageScan(seedPage, dummyBag, NULL);

    // Cleanup: delete the dummy page and bag
    webpage_delete(seedPage);
    bag_delete(dummyBag, NULL);

    // Exit with success
    exit(0);
}



