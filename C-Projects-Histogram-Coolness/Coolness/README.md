# Coolness

**Author:** Anushka Hada  
**Email:** anhada@ucsc.edu  

---

## Description
`Coolness` is a C program that calculates a “coolness” value as a function of **temperature** and **wind speed**.  

Behavior based on inputs:  
- **No arguments:** Calculates coolness for a range of parameters:  
  - Temperature (T) from -10 to 40 in steps of 10  
  - Wind speed (V) from 5 to 15 in steps of 5  
- **One argument:** Treats the argument as temperature (T) and calculates coolness for wind speeds 5, 10, 15  
- **Two arguments:** Calculates coolness for the given temperature and wind speed  
- **More than two arguments:** Returns an error and exits with code 1  
- **Invalid inputs for T or wind speed:** Returns an error and exits with code 1  
- **Normal termination:** Program exits with code 0  

---

## Files in the Repository

| File | Description |
|------|-------------|
| `.gitignore` | Excludes unwanted files from the repository. |
| `coolness.c` | Main program source code. |
| `testing.out` | Output from testing scripts. |
| `testing.sh` | Script to test the program behavior. |
| `Makefile` | Compiles the program. |
| `README.md` | Project description and instructions. |

---

## How to Compile

1. Open a terminal in the project directory.  
2. Run:  
```
make
```
This will compile `coolness.c` into the executable `coolness`.

---

## How to Run

1. Manually compile (alternative to Makefile):  
```
gcc -o coolness coolness.c -lm
```
2. Run the program with temperature and wind speed arguments:  
```
./coolness [T] [V]
```
3. Follow the rules above for the number of arguments.  

---

## Skills Demonstrated

- C programming and command-line argument handling  
- Input validation and error handling  
- Makefile usage for compilation  
- Writing and running basic testing scripts
