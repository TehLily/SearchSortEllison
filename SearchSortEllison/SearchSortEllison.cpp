/*
LINEAR SEARCH
Write a linear search method to find a number in the list. Call this before each of your sort methods. Include a comment explaining how Linear Search works, when to use it, when you cannot.
BINARY SEARCH
Write a binary search method to find a number in the list. Call this after each of your sort methods. Include a comment explaining how Binary Search works, when to use it, when you cannot.

BUBBLE SORT
Insert 10,000 items. Display the data before and after the sort. You’ll see that scrolling the display takes a long time. Take Screenshot Number 1 of the your code.
Next comment out the calls to any display or print methods, that was just to verify it was working. Additionally, you will not want to try to print a list of 100,000 items, likely your console cannot handle it and your program will hang. Add timing to see how long the sort itself takes with 10,000 items. The time will vary on different machines. Take Screenshot Number 2 of your results.
Sorting 100,000 numbers will probably take less than 30 seconds. Now, select an array size, it will be trail and error, that takes about this long and time it. Take Screenshot Number 3 of these results.
SELECTION SORT
Now, perform the same experiment on the Selection Sort using the same timing method you used. This will be  Screenshot Number 4, Screenshot Number 5, Screenshot Number 6.
INSERTION SORT
Now, perform the same experiment on the Selection Sort using the same timing method you used. This will be  Screenshot Number 7, Screenshot Number 8, Screenshot Number 9.


*/




#include <iostream>
#include <random>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <array>

using namespace std;

void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {  //print
		cout << arr[i] << " ";
	}
	cout << endl;
}

int linearSearch(int arr[], int arrSize, int numToFind) { //linear search method from GeeksForGeeks, modified
	int i;
	for (i = 0; i < arrSize; i++) {
		if (arr[i] == numToFind) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int leftIndex, int rightIndex, int numToFind) {  //binary search method from GeeksForGeeks, modified
	if (rightIndex >= leftIndex) {
		int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
		if (arr[midIndex] == numToFind) {
			return midIndex;
		}
		if (arr[midIndex] > numToFind) {
			return binarySearch(arr, leftIndex, midIndex - 1, numToFind);
		}
		return binarySearch(arr, midIndex + 1, rightIndex, numToFind);
	}
	return -1;
}

void bubbleSort(int arr[], int arrSize) { //Bubble Sort method from GeeksForGeeks, modified
	int i, j;
	for (i = 0; i < arrSize; i++) {
		for (j = 0; j < arrSize - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void selectSwap(int* num1, int* num2) {  //Swap function for Selection Sort
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void selectionSort(int arr[], int arrSize) {  //Selection Sort method from GeeksForGeeks, modified
	int i, j, minIndex;
	for (i = 0; i < arrSize - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < arrSize; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
			if (minIndex != i) {
				selectSwap(&arr[minIndex], &arr[i]);
			}
		}
	}
}

void insertionSort(int arr[], int arrSize) {
	int i, key, j;
	for (i = 1; i < arrSize; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main() {
	const int SIZE = 10000;
	int RandNum[SIZE];
	int random;
	int searchNum = 152;
	int searchResult = -1;
	srand(time(0));  //seeds random number generator to populate array


	for (int i = 0; i < SIZE; i++) {  //population of array with random numbers
		random = rand() % 1000 + 1;
		RandNum[i] = random;
	}
	/*BLOCK OUT RANDOM ORDER DISPLAY****************************************
	cout << "Random array: " << endl;

	printArray(RandNum, SIZE);
	**********************************************************************/

	/* BLOCK OUT LINEAR SEARCH*******************************************
	Linear search goes through each element of an array and compares it to
	*	the number being searched for. It is slower than a binary search, but
	*	does not require a sorted array. It should only be used on smaller data
	*	sets when an exact match is required.
	
	
	searchResult = linearSearch(RandNum, SIZE, searchNum);
	if (searchResult == -1) {
		cout << "The number "<< searchNum << " is not present in the array." << endl;
	}
	else {
		cout << "The first instance of number " << searchNum << " in unsorted array is at index " << searchResult << "." << endl;
	}
	****************************************************************************/

	/*  BLOCK OUT BUBBLE SORT ****************************************************
	//start timer for bubble sort:
	clock_t start = clock();

	//Bubble Sort
	bubbleSort(RandNum, SIZE);

	//stop timer for bubble sort:

	clock_t ticks = clock() - start;
	//print results:
	cout << "Time to sort " << SIZE <<" entries using Bubble sort : " << (double)ticks / CLOCKS_PER_SEC << " seconds." << endl;

	*******************************************************************************/
	/*BLOCK OUT BUBBLE SORT PRINT *************************************************
	cout << "Array, sorted with bubble sort: " << endl;

	printArray(RandNum, SIZE);
	***********************************************************************************/

	/* BLOCK OUT BINARY SEARCH *********************************************************
	Binary search uses a sorted array. It divides the array in half and checks
*	if the number to find is the same as the middle, higher, or lower. If same,
*	returns the middle index, if lower, repeats the search with the lower half
*	of the array. If higher, repeats the search with the higher half. Continues
*	deviding and checking the middle until the number is found or all possible
*	subarrays in range have been searched. This is faster than a linear search,
*	but requires a sorted array.

	searchResult = binarySearch(RandNum, 0, SIZE - 1, searchNum);
	if (searchResult == -1) {
		cout << "The number " << searchNum << " is not present in the array." << endl;
	}
	else {
		cout << "The first instance of number " << searchNum << " after bubble sort is at index " << searchResult << "." << endl;
	}
********************************************************************************************/

//BLOCK OUT SELECTION SORT***********************************************************************

	//start timer for selection sort:
	clock_t start = clock();

	//Selection Sort
	selectionSort(RandNum, SIZE);

	//stop timer for selection sort:

	clock_t ticks = clock() - start;
	//print results:
	cout << "Time to sort " << SIZE << " entries using Selection sort : " << (double)ticks / CLOCKS_PER_SEC << " seconds." << endl;
	//*******************************************************************************************/
	/*BLOCK OUT SELECTION PRINT******************************************************************
	cout << "Array, sorted with selection sort: " << endl;

	printArray(RandNum, SIZE);
//******************************************************************************************/


	/*BLOCK OUT BINARY SEARCH**************************************************************
	searchResult = binarySearch(RandNum, 0, SIZE - 1, searchNum);
	if (searchResult == -1) {
		cout << "The number " << searchNum << " is not present in the array." << endl;
	}
	else {
		cout << "The first instance of number " << searchNum << " after selection sort is at index " << searchResult << "." << endl;
	}
	//**************************************************************************************/
	

	/*BLOCK OUT INSERTION SORT***************************************************************

		//start timer for insertion sort:
	clock_t start = clock();

	//Insertion Sort
	insertionSort(RandNum, SIZE);

	//stop timer for insertion sort:

	clock_t ticks = clock() - start;
	//print results:
	cout << "Time to sort " << SIZE << " entries using Insertion sort : " << (double)ticks / CLOCKS_PER_SEC << " seconds." << endl;
	******************************************************************************************/
	
	
	/*BLOCK OUT INSERTION PRINT***************************************************************
	cout << "Array, sorted with insertion sort: " << endl;

	printArray(RandNum, SIZE);


	******************************************************************************************/
	

	/*BLOCK OUT BINARY SEARCH**************************************************************
	searchResult = binarySearch(RandNum, 0, SIZE - 1, searchNum);
	if (searchResult == -1) {
		cout << "The number " << searchNum << " is not present in the array." << endl;
	}
	else {
		cout << "The first instance of number " << searchNum << " after insertion sort is at index " << searchResult << "." << endl;
	}
	**************************************************************************************/

}


