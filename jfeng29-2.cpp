// CSE100Lab2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
// This is about Binary search
int binarysearch(int arr[], int target, int low, int high) {

	
	int mi = (low + (high)) / 2;

if (low <= high) {
		
		
		
	if (arr[mi] == target) {
		cout << mi;
		return mi;
	}
	if (arr[mi] < target) {
		binarysearch(arr, target, mi + 1, high);
	}
	if (arr[mi] > target) {
		binarysearch(arr, target, low, mi - 1);

	}

	}	
else{cout << -1;
		return -1;
}
		
}
int main()
{
	int length, target, num, low , high;
	cin >> length;
	cin >> target;
	int* arr = new int[length];
	for (int i = 0; i < length; i++) {
		cin >> num;
		arr[i] = num;
	}
	binarysearch(arr, target, 0, length - 1);
    return 0;
}

