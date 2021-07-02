// CSE100Lab9.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;
struct node {
	int data;
	node* next;


	node(int data) {
		this->data = data;
		next = NULL;
	}
};
struct hashtable {
	node** array;
	int size;

	hashtable(int size) {

		array = (node**)malloc(sizeof(node*) * size);

		for (int i = 0; i < size; i++) {
			array[i] = NULL;
		}
		this->size = size;
	}
	int hash(int value) {
		return value%size;
	}

	void insert(int value) {
		
		node*key = new node(value);
		node*temp;
		int h = hash(value);
		if (array[h] == NULL) {
			array[h] = key;
			temp = key;
		}
		else {
			node* Next;
			Next = array[h];
			array[h] = key;
			array[h]->next = Next;
		}
	}

	void search(int value) {
	//	cout << "searching " << endl;
		int here = hash(value);
		int j = 0;

		node*current = array[here];
		//cout << current << endl;
		if (current == NULL) {
			cout << value << " : NOT FOUND" << endl;
			return;
		}
		while (current->data != NULL) {
			//cout << "im here" << endl;
			if (current->data == value) {
				cout << value <<  " : FOUND AT " << here << "," << j << endl;
				break;
			
			}
			j++;
			current = current->next;
			if (current == NULL) {
				cout << value << " : NOT FOUND" << endl;
				break;
			}
		}
	}

	void print() {
	//	cout << "hello" << endl;
		for (int i = 0; i < size; i++) {
			cout << i << " : ";
			node* curr = array[i];
			if (curr != NULL) {
				while (curr != NULL) {
					cout << curr->data ;
					if (curr->next != NULL) {
						cout << "->";
					}
					curr = curr->next;
				}
				
			}
			cout << endl;
		}
	}

	void delet(int value) {
	//	cout << "deleting my soul" << endl;
		node*prev;
		node*current;
		node*oldnode;
		int h = hash(value);
		current = array[h];
		prev = array[h];
		oldnode = NULL;
		int counter = 0;
		int fail = 0;
		while (current != NULL) {
			if (current->data == value) {
				cout << value << " : DELETED" << endl;
				fail = value;
				if (current->next == NULL) {
			//		cout << "I am near Null" << endl;
					if (counter == 0) {
					//	cout << "I am near Null" << endl;
						array[h]  = NULL;
						
						

						break;
					}
					current = NULL;
					break;
				}
				if (counter == 0) {
					while (current->next->next != NULL) {
						current->data = current->next->data;

						current = current->next;
						}
					current->data = current->next->data;
					current->next = NULL;

					

					break;
				}
				current = current->next;
				break;
			}
			else {
			
					prev = current;
				
				current = current->next;
			}
			counter++;

		}
	//	cout << "my stop is here" << endl;
		if (counter > 0) {
			prev->next = current;
		}
		else delete(oldnode);
		if (fail == 0) {
			cout << value << " : DELETE FAILED" << endl;
		}
	}

};


int main()
{
	int length, num;
	cin >> length;
	hashtable c = hashtable(length);
	string input;
//	cout << " operation" << endl;
	
	while (input != "e") {
		cin >> input;
		if (input == "i") {
	//		cout << "hi i" << endl;
			cin >> num;
			c.insert(num);
		}
		if (input == "o") {

			c.print();

			cout << "++++++++++++++++++++" << endl;
		}
		if (input == "d") {
			cin >> num;
			c.delet(num);
			cout << "++++++++++++++++++++" << endl;
		}
		if (input == "s") {
			cin >> num;
			c.search(num);
			cout << "++++++++++++++++++++" << endl;
		}
	}
    return 0;
}

