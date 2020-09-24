#ifndef MERGESORT_H_GUARD
#define MERGESORT_H_GUARD

#include <stdbool.h>
#include <cstdlib>

#define UNIT_TESTING

void mergesort(int size, int values[]);
void mergesortRange(int *values, int startIndex, int endIndex);
void mergeRanges(int *values, int startIndex, int midPoint, int endIndex);
bool needsSorting(int rangeSize);

#endif
