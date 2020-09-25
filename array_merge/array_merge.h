#ifndef ARRAY_MERGE_H_GUARD
#define ARRAY_MERGE_H_GUARD

#include <cstdlib>
#define UNIT_TESTING

int* array_merge(int num_arrays, int* sizes, int** values);
bool isIn(int value, int* array, int size);
int* resizeArray(int* array, int k);
void mergesort(int size, int *values);
bool containsZero(int** values, int num_array, int* sizes, int* temp);


#endif
