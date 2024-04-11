#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int function(int Left, int Right, int Input_Array[], int Input_Array_Size);
int main(){
    int a, Histogram_Static_Size = 16, Histogram_Max = 16, Histogram_Interval_Size = 1; 
    int Left, Right; 
    
    int Input_Array_Size = 0; 
    int *Input_Array = NULL; // Initialize the array to NULL.
    
      
    int Histogram[Histogram_Static_Size][2];

    int numberOfastrick = 3;
    char asterisks[Histogram_Static_Size];



    printf("16 bins of size 1 for range [0,16)\n");
     
    // Read in input util ctrl+D
    while( scanf( "%d", &a) != EOF){
        Input_Array_Size++;
        Input_Array = (int *)realloc(Input_Array, Input_Array_Size * sizeof(int)); 
        Input_Array[Input_Array_Size - 1] = a; // Allocate memory for the updated size. Used stackoverflow as I am not that familier with dynamic arrays in C
        
        if (Input_Array == NULL) {
            printf("Failure");
            exit(1);
        }
        
        while(a > Histogram_Max-1){
            Histogram_Max = Histogram_Max * 2; // 16 becoms 32
            Histogram_Interval_Size = Histogram_Interval_Size * 2; // 1 becoms 2 
            
            printf("16 bins of size %d for range [0,%d)\n", Histogram_Interval_Size, Histogram_Max );
        }
    }




    // Makes bins
    for (int i = 1; i < Histogram_Static_Size; i++) {
        Histogram[i][0] = i * Histogram_Interval_Size;
        Histogram[i][1] = Histogram[i][0] + (Histogram_Interval_Size - 1);
    }
    // Hardcode the first stuff
    Left = 0;
    Histogram[0][0] = Left;
    Right = 0 + Histogram_Interval_Size-1;
    Histogram[0][1] = Right;

    char returnedString;
    for (int i = 0; i < Histogram_Static_Size; i++) {
        function(Histogram[i][0] , Histogram[i][1], Input_Array, Input_Array_Size);
        printf("\n");
    }
     
        
        





    free(Input_Array); // Free memory or else program breaks. Do this at the end 
    return 0;
}


int function(int Left, int Right, int Input_Array[], int Input_Array_Size){
    int StringSize = 1;
    char myString[StringSize];

    for (int i = 0; i < Input_Array_Size; i++) {

        int num = Input_Array[i];
        if (Left <= num && num <= Right){
            //printf("Inside if");
            StringSize++;
            myString[StringSize-1] = '*';    
        }
    }
    
    printf("[%3d:%3d] ", Left, Right);
    for (int j = 0; j < StringSize; j++){
        if(myString[j] == '*'){
            printf("%c", myString[j] ); 

        }
        
    }



}





/* Extra code for testing

printf("L %d\n", Left);
    printf("Right %d\n", Right);
printf("You entered the following integers:\n");
    for (int i = 0; i < Input_Array_Size; i++) {
        printf("%d\n", Input_Array[i]); // Print the elements of the array
    }
    //Histogram[i][0] = Left; 
        //printf("Histogram[i][0] = Left; gives us %d\n", Histogram[i][0]);


    // I am able to retrive histogram max/interval size outside 
    printf("Histogram_Max %d \n", Histogram_Max);
    printf("Histogram_Interval_Size %d \n", Histogram_Interval_Size); 

    // orint input array 
    for (int i = 0; i < Input_Array_Size; i++) {
        printf("%d, Input_Array[i]\n", Input_Array[i]);
    }
        
    //printf("After for loop Histogram[0][0] %d\n", Histogram[0][0]);
    //printf(" After for loop Histogram[0][1] %d\n", Histogram[0][1]);
    // Print the array of asterisks for each range


       // Print the 'asterisks' array
        printf("astrick array InputArraySize: %d\n",Input_Array_Size );
        for (int i = 0; i < Input_Array_Size; i++) {
            
            for (int j = 0; j < 16; j++) {
                printf("astrick[%d][%d] : %c \n", i, j, asterisks[j][i]);
            }
            printf("\n");
        }


for (int i = 0; i < Input_Array_Size; i++) {
        int num = Input_Array[i];
        printf("Input_Array[i] %d \n", Input_Array[i]);
            
        //loop through array
        for (int col = 0; col < 16; col++) {

            // if input > left or less than right then append asterick
            if ( (num >= Histogram[col][0])  &&  (num <= Histogram[col][1]) ) {
                    
                    printf("[%d,%d] \n", Histogram[col][0], Histogram[col][1] );
                    printf("Inside IF Input_Array[i] %d\n", num);
                    
                    asterisks[col] += string; // assign astericks to asterick array 
                    
                    
                    //printf("FOR col: %d i: %d asterisks[col][i]: %d BIN [%d, %d] Input: %d \n", col, i, asterisks[col][i], Histogram[col][0], Histogram[col][1], Input_Array[i] );
                }
                printf("col %d asterisks[col] %c \n", col, asterisks[col]);
                
            }   
        }






}








*/









