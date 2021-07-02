// CSE100Lab8.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream> 
#include <vector>

using namespace std;
// bucketsortation using no real happinessortation
void insertionsort(vector<float> &b, int length) {
	int i, j;
	float current;
	for (i = 1; i < length; i++) {
		//b[i] = current;
		current = b[i];
		j = i - 1;
		while (j >= 0 && b[j] > current) {
			b[j + 1] = b[j];
			j--;
		}
		// b[j] = current;
		b[j + 1] = current;

	}

}
void bucketsort(float arr[], int size) {
	vector<float> bucket[size];
	// Vector<float>bucket[];
	int column = 0;
	for (int i = 0; i < size; i++) {
		//    cout << "yo my man hows it going" << endl;
		int bucketindex = size* arr[i];
		// bucket[i].push_back(arr[i]);
		bucket[bucketindex].push_back(arr[i]);
	}
	for (int i = 0; i < size; i++) {
		// cout << "swag out on holiday lane"<< endl;
		insertionsort(bucket[i], bucket[i].size());
	}
	
	for (int i = 0; i < size; i++) {
		// cout << "heloo I am here" << endl;
		for (int j = 0; j < bucket[i].size(); j++) {
			// cout << " I am not a segmentation fault" << endl;
			arr[column] = bucket[i][j];
			column++;
		

		}
	}

}



int main()
{
	int length;
	float num;
	cin >> length;

	float* arr = new float[length];
	for (int i = 0; i < length; i++) {

		cin >> num;
		arr[i] = num;

	}
	bucketsort(arr, length);
	for (int i = 0; i < length; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}

