/*
 * @file menuCommands.c
 * @author Sophia Deak
 * @date Sept 2018
 * @brief   function wrappers for file or text conversion, to be linked with menu
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "conversionFunctions.h"
#include "encodingFunctions.h"
#include "menuCommands.h"


void encodeFile(char name[]){


    int y, x;
    getmaxyx(stdscr, y, x);
    FILE *file;
    char line[300];
    
    FILE *results = fopen("results.txt", "w");

    int k = 0;
    if((file = fopen(name, "r")) != NULL){

        while(fgets(line, sizeof(line), file) != NULL){            
            //counts chars in line
            int size = strlen(line); 
//            printf("size is %d\n", size);


            char brief[size * 5];
  //          printf("line: %s\n", line);
            int s = encodeArray(line, brief);
            
            fprintf(results, "%.*s",x, brief);
            mvprintw(1 +k, 2 , "%.*s", s, brief);

            fprintf(results, "\n");
            k++;
            
    //        printf("\n"); 
        }

    }

fclose(file);
fclose(results);
}


void encodeText(){
    
    char line[100];
    char output[500];

    FILE *results = fopen("results.txt", "w");

    printf("enter text to encode\n");
    fgets(line, 100, stdin);

    printf("input is %s\n", line);
    int x = encodeArray(line, output);
    printf(" result is %.*s\n", x, output);

    fprintf(results, "%.*s\n", x, output);

    fclose(results);
    
    return;
}
