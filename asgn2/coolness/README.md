Coolness, Anushka Hada, anhada@ucsc.edu

Description: Coolness file takes in argument Temprature and Wind. It then calculates “coolness” as a function of wind speed and temperature. When arguments are passed T is the first argument, V second. 

In case of one argument, take that one argument as Temp and find coolness using the wind speed values 5,10,15. 

In case of two argument, find coolness as is. 

In case of two and above arguments, return error and exit with 1.

In case of wrong inputs for T and wind speed return error and exit with 1.

In case of no inputs. The program calculates coolness for a range of parameters: T from -10 to 40 in steps of 10, and V from 5 to 15 
in steps of 5. If the program terminates normally, it exits with return code 0. Otherwise, it exits with return code 1. 

File names and what they do:

.gitignore: Allows unwanted files to be not included when compiled

coolness.c: Program containg code

testing.out: Test script made when running testing.sh.

testing.sh: Basic testing script to ensure that program runs as expected. 

Makefile: Complies files

README.md: Discription of files 		

How to compile:Enter "make" on terminal under the directory that contans the files

How to run it: Enter "gcc -o coolness coolness.c -lm" and then "./coolness k n" to run manually on terminal.

