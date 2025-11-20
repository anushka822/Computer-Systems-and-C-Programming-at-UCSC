# Histogram

**Author:** Anushka Hada  
**Email:** anhada@ucsc.edu  

---

## Description
`Histogram` is a C program that takes user inputs and visualizes them as a histogram.  
- Inputs outside the range `[0,16)` are **doubled**.  
- Inputs within defined **bin ranges** are represented with **asterisks**.  

This project demonstrates **C programming, input validation, file compilation with Makefile, and basic data visualization**.

---

## Files in the Repository

| File | Description |
|------|-------------|
| `.gitignore` | Excludes unnecessary files from the repository. |
| `histogram.c` | Main program source code. |
| `testing.out` | Output from testing scripts. |
| `testing.sh` | Script to test the histogram program. |
| `Makefile` | Compiles the program. |
| `README.md` | Project description and instructions. |

---

## How to Compile

1. Open a terminal in the project directory.  
2. Run:
```
make
```
This compiles the program and generates the executable `histogram`.

---

## How to Run

1. Execute the program:
```
./histogram
```
2. Enter the inputs.  
3. Press **Ctrl + D** to end input and display the histogram.

---

## Skills Demonstrated

- C programming and input handling  
- Makefile usage and build automation  
- Writing test scripts for program verification  
- Data visualization with ASCII histograms
