// CSE100Lab13.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

// Matrix chaining my fking back out bc I slaved away at this shit for days

void print(int* s, int a, int b, int n) {
	if (a == b) {
		cout << "A" << a - 1;
	}
	else {
		cout << "(";
		//cout << "is this mic working?" << endl;
		print(s, a, *((s + a * n) + b), n);
		cout << ".";
		//cout << "im a fking piece of fking shit" << endl;
		print(s, *((s + a * n) + b) + 1, b, n);
		cout << ")";
	}
}
void matrixchainorder(int arr[], int n) {

	int m[n][n];
	int s[n][n];
	for (int i = 1; i < n; i++) {
		m[i][i] = 0;
	}
	
	for (int j = 2; j < n; j++) {
	//	cout << "herro" << endl;
		for (int i = 1; i < n - j + 1; i++) {
		
			int k = i + j - 1;
			m[i][k] = INT16_MAX;
	//		cout << "k " << k << endl;
	//		cout << "i " << i << endl;
			for (int l = i; l <= k-1 ; l++) {
	//			cout << "wtf why isnt this printing" << endl;
				int q = m[i][l] + m[l + 1][k] + (arr[i - 1] * arr[l] * arr[k]);
				if (q < m[i][k]) {
					m[i][k] = q;
					s[i][k] = l;
		//			cout << "this is q " << q << endl;
				}
			}
		}

	}
//	cout << "this is the value " << m[1][n-1] << endl;
	cout << m[1][n - 1] << endl;
	print((int *)s, 1, n - 1, n);
	cout << endl;
	
}


int main()
{
	int length, value, weight;
	cin >> length;
	length = length + 1;
	int* arr = new int[length];
	
	for (int i = 0; i < length; i++) {
		cin >> value;
		arr[i] = value;
	}
	
	
	matrixchainorder(arr, length);
	
    return 0;
}

