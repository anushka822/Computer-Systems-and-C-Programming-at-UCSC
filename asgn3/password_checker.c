#include "password_checker.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
Password checker

Requirements:
- Password must be at least 10 characters
- Password must contain at least
    - 1 upper case letter
    - 1 lower case letter
    - 1 number
- Password cannot contain the person's first name or last name (case sensitive)

For the simplicity of this exercise:
- This is not the most efficient way to implement this program
- These functions do not perform any error checking
- You can assume that the first and last name will never be the empty string
*/

/* Returns true if LETTER is in the range [LOWER, UPPER], false otherwise */
bool check_range(char letter, char lower, char upper) {
    bool is_in_range = (letter >= lower && letter <= upper);
    //printf("is_in_range %d", is_in_range);
    return is_in_range;
}




/* Returns true if the length of PASSWORD is at least 10, false otherwise */
bool check_length(const char *password) {
    int length = strlen(password);
    if( length >= 10 ){
        return true;
    }
    else{
        return false; 
    }
}

/* Returns true if PASSWORD contains at least one upper case letter, false otherwise */
bool check_upper(const char *password) {
    bool is_in_range = false;
    while (*password != '\0') {
        is_in_range = check_range( *password, 'A', 'Z');
        if (is_in_range) break;
        ++password;
    }
    return is_in_range;
}

/* Returns true if PASSWORD contains at least one lower case letter, false otherwise */
bool check_lower(const char *password) {
    bool is_in_range = false;
    while (*password != '\0') {
        is_in_range = check_range(*password, 'a', 'z');
        if (is_in_range) break;
        ++password;
    }
    // if its true we break and return true. If its false then we loop through whole password and return false.
    return is_in_range;
}



bool check_number(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, '0', '9')) {
            return true;
        }
        ++password;
    }
    return false;
}

/* Returns true if the person's first and last name are NOT in the password, false otherwise */
bool check_name(const char *first_name, const char *last_name, const char *password) {
    
    /* Type "man strstr" in your terminal to learn what strstr does!
        To exit the man pages, press 'q' */
    /* Hint: a NULL pointer will evaluate to False in a logical expression while a non-NULL pointer
        will evaluate to True */
    const char *first = strstr(password, first_name);
    const char *last = strstr(password, last_name);
    //printf("*first_name %c", *first_name);
    //printf("*last_name %c", *last_name);
    //printf("%d", !first || !last);
    return (!first && !last);
}

/* Returns true if PASSWORD meets the conditions specified above */
bool check_password(const char *first_name, const char *last_name, const char *password) {
    bool length, upper, lower, number, name;
    lower = check_lower(password);
    upper = check_upper(password);
    number = check_number(password);
    length = check_length(password);
    name = check_name(first_name, last_name, password);
    //printf("lower && length && name && upper && number %d", (lower && length && name && upper && number));
    return (lower && length && name && upper && number); 
}
