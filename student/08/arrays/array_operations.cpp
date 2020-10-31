#include "array_operations.hh"
#include <iostream>

using namespace std;

int greatest_v1(int* itemptr, int size){
    int* max_ptr= itemptr;

    for(int* position = itemptr; position < itemptr + size; ++position){
        if (*position > *max_ptr)
            {
                max_ptr = position;
            }
    }
    return *max_ptr;
}

int greatest_v2(int* itemptr, int* endptr){
    int* max_ptr= itemptr;

    for(int* position = itemptr; position < endptr; ++position){
        if (*position > *max_ptr)
            {
                max_ptr = position;
            }
    }
    return *max_ptr;
}

void copy(int* itemptr, int* endptr, int* targetptr){

    for(int* position = targetptr; position < endptr; ++position){
        *(targetptr++) = *(itemptr++);
    }
}

/* Reverses the elements of the array
 * int* leftptr: pointer to the first element of the reversable part
 * int* rightptr: pointer to the next memory address after the reversable part
 */
void reverse(int* leftptr, int* rightptr){
    int temp = 0;

    while(leftptr < rightptr){
        temp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;
        leftptr++;
        rightptr--;
    }
}







