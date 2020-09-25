#include "array_merge.h"
#include "mergesort.h"

// function that generates a single sorted list of the unique values in an array of arrays. (small -> large)
int* array_merge(int num_arrays, int* sizes, int** values) {
  int total = 0; 
  
  for(int i = 0; i < num_arrays; ++i){
  total = total + sizes[i];
  }
  // our array to hold the unique values in our values array (with extra memory allocated for safety)
  int* temp = (int *) malloc(total* sizeof(int));
  // counter for our temp array
  int n = 0;
  // length of our merged array of unique values
  int k = 0;
  // while we haven't gone through all of the exterior arrays...
  for(int i = 0; i < num_arrays; i++){
  	  // so long as there is still stuff to iterate through in the interior array...
	  for(int j = 0; j < sizes[i]; ++j){
		  // and our temp array doesn't already have the value stored in that index...
		  if(!(isIn(values[i][j], temp, k))){
		  // it's a unique value -> chuck it in our temp array.
	  	  temp[n] = values[i][j];
		  // we only increment temp stuff in our if statement so we don't get gaps in the array
		  k++;
		  n++;
		  }
	  }
  }
  // sort our temp array
  mergesort(k,temp);

  // make sure we also put the length in there
  int* finalArray = resizeArray(temp,k);
  finalArray[0] = k;
  return finalArray;
}
   // function that checks to see if the passed array already has the passed value in it
   // returns true if it already has it and false if it doesn't 
   bool isIn(int value, int* array, int size){
   for(int i = 0; i < size; ++i){
	if(array[i] == value){
	return true;
	}
   }
   return false;
   }
   // copies the values in our temporary array into a resized array that only allocates exactly the memory it needs.
   int* resizeArray(int* array,int k){
	   int* resizedArray = (int*) malloc((k + 1)* sizeof(int));
	   // starts copying at index 1 instead of 0 to leave room for k at the start.
	   for(int i = 0; i < k; i++) {
		   resizedArray[i + 1] = array[i];
	   }
	   // should be able to free the memory given to temp now
	   free(array);
	   return resizedArray;
   }
	
