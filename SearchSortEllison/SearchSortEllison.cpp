
#include <iostream>
#include <random>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <array>

using namespace std;

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

int main() {
	const int SIZE = 10000;
	int RandNum[SIZE];
	int random;
	int searchNum = 152;
	int searchResult = -1;
	srand(time(0));  //seeds random number generator to populate array


	for (int i = 0; i < SIZE; i++) {
		random = rand() % 1000 + 1;
		RandNum[i] = random;
	}

	for (int i = 0; i < SIZE; i++) {
		cout << RandNum[i] << " ";
	}
	cout << endl;

/*	Linear search goes through each element of an array and compares it to
*	the number being searched for. It is slower than a binary search, but
*	does not require a sorted array. It should only be used on smaller data
*	sets when an exact match is required.
*/

	searchResult = linearSearch(RandNum, SIZE, searchNum);
	if (searchResult == -1) {
		cout << "The number "<< searchNum << " is not present in the array." << endl;
	}
	else {
		cout << "The first instance of number " << searchNum << " is at index " << searchResult << "." << endl;
	}

	//sort array

	/*	Binary search uses a sorted array. It divides the array in half and checks 
	*	if the number to find is the same as the middle, higher, or lower. If same,
	*	returns the middle index, if lower, repeats the search with the lower half
	*	of the array. If higher, repeats the search with the higher half. Continues
	*	deviding and checking the middle until the number is found or all possible
	*	subarrays in range have been searched. This is faster than a linear search,
	*	but requires a sorted array.
	*/

	searchResult = binarySearch(RandNum, 0, SIZE-1, searchNum);  
	if (searchResult == -1) {
		cout << "The number " << searchNum << " is not present in the array." << endl;
	}
	else {
		cout << "The first instance of number " << searchNum << " is at index " << searchResult << "." << endl;
	}

}

