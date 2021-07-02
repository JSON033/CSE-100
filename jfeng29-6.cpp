// CSE100Lab6.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


// Randomization of the pivotation of the Quicksortation
using namespace std;
int partition(int arr[], int small, int big) {
	int x = arr[big];
	int i = small - 1;
	for (int j = small; j < big; j++) {
		if (arr[j] <= x) {
			i = i + 1;
		int	temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

	}
	int temporary = arr[i + 1];
	arr[i + 1] = arr[big];
	arr[big] = temporary;
	return i + 1;
}
int random(int small, int big) {
	srand(time(NULL));
	int randompivot = small + rand() % (big - small);
	return randompivot;
}
int randompartition(int arr[], int small, int big) {
	int pivot = random(small, big);
	int temp = arr[pivot];
	arr[pivot] = arr[small];
	arr[small] = temp;
	int partit = partition(arr, small, big);
	return partit;
}
void quickSort(int arr[], int small, int big) {
	if (small < big) {
		int q = randompartition(arr, small, big);
		quickSort(arr, small, q - 1);
		quickSort(arr, q + 1, big);
	}
}
int main()
{
	int length, num;
	cin >> length;
	int* arr = new int[length];
	for (int i = 0; i < length; i++) {
		cin >> num;
		arr[i] = num;
	}
	quickSort(arr, 0, length - 1);
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ";";
	}
    return 0;
}

