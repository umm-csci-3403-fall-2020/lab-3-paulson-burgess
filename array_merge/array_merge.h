#ifndef ARRAY_MERGE_H_GUARD
#define ARRAY_MERGE_H_GUARD

#include <cstdlib>
#define UNIT_TESTING

int* array_merge(int num_arrays, int* sizes, int** values);
bool isIn(int value, int* array, int size);
void resizeArray(int* array,int* newArray, int k);
void mergesort(int size, int *values);



#endif
