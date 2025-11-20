# Password Checker

**Author:** Anushka Hada  
**Email:** anhada@ucsc.edu  

---

## Description
`Password Checker` is a C program that verifies whether a password meets specified security requirements.  

### Password Requirements
- Minimum length: **10 characters**  
- Must contain at least:  
  - **1 uppercase letter**  
  - **1 lowercase letter**  
  - **1 number**  
- Must **not contain the user's first or last name** (case-sensitive)  

The program demonstrates **C programming, string handling, input validation, and modular function design**.

---

## Files in the Repository

| File | Description |
|------|-------------|
| `password_checker.c` | Main program source code implementing all checks. |
| `README.md` | Project description and instructions. |

---

## How to Compile

1. Open a terminal in the project directory.  
2. Compile the program using GCC:  
```
gcc -o password_checker password_checker.c -lm
```

---

## How to Run

1. Run the executable with your desired input:  
```
./password_checker
```
2. Follow prompts or modify the code to test different first name, last name, and password combinations.

---

## Skills Demonstrated

- C programming and string manipulation  
- Modular function design  
- Input validation and error checking  
- Logical operations and boolean handling
