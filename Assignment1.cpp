/*
Use this code to submit your assignment #1.


Complete the missing lines, test your code, and then submit your answers.

Methods to be completed:
	* mystery1()


*/


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// const array size
const int ARRAY_SIZE = 50;

// max value for random numbers
const int MAX_RAND = 100;


// function to fill an input array with random numbers
// in range [-MAX_RAND, MAX_RAND]
void fillRandomNumbers(int a[], const int size) {

	srand(time(NULL));
	if (size >= 1) {
		for (int i = 0; i < size; i++)
			a[i] = (rand() % (2 * MAX_RAND + 1)) - MAX_RAND;
	}
	else {
		cerr << "invalid array size ..." << endl;
	}
}

// print the unput array, 10 numbers per line
void printArray(int a[], const int size) {

	if (size >= 1) {
		for (int i = 0; i < size; i++) {
			cout << a[i] << "\t";
			if (i % 10 == 0)
				cout << endl;
		}
	}
	else {
		cerr << "invalid array size ..." << endl;
	}
}

// A utility function to swap two elements  
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// partition portion of quicksort
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// function finds the range of a set of numbers
int mystery1(int a[], const int size){
	int max = 0;
	int min = MAX_RAND;
	int range;
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}
	range = max - min;
	return range;
}

// function finds if there are duplicate numbers in a set
int mystery2(int a[], const int size){
	quickSort(a, 0, size); // sort the array
	for (int j = 0; j < size; j++) // find consecutive doubles
	{
		if (a[j] == a[j + 1])
			return 1;
	}
	return 0;
}

// sort even and odd numbers
void mystery3(int a[], const int size){
	int temp;
	int place = 0; // marks the place between the sorted and unsorted portions of the array

	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 == 0) // swaps the even number from the usorted array to the end of the sorted array
		{
			temp = a[i];
			a[i] = a[place];
			a[place] = temp;
			place++;
		}
	}

	printArray(a, size);
}

// sorts an array from smallest to largest
void mystery4(int a[], const int size){
	int temp;
	int place = 0; // marks the place between the sorted and unsorted array

	for (int i = 1; i < size; i++)
	{
		if (a[i] <= a[place]) // swaps a number from the unsorted portion to the sorted portion
		{
			temp = a[i];
			a[i] = a[place];
			a[place] = temp;
			place++;
		}
	}
}

// sorts an array from smallest to largest and returns the smallest number
int mystery5(int a[], const int size){
	int temp;
	int place = 0; // marks the place between the sorted and unsorted array

	for (int i = 1; i < size; i++)
	{
		if (a[i] <= a[place]) // swaps a number from the unsorted portion to the sorted portion
		{
			temp = a[i];
			a[i] = a[place];
			a[place] = temp;
			place++;
		}
	}

	return a[0]; // a[0] is the smallest number in the array
}



int main(){

	int myArray[ARRAY_SIZE];
	fillRandomNumbers(myArray, ARRAY_SIZE);
	printArray(myArray, ARRAY_SIZE);

	return 0;
}
