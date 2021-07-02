// CSE100Lab1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
// This is about linear search
int main()
{
	int length,target,num;
	cin >> length;
	cin >> target;
	int* arr = new int[length];
	for (int i = 0; i < length; i++) {
		cin >> num;
		arr[i] = num;
	}
	for (int i = 0; i < length; i++) {
		if (arr[i] == target) {
			cout << i << endl ;
			return i;
		}
	}

    cout << -1 << endl;
	return -1;
}

