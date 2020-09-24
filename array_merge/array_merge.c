#include "array_merge.h"
#include "mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  int total = 0; 
  
  for(int i = 0; i < num_arrays; ++i){
  total = total + sizes[i];
  }

  int* temp = (int *) calloc(total, sizeof(int));
  // counter for array of arrays (values)
  int i = 0;
  // counter for our temp array
  int n = 1;
  // length of our merged array of unique values
  int k = 0;
	
// ex run-through total is 1

  while(i != num_arrays){
  
	  for(int j = 0; j < sizes[i]; ++j){
		  if(!(isIn(values[i][j], temp, total))){
	  	  temp[n] = values[i][j];
		  k++;
		  n++;
		  }
	  }
  i++;
  }
  // sort our temp array
  mergesort(total,temp);

  int* finalArray = resizeArray(temp, k);
  // make sure we also put the length in there
  finalArray[0] = k;
  if (sizeof(temp) != 0){
  free(temp);
  }
  return finalArray;
}
	// case of value = 0, temp array passed, and size = total = 1 
   bool isIn(int value, int* array, int size){
   // check to see if our temp array already has a given value
   // with the exception f the 0th index which is reserved for k. (which can have one duplicate)
   for(int i = 1; i < size; ++i)
	if(array[i] == value){
	return true;
	}
   return false;
   }

   int* resizeArray(int* array,int k){
	   int* resizedArray = (int*) calloc(k + 1, sizeof(int));
	   for(int i = 1; i < k + 1; i++) {
		   resizedArray[i + 1] = array[i];
	   }
	   return resizedArray;
   }
