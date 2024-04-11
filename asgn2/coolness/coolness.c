#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define sizeV 3
#define sizeT 6

/// is digit to check if its number
// make function to print temp,wind, coolness
// main checks arguments
// once checked it sends to different function to print stuff
// function one with two intputs just has coolness expression
// function with no arguments gives 

double ifTwo( double T, double V);
double None();
double ifOne( double T);


int main(int argc, char* argv[])
{
    double T, V;
    
    /// file 1, 30: 2, 10: 3
    // count coolness 10 30 - 3
    // [0, 1, 2]-index
    

    //printf("arg 1: %s, arg 2: %s, arg 3: %s\n", argv[1], argv[2], argv[3]);
    
     // if argument count is 2: coolness 20 
    if(argc == 2){
        //send to function ifOne. check once more that Temp is within range
        T = atof(argv[1]);
        
        // check if digit
        // Ensure that T and V are within these values:  -99 <= T <= 50 and 0.5 <= V
        if ( !( -99 <= T && T <= 50) ) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
            exit(1);
        }
        else {
            ifOne(T);

        }           
    }
    
    // if argument count above 3 file # #
    else if(argc > 3) {
        printf("Usage: ./coolness [temperature] [wind speed]\n");
        exit(1);
    }
    
    // if argument count is 3: coolness 30 10
    else if(argc == 3){
        T = atof(argv[1]);
        V = atof(argv[2]);
          
        
        // Ensure that T and V are within these values:  -99 <= T <= 50 and 0.5 <= V
        if ( !( -99 <= T && T <= 50 && 0.5 <=V) ) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
            exit(1);
        }    
        else{ 
            // Put T and V into function. Then get result and return it 
            ifTwo(T, V);
            return 1;
        }

    }
   

    // if argument count is NONE
    else{
        None();
    }


    return 0;
}
double ifTwo( double T, double V){
    double coolness;
    coolness = 35.74 + (0.6215 * T) - 35.75 * (pow(V, 0.16)) + (0.4275 * T) * (pow(V, 0.16));

    printf("Temp\tWind\tCoolness\n");
    printf("%.1lf\t%.1lf\t%.1lf\n", T, V, coolness);
}

double ifOne( double T){
    double V = 5, V2 = 10, V3 = 15, coolness, coolness2, coolness3;

    coolness = 35.74 + (0.6215 * T) - 35.75 * (pow(V, 0.16)) + (0.4275 * T) * (pow(V, 0.16));
    coolness2 = 35.74 + (0.6215 * T) - 35.75 * (pow(V2, 0.16)) + (0.4275 * T) * (pow(V2, 0.16));
    coolness3 = 35.74 + (0.6215 * T) - 35.75 * (pow(V3, 0.16)) + (0.4275 * T) * (pow(V3, 0.16));

    printf("Temp\tWind\tCoolness\n");
    printf("%.1lf\t%.1lf\t%.1lf\n", T, V, coolness);
    printf("%.1lf\t%.1lf\t%.1lf\n", T, V2, coolness2);
    printf("%.1lf\t%.1lf\t%.1lf\n", T, V3, coolness3);  

}
double None(){
    double V[sizeV] = {5, 10, 15};
    double T[sizeT] = {-10.0, 0, 10, 20, 30, 40 };
    double coolness; 
    
    // iterates 3 times
    // iterates 18 times
    printf("Temp\tWind\tCoolness\n");
    
    for(int j = 0; j < sizeT; j++){
        for (int i = 0; i < sizeV; i++) {
            coolness = 35.74 + (0.6215 * T[j]) - 35.75 * (pow(V[i], 0.16)) + (0.4275 * T[j]) * (pow(V[i], 0.16));
            printf("%.1lf\t%.1lf\t%.1lf\n", T[j], V[i], coolness);
            
        }
        if (j < (sizeT -1 )) {
            printf("\n");
            }
        }
         

}







