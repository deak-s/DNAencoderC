/**
 * @file encodingFunctions.c
 * @author Sophia Deak
 * @date Sept 2018
 * @brief implementations of encoding functions for dna encoder
 */

#include <stdio.h>
#include <stdlib.h>

#include "encodingFunctions.h"
#include "conversionFunctions.h"

int encodeArray(char input[], char output[]){
   
   int tritCounter = 0; 
   int x;
    //iterate through char array
    //use to be (int)input[x] != 0
      for(x = 0; (int)input[x] != 0; x++){

          int t = howManyTrit((int)input[x]);

          int *tritArray = decToBase3Array((int)input[x]); 


          //first trit to output array
          //assumes prev element was 'A'
          if(tritCounter == 0){
              output[0] = encodeTrit( 'A', tritArray[0]);
              tritCounter += 1;

              for(int k = 1; k <t; k++){
                  output[tritCounter] = encodeTrit(output[tritCounter - 1], tritArray[k]);
                  tritCounter += 1;
              }
          }

          //now have trit array repping one input char
          //must iterate through trit[] and swap to base pair
          else {
              for(int k = 0; k < t; k++){


                  output[tritCounter] = encodeTrit(output[tritCounter - 1], tritArray[k]);

                  tritCounter += 1;
              }
          }
           }

      output[tritCounter + 1] = '\0';

/*
      for (int j = 0 ; j < tritCounter; j++){
          printf("%c", output[j]);
      }*/
//      printf("results:\n%d characters encoded\n%d bases\n", x, tritCounter);
    return tritCounter;
}


