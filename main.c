/*
 * @file main.c
 * @author Sophia Deak
 * @date Sept 2018
 * @brief ___
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conversionFunctions.h"
#include "encodingFunctions.h"
#include "menuCommands.h"
int main(){

    char testInput[] = "sprouts number5";
    char testOutput[200];

    printf("should be s: %c\n", testInput[0]);

   printf("result of 27 dtb %d\n", decToBase3(27));
    printf("result of 2 dtb %d\n", decToBase3(2));

    //printf("testing encode trit . . .\n");
    //printf("should b T - %c\n", encodeTrit('A', 2));
   // printf("should b A - %c\n", encodeTrit('G', 1));

    printf("dec to array of 27\n");
     int *tArray = decToBase3Array(27);
     
    for(int b = 0; b < 4; b++){
        printf("%d",tArray[b]);
                } 

   printf("encode array\n");

  encodeArray(testInput, testOutput, 11); 
printf("-------array finished encoding-----------\n");
/*
  for (int g = 0; g < 11; g++){
      printf("%c", testOutput[g]);
  }
    printf("\n");
*/



    printf("opening file\n");
    encodeFile("papers.txt");

    return 0;
}
