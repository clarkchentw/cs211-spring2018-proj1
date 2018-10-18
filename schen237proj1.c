/*
Program: Project 1 for CS211
Name: Clark Chen
NetID: schen237
Class: CS211
*/


#include <stdio.h>
#include <stdlib.h>
int nextSize = 1;
////////////////////////////////////////////////////////////
// Function for copy array
void arrayCopy (int fromArray[], int toArray[], int size){
	for (int i = 0; i < size; i++){
                toArray[i] = fromArray[i];
        }
}

////////////////////////////////////////////////////////////
// Function to sort the array using binary sort
void myFavorateSort (int arr[], int size){
	int temp  = 0;
	int swapped = 0;
	printf("sortSize: %d\n",  size);
	for (int i = 0; i < size-1; i++)
	{
		swapped = 0;
		for (int j = 0; j < size-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}

////////////////////////////////////////////////////////////
// linear search in the given array
int linSearch (int arr[], int size, int target, int *numComparisons){
	int result = -1;
	*numComparisons = 0;
	for (int i = 0; i < size; i++){
		(*numComparisons)++;
		if (arr[i] == target)
		{
			result = i;
			break;
		}
	}
	return result;
}

////////////////////////////////////////////////////////////
// Binary search on the given array
int binSearch (int arr[], int size, int target, int *numComparisons){
	int result = -1;
	*numComparisons = 1;
	int min = 0;
	int max = size-1;
	int mid = (max - min) / 2 + min;

	while (target != arr[mid]){
		(*numComparisons)++;
		if (target > arr[mid]){
			min = mid+1;
		}
		else
		{
			max = mid-1;
		}
		mid = (max - min) / 2 + min;
		if (min > max){
			mid = -1;
			break;
		}
	}
	result = mid;
	return result;
}

////////////////////////////////////////////////////////////
// Fill in data into the array
void fillArray(int inputArray[], int arraySize)
{
        for (int i = 0; i < arraySize; i++){
		printf("%d:%d ", i, i+10*nextSize);
                inputArray[i] = i+10*nextSize;
        }
	nextSize++;
}

////////////////////////////////////////////////////////////
// Function to display the whole array
void displayArray(int inputArray[], int inputSize)
{
	for (int i = 0; i < inputSize; i++){
                printf("%d\n", inputArray[i]);
        }
}


int main()
{
	// Variable used in program
	int i = 0; // for the loop
	int inputInt; // for scanf
	int arraySize = 5; // Current size of array
	int inputSize = 0; // Current array size, used for send in to function
	int *numComparisons = 0;
	int searchResult = -1;
	int *originalArray;
	int *sortedArray;
	int *tempArray; // used to expand the array

	// allocate space for original
	originalArray = (int*) malloc (sizeof(int) * arraySize);

	// Getting user input
	scanf ("%d", &inputInt);

	//// Reading process
	// Keep reading the user input until read -999
	while (inputInt != -999){
		inputSize++;
		if (arraySize <= i){
			tempArray = (int*) malloc (sizeof(int) * arraySize * 2);
			for (int x = 0; x < arraySize; x++){
				tempArray[x] = originalArray[x];
			}
			free(originalArray);
			originalArray = tempArray;
			arraySize = arraySize * 2;
		}
		originalArray[i] = inputInt;
		i++;
		scanf ("%d", &inputInt);
	}

	//// Begin process data
	// initialize sortedArray
	sortedArray = (int*) malloc (sizeof(int) * inputSize);
	
	// Copy originalArray to sortedArray
	arrayCopy(originalArray, sortedArray, inputSize);
	myFavorateSort(sortedArray, inputSize); // sort the array


	// Read in the checking data
	while (1 == 1) {
		printf("-----------------------------------------------------------\n");
		printf("Please type in a number to search(Terminate by input -999): \n");
		scanf ("%d", &inputInt);
		if (inputInt == -999)
		{
			// break when read in -999
			printf("\n");
			break;
		}
		
		// obtain search result
		searchResult = linSearch (originalArray, inputSize, inputInt, &numComparisons);

		//// Print out result
		printf("Linear Search Result:\n");
		if (searchResult == -1){
			printf("%d doesn't exist in the list.\n", inputInt);
		}else{
			printf("%d found in index %d\n", inputInt, searchResult);
		}
		printf("It takes %d times of comparisons to provide the result.\n\n", numComparisons);
		searchResult = binSearch(sortedArray, inputSize, inputInt, &numComparisons);

		printf("Binary Search Result:\n");
                if (searchResult == -1){
                        printf("%d doesn't exist in the list.\n", inputInt);
                }else{
                        printf("%d found in index %d\n", inputInt, searchResult);
                }
                printf("It takes %d times of comparisons to provide the result.\n\n\n", numComparisons);
	}

	return 0;
}

