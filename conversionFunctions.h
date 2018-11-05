/*
 * @file conversionFunctions.h
 * @author Sophia Deak
 * @date Sept 2018
 * @brief header file for functions that convert between encodings and data types
 */

#ifndef CONVERSIONFUNCTIONS_H
#define CONVERSIONFUNCTIONS_H

/**
 * @brief converts a decimal to base3
 * @param[in] x  base 10 integer to convert
 * @return integer converted into base3
 */
int decToBase3(int x);

int *decToBase3Array(int x);
/**
 * @brief calculates log base 3 of a number
 * @param[in] x  number to calculate log base 3 of
 * @return  double  calculated result
 */
double logBase3(double x);

/**
 * @brief  calculates how many trits needed to represent a decimal number
 * @param[in]  x  decimal number to evaluate
 * @return    int  how many trits needed
 */
int howManyTrit(int x);

/**
 * @brief  encodes a ternary digit into a DNA base, depends on previous char
 * @param[in] prev    previous char in sequence
 * @param[in] trit    ternary digit to encode
 * @return    char   encoded trit
 */
char encodeTrit(char prev, int trit);


#endif
