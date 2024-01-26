/*
  main.c
  Patricia_Antlitz_HW-Lec01-C

  Created by Patricia Antlitz on 1/18/23.
 
 We are going to roll several 6-sided dice.  The number of dice is entered through keyboard (from 2 to 5).  The value for each thrown die is a random number (1~6)
 •    save all die values to an array
 •    calculate the sum and the average of all dice
 •    display the value for each die, the sum and average
*/

//tells the preprocessor which secondary libraries/classes to use
//main language functionality
#include <stdio.h> //printf() scanf()
//for random
#include <stdlib.h> //srand() rand()
//random number seed
#include <time.h>

//constant global variable -> this are pure text replacement, no real value attached to it
//#define MAX_NUM = 6;

void generateRandom(int numDices) {
    
    //the array size, and number of dice faces cannot be changed
    const int maxVal = 6;
    //array of size 6
    //there are commonly two ways to create an array
    //this is the static array, in which you must pass a value to as the size
    int storeArray[maxVal];
    //the second way is more efficient, to declare a dynamic array that uses dynamic allocation.
    //int *array = (int*)malloc(sizeof(int)*numDices);
    //for big arrays
    //will have to clear after calling/printing by :
    //free(array);
    
    //will hold 1 random number
    int randomNum;
    int sumOfNums = 0;
    double averageNum = 0;
    //time seed, allows different random numbers to be generated each time
    srand ((unsigned) time(NULL) );
    
    printf("\nValue of dices: \n");
    //loop loops n times (given by user and passed as a parameter)
    for(int i = 0; i < numDices; i++)
    {
        //get rand numbers from 1-6
        randomNum = (rand() % maxVal) + 1;
        //each number is stored in the array
        storeArray[i] = randomNum;
        
        printf("%d ", storeArray[i]);
        //calculations for sum and average
        sumOfNums += randomNum;
        averageNum = (double)sumOfNums / maxVal;
    }
    
    printf("\nSum = %d \n", sumOfNums);
    printf("Average = %0.2f \n", averageNum);
}

int main(int argc, const char * argv[]) {
    
    int userNumber;
    int i = 0;
    // insert code here...
    printf("We are going to roll several 6-sided dices\n");
    printf("Enter the number of dices you want to roll (from 2 to 5):\n");
    //gets user's entry
    scanf("%d", &userNumber);

    while(i >= 0)
    {
        //will not allow the user to pick a number smaller than 2 or greater than 5
        if(userNumber < 2 || userNumber > 5)
        {
            printf("Incorrect number to rolls, please try again:\n");
            scanf("%d", &userNumber);
        }
        else
        {
            printf("\nRolling %d dices...\n", userNumber);
            generateRandom(userNumber);
            //gets out of the loop
            break;
        }
    }
    
    return 0;
}
