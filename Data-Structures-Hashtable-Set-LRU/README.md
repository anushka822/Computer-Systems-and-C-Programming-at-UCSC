# Data Structures Projects: Set, Hashtable & LRU Cache

**Author:** Anushka Hada
**Email:** [anhada@ucsc.edu](mailto:anhada@ucsc.edu)

---

## Description

This folder contains C programming projects completed as part of CSE-13S coursework at UCSC. These projects demonstrate **C programming skills, pointer manipulation, dynamic memory management, and data structure implementation**.

All project files are located in this single folder.

### Projects Included

1. **Set**

   * Implements a collection of unique items identified by string keys.
   * Supports insertion, deletion, lookup, iteration, and printing.
   * Demonstrates dynamic memory management and safe pointer usage.

2. **Hashtable**

   * Implements a hashtable of sets for efficient key-based storage and lookup.
   * Uses **separate chaining** with sets to handle collisions.
   * Supports insertion, lookup, iteration, printing, and deletion.
   * Demonstrates hash functions, modular arithmetic, and dynamic memory usage.

3. **LRU Cache**

   * Implements a Least Recently Used (LRU) cache.
   * Supports insertion, retrieval, and eviction of items based on access order.
   * Demonstrates linked list manipulation, pointer usage, and memory management.

---

## Folder Contents

```
Data-Structures-Projects/
│
├── set.c
├── set.h
├── hashtable.c
├── hashtable.h
├── lru.c
├── lru.h
├── test_set.c
├── test_hashtable.c
├── test_LRU.c
├── Makefile (if present)
└── README.md
```

---

## Compilation & Running

* Use the provided Makefile if available or compile manually with `gcc`.
* Example: `gcc -o program set.c hashtable.c lru.c test_set.c -std=c11`
* Run the resulting executable to test functionality.
