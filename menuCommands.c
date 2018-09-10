/*
 * @file menuCommands.c
 * @author Sophia Deak
 * @date Sept 2018
 * @brief   function wrappers for file or text conversion, to be linked with menu
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conversionFunctions.h"
#include "encodingFunctions.h"
#include "menuCommands.h"


void encodeFile( char name[]){

    FILE *file;
    char line[300];
    
    FILE *results = fopen("results.txt", "w");

    if((file = fopen(name, "r")) != NULL){

        while(fgets(line, sizeof(line), file) != NULL){            
            //counts chars in line
            int size = strlen(line); 
            printf("size is %d\n", size);


            char brief[size * 5];
            printf("line: %s\n", line);
            int x = encodeArray(line, brief, 40);
            
            fprintf(results, "%.*s",x, brief);

            fprintf(results, "\n");
            
            printf("\n"); 
        }

    }

fclose(file);
fclose(results);
}


void encodeText(){
    
    
    return;
}
