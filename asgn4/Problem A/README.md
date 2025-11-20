# Linked List Cycle Detection

**Author:** Anushka Hada  
**Email:** anhada@ucsc.edu  

---

## Description
This project implements a C function to **detect cycles in a singly linked list** using the **Floyd’s Tortoise and Hare algorithm** (two-pointer technique).  

### How it Works
- Two pointers, `slow_ptr` and `fast_ptr`, start at the head of the list.  
- `slow_ptr` moves **one step** at a time.  
- `fast_ptr` moves **two steps** at a time.  
- If there is a cycle in the list, the two pointers will eventually meet.  
- If the list is acyclic, `fast_ptr` reaches the end of the list (`NULL`) first.

### Function Signature
```c
int ll_has_cycle(node *head);
```
- Returns `1` if the linked list contains a cycle.  
- Returns `0` if the linked list is acyclic.  

---

## Files in the Repository

| File | Description |
|------|-------------|
| `ll_cycle.c` | Implementation of cycle detection function. |
| `ll_cycle.h` | Header file with the `node` struct definition and function prototype. |
| `README.md` | Project description and usage instructions. |

---

## Skills Demonstrated

- C programming and pointer manipulation  
- Linked list traversal  
- Algorithm implementation (Floyd’s cycle detection)  
- Understanding of fast/slow pointer technique  
