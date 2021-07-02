// CSE100Lab5.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
// Heapsortation for the maximation of the no understandtation
	

void Maxheapify(int arr[], int root, int n) {
	
	int left = (2 * root) + 1 ;
	int right = (2 * root) + 2 ;
	int longest = root;
	if (left < n && arr[left] > arr[longest]) {
		longest = left;
	}
	if (right < n && arr[right] > arr[longest]) {
		longest = right;
	}
	if (longest != root) {
		int temp = arr[root];
		arr[root] = arr[longest];
		arr[longest] = temp;
		Maxheapify(arr, longest , n);
	}
}

void BuildingHeap(int arr[], int n) {
	for (int i = (n/2) - 1; i >= 0; i--) {
		Maxheapify(arr, i, n);
	}
}
void heapsort(int arr[], int length){
	BuildingHeap(arr, length);
	for (int i = length-1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		Maxheapify(arr, 0, i);
	}
}
int main()
{
	int length, num;
	cin >> length;
	int* arr = new int [length]; 
	for (int i = 0; i < length; i++) {
		cin >> num;
		arr[i] = num;

	}
	heapsort(arr, length);
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ";";
	}
    return 0;
}

