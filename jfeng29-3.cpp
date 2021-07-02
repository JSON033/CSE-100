// CSE100Lab3.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;


// mertation sorgation
	void merge(int arr[], int left, int mid, int right) {

		int i, j, k;
		int n1 = mid - left + 1;
		int n2 = right - mid;
	
		int* lefty = new int[n1];
		int* righty = new int[n2];
		
	
		for (i = 0; i < n1; i++)
			lefty[i] = arr[left + i];
		for (j = 0; j < n2; j++)
			righty[j] = arr[mid + 1 + j];

		i = 0, j = 0, k= left;
		while (i < n1 && j < n2) {
	
			if (lefty[i] <= righty[j]) {
				arr[k] = lefty[i];
				i++;
			}
			else {
				arr[k] = righty[j];
				j++;
			}
			k++;
		}
		
	

	
	
		while (i < n1) {
			arr[k] = lefty[i];
			i++;
			k++;

		}
		
		while (j < n2) {
			arr[k] = righty[j];
			j++; 
			k++;
		}
		
}
void mergesort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);

		merge(arr, left, mid, right);
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
	mergesort(arr, 0, length-1);
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ";";
	}
    return 0;
}



/*int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;

/* create temp arrays 
int* L = new int[n1];
int* R = new int[n2];

/* Copy data to temp arrays L[] and R[] 
for (i = 0; i < n1; i++)
	L[i] = arr[l + i];
for (j = 0; j < n2; j++)
	R[j] = arr[m + 1 + j];

/* Merge the temp arrays back into arr[l..r]
i = 0; // Initial index of first subarray 
j = 0; // Initial index of second subarray 
k = l; // Initial index of merged subarray 
while (i < n1 && j < n2)
{
	if (L[i] <= R[j])
	{
		arr[k] = L[i];
		i++;
	}
	else
	{
		arr[k] = R[j];
		j++;
	}
	k++;
}

/* Copy the remaining elements of L[], if there
are any 
while (i < n1)
{
	arr[k] = L[i];
	i++;
	k++;
}

/* Copy the remaining elements of R[], if there
are any 
while (j < n2)
{
	arr[k] = R[j];
	j++;
	k++;
}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted 
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
*/
