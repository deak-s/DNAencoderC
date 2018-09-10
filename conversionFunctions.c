/*
 * @file conversionFunctions.c
 * @author Sophia Deak
 * @date Sept 2018
 * @brief implementations of functions for converting between base encodings and data types
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "conversionFunctions.h"
int decToBase3(int x){

    int t = howManyTrit(x);
    printf(" %d trits\n", t);
    int array[t];
    int answer = 0;
    int decimalPlace = 1;

    for(int i = t - 1; i>= 0; i--){
       // decimal place * remainder of x / 3
        answer += (decimalPlace * (x %3)); 

        decimalPlace = decimalPlace * 10;
        x = floor(x / 3);
    }
    return answer;
}

int *decToBase3Array(int dec){
    int t = howManyTrit(dec);
    printf("dec array hmt %d\n", t);
    int *array = (int *)malloc( t * sizeof(int));

    for (int i = t - 1; i >=0; i--){
        printf("adding %d at pos %d\n", dec % 3, i);
        array[i] = dec % 3;
        dec = floor(dec / 3);
    }

    for(int y = 0; y < t; y++){
        printf("%d", array[y]);
    }

    return array;
}


double logBase3(double x){

    double answer = log(x) / log(3);
    return answer;
}

int howManyTrit(int x){

    double y = logBase3((double)x + 1);
    int answer = (int)ceil(y);

    return answer;
}

char encodeTrit(char prev, int trit){

    char next;
    switch(prev) {
        case 'A' :
            if (trit == 0){
                next = 'C';
            }
            else if (trit == 1){
                next = 'G';
            }
            else if (trit == 2){
                next = 'T';
            }
            else {
                next = 'X';
            }
            break;

        case 'C' :
            if (trit == 0){
                next = 'G';
            }
            else if (trit == 1){
                next = 'T';
            }
            else if (trit == 2){
                next = 'A';
            }
            else {
                next = 'X';
            }
            break;

        case 'G' :
            if (trit == 0){
                next = 'T';
            }
            else if (trit == 1){
                next = 'A';
            }
            else if (trit == 2){
                next = 'C';
            }
            else {
                next = 'X';
            }
            break;

        case 'T' :
            if (trit == 0){
                next = 'A';
            }
            else if (trit == 1){
                next = 'C';
            }
            else if (trit == 2){
                next = 'G';
            }
            else {
                next = 'X';
            }
            break;
        default :
            printf("error\n");
            break;
    }
    return next;

}
