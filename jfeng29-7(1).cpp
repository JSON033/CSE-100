// CSE100Lab7.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include <vector>
using namespace std;

// radixsortation using counting sortation while also having to have vectorization
vector<vector<int>> countingsort(vector<vector<int>> b, int count, int size) {
	vector < vector<int> >sort;
	sort.resize(size);
	//cout << b.size() << endl;
	//cout << count << endl;
	for (int i = 0; i < b.size(); i++) {
	 sort[i].resize(10);
	}
	int counts[10] = { 0,0,0,0,0,0,0,0,0,0 }; 
	
	for (int i = 0; i < b.size(); i++) {
		counts[b[i][count] ]++;
	
	}
	for (int i = 1; i < 10; i++) {
		
		counts[i] = counts[i - 1] + counts[i];
	//	cout << "hi my name is" << i << "  " << counts[i] << endl;

	}
//	cout << "hi" << endl;
	for (int i = size - 1; i >= 0; i--) {
	//	cout << "hello" << endl;
		//sort[i] = b[counts[b[i][count]]-1];
		sort[counts[b[i][count]] - 1] = b[i];
		counts[b[i][count]]--;
	//	cout << "hello" << endl;
	/*	for (int i = 0; i < size; i++) {
			for (int j = 0; j < 10; j++) {
				cout << sort[i][j] << ";";
			}
		}
		cout << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 10; j++) {
				cout << b[i][j] << ";";
			}
		}
		cout << endl;
		*/
	}

	return sort;
}

vector<vector<int>> radixsort(vector<vector<int>> v, int size) {
	int vindex = 9;
	vector<vector<int>> output = v;
/*	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 10; j++) {
			cout << output[i][j] << ";";
		}
		cout << endl;
	}
	*/
	while(vindex != -1){
	//	cout << vindex << endl;
	output = countingsort(output, vindex, size);

		vindex--;
	/*	for (int i = 0; i < size; i++) {
			for (int j = 0; j < 10; j++) {
				cout << output[i][j] << ";";
			}
			cout << endl;
		}
		*/
		}
//	cout << "its me NINOO" << endl;
	return output;
	}


int main()
{
	int length, num;
	cin >> length;
	int index = 9;
	vector<vector<int>> list;

	for (int i = 0; i < length; i++) {

	vector<int> arr;

		for (int j = 0; j < 10; j++) {
			cin >> num;
			arr.push_back(num);
		}
		list.push_back(arr);
	}
	list = radixsort(list, length);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 10; j++) {
			cout << list[i][j] << ";";
		}
		cout << endl;
	}
    return 0;
}

