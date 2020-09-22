#include "mergesort.h"


void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
	int rangeSize = endIndex - startIndex;
	int *destination;
	// need to make sure to free destination array at some point
	destination = (int*)calloc(rangeSize, sizeof(int));
	int firstIndex = startIndex;
	int secondIndex = midPoint;
	int copyIndex = 0;
	while (firstIndex < midPoint && secondIndex < endIndex) {
		if (values[firstIndex] < values[secondIndex]) {
			destination[copyIndex] = values[firstIndex];
			++firstIndex;
		} else {
			destination[copyIndex] = values[secondIndex];
			++secondIndex;
		}
		++copyIndex;
	}
	while (firstIndex < midPoint) {
		destination[copyIndex] = values[secondIndex];
		++copyIndex;
		++firstIndex;
	}
	while (secondIndex < endIndex) {
		destination[copyIndex] = values[secondIndex];
		++copyIndex;
		++secondIndex;
	}
	for (int i = 0; i < rangeSize; i++) {
		values[i + startIndex] = destination[i];
	}
	free(destination);
}

bool needsSorting(int rangeSize) {
	return rangeSize >= 2;
}

void mergesortRange(int values[], int startIndex, int endIndex) {
	int rangeSize = endIndex - startIndex;
	if (needsSorting(rangeSize)){
		int midPoint = (startIndex + endIndex) / 2;
		mergesortRange(values, startIndex, midPoint);
		mergesortRange(values, midPoint, endIndex);
		mergeRanges(values, startIndex, midPoint, endIndex);
	}
}


void mergesort(int size, int values[]) {
	mergesortRange(values, 0, size);
}



