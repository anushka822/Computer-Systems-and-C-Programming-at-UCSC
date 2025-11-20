#include "growing_arrays.h"



// returns the index of the item added  
int add_record(Record record) {
    // Your code here
    // if current value equals max value, resize.
    if (table.nval == table.max) {
        table.max *= GROW_SIZE;
        // use realloc cos were dealing with dynamic arrays. 
        table.record = realloc(table.record, table.max * sizeof(Record));
    }

    // Adds the new record to the end of the array as table.nval is the last value in array. 
    table.record[table.nval] = record;
    table.nval++; // increases the count
  

    // Return the index of the item just added
    return table.nval - 1;
}

// return 0 if there is no matching record
// return 1 if there is a matching record and deletes it and 
// moves records
int del_record(const char *name) {
    int i;

    for (i = 0; i < table.nval; i++) {
        // if we find name in array 
        if (strcmp(table.record[i].name, name) == 0) {
            break;
        }
    }

    // If the record is found, delete the record 
    if (i < table.nval) {
        // Move records beyond the hole down by one position to preserve the order 
        memmove(&table.record[i], &table.record[i + 1], (table.nval - i - 1) * sizeof(Record));
        table.nval--;
        return 1; // Record found and deleted
    }



    return 0; // If record not found then return 0. 
}

// returns id for first matching record
int get_id(const char *name) {
    // Your code here
    // Search for the record with the given name
    for (int i = 0; i < table.nval; i++) {
        // name found 
        if (strcmp(table.record[i].name, name) == 0) {
            // Return the id
            return table.record[i].id; 
        }
    }

    return 0; // No matching record found so 0
}

// returns record with a valid index, 0 to max-1 
Record get_record(int index) {
    // Your code here
    // validate index 
    if (index >= 0 && index < table.nval) {
        return table.record[index];
    } else {
        // Return a default record with id 0 and an empty name if the index is out of bounds
        Record none_record = {0};
        return none_record;
    }
}

// Testing code. You can modify this and check your own test cases.
//struct Table table; // If you are using another .c file to test your program comment this line as well.


/*
int main() {
    table.nval = 0;
    table.max = INIT_SIZE;
    table.record = malloc(sizeof(Record) * table.max);

    // test add_record
    Record r1 = {"Alice", 1};
    Record r2 = {"Bob", 2};
    Record r3 = {"Charlie", 3};
    int i1 = add_record(r1);
    int i2 = add_record(r2);
    int i3 = add_record(r3);
    printf("added records at indices %d, %d, %d\n", i1, i2, i3);

    // test get_id and get_record
    int id = get_id("Bob");
    Record r = get_record(i1);
    printf("record at index %d: name=%s, id=%d\n", i1, r.name, r.id);
    printf("record with name 'Bob': id=%d\n", id);

    // test del_record
    int success = del_record("Bob");
    printf("deleted record with name 'Bob': %d\n", success);
    id = get_id("Bob");
    printf("record with name 'Bob': id=%d\n", id);

    free(table.record);
    return 0;
}
*/

/*
Output for the above testing code:

added records at indices 0, 1, 2
record at index 0: name=Alice, id=1
record with name 'Bob': id=2
deleted record with name 'Bob': 1
record with name 'Bob': id=0


*/
