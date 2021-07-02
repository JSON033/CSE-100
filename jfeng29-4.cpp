// CSE100Lab4.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
// This is the maximation subarraynation
int max(int one, int two) {
	if (one >= two) {
		return one;
	}
	else {
		return two;
	}
}

int maximum(int one, int two, int three) {
	return max(max(one, two), three);
}
int MaxCrossingSum(int arr[], int low, int mid, int high) {
	int total;
	total = 0;
	int lowest = INT16_MIN;
	for (int i = mid; i >= low; i--) {
		total = arr[i] + total;
		if (total > lowest) {
			lowest = total;
		}
	}
	int tot = 0;
	int rightlowest = INT16_MIN;
	for (int i = mid + 1; i <= high; i++) {
		tot = tot + arr[i];
		if (tot > rightlowest) {
			rightlowest = tot;
		}
	}
	return lowest + rightlowest;
}
int MaxSubArray(int arr[], int low, int  high) {
	if (low == high) {
		return arr[low];
	}
	int mid = (low + high) / 2;
	return maximum(MaxSubArray(arr, low, mid),
		MaxSubArray(arr, mid + 1, high),
		MaxCrossingSum(arr, low, mid, high));


}
	


int main()
{
	int len, num, maxsum;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; i++) {
		cin >> num;
		arr[i] = num;
	}
	maxsum = MaxSubArray(arr, 0, len - 1);
	cout << maxsum ;
	return 0;
}

