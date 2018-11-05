/**
 * @file encodingFunctions.h
 * @author Sophia Deak
 * @date Sept 2018
 * @brief header file for dna encoding functions
 */

#ifndef ENCODINGFUNCTIONS_H
#define ENCODINGFUNCTIONS_H
//base 3 encode a line (with spaces

/**
 * @brief encodes an array of text into an array of DNA bases
 * @param[in]  input[]   char array of text to encode
 * @param[out] output[]  char array of DNA bases 
 * @return     int  number of chars needed to encode text (size of output)
 */
int encodeArray(char input[], char output[]);


#endif
