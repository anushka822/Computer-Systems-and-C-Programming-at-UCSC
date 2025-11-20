# Growing Arrays: Dynamic Record Management

**Author:** Anushka Hada  
**Email:** anhada@ucsc.edu  

---

## Description
This project implements a **dynamic array of records** in C. The program supports:

- Adding a record dynamically and automatically resizing the array when needed.  
- Deleting a record by name while maintaining array order.  
- Retrieving a record by index.  
- Searching for a record ID by name.  

The project demonstrates **dynamic memory allocation, array resizing, pointer manipulation, and memory-safe operations in C**.

---

## Files in the Repository

| File | Description |
|------|-------------|
| `growing_arrays.c` | Implementation of dynamic array functions (`add_record`, `del_record`, `get_id`, `get_record`). |
| `growing_arrays.h` | Header file defining `Record` struct, `Table` struct, and function prototypes. |
| `test_growing_arrays.c` | Example/test file to validate array functionality. |
| `Makefile` | Compiles the dynamic array and test program. |
| `README.md` | Project description and usage instructions. |

---

## Functions Overview

- `int add_record(Record record)`  
  Adds a new record to the dynamic array, resizes the array if needed, and returns the index of the added record.  

- `int del_record(const char *name)`  
  Deletes the first record matching `name` and maintains array order. Returns `1` if deleted, `0` if not found.  

- `int get_id(const char *name)`  
  Returns the ID of the first record matching `name`, or `0` if not found.  

- `Record get_record(int index)`  
  Returns the record at the given index if valid; otherwise returns a default record with ID `0`.  

---

## How to Compile

1. Open a terminal in the project directory.  
2. Compile the program (example):  
```bash
gcc -o growing_arrays growing_arrays.c -lm
```

---

## How to Run

- The provided `main` function (commented out) can be used to test the dynamic array operations.  
- Add your own test cases or modify the example to experiment with adding, deleting, and retrieving records.  

---

## Skills Demonstrated

- Dynamic memory allocation with `malloc` and `realloc`  
- Array manipulation and `memmove` usage  
- Struct handling in C  
- Modular function design and reusable code  
- Safe index checking and error handling
