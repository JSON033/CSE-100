// CSE100Lab11.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};
bool search(Node* root,int value) {
	if (root == NULL) {
		return false;
	}
	else {
		if (root->data == value) {
			return true;
		}
		else if (value < root->data) {
			return search(root->left, value);
		}
		else {
			return search(root->right, value);
		}
	}

}
Node* insert(Node* root, int value) {
	if (root == NULL) {
		root = new Node();
	//	cout << "here" << endl;
		root->data = value;
	//	cout << "here1" << endl;
		root->left = NULL;
	//	cout << "here2" << endl;
		root->right = NULL;
	//	cout << "here3" << endl;
	}
	else {
	//	cout << "here" << endl;
		if (value < root->data) {
			root->left = insert(root->left, value);
		}
		else {
			root->right = insert(root->right, value);
		}
	}
	
	return root;
}
void remove(Node* root, int value) {
	int direction = 0;
	Node* current = root;
	Node* parent = current;
	while (current->data != value) {
		parent = current;
		bool remov= search(root, value);
		if (remov == false) {
			return;
		}
		if (value < current->data) {
			current = current->left;
			direction = -1;
		}
		else if (value > current->data) {
			current = current->right;
			direction = 1;
		}
		
	}
	if (current->left == NULL && current->right == NULL) {
		if (direction == 1) {
			parent->right = NULL;
		}
		else {
			parent->left = NULL;
		}
	}
	else if (current->left != NULL && current->right == NULL) {
		Node* lefttree = current->left;
		if (direction == -1) {
			parent->left = lefttree;
		}
		else {
			parent->right = lefttree;
		}
	}
	else if (current->left == NULL && current->right != NULL) {
		Node* rightree = current->right;
		if (direction == -1) {
			parent->left = rightree;
		}
		else {
			parent->right = rightree;
		}
	}
	else {
		Node* next = current->right;
		while (next->left != NULL) {
			next = next->left;
		}
		int val = next->data;
		remove(root, next->data);
		current->data = val;
	}

	
}
void prewalk(Node* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << endl;
	prewalk(root->left);
	prewalk(root->right);
}
void postwalk(Node* root) {
	if (root == NULL) {
		return;
	}
	postwalk(root->left);
	postwalk(root->right);
	cout << root->data << endl;
}
void inorder(Node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

int main()
{
	Node* tree = NULL;
	int value;
	string op;
	 cin >> op;
	while (op != "e") {
		if (op == "i") {
			cin >> value;
			tree = insert(tree, value);
		}
		if (op == "d") {
			cin >> value;
			remove(tree, value);
			
		}
		if (op == "pre") {
			prewalk(tree);
			cout << "++++++++++++++++++++" << endl;
		}
		if (op == "post") {
			postwalk(tree);
			cout << "++++++++++++++++++++" << endl;
		}
		if (op == "in") {
			inorder(tree);
			cout << "++++++++++++++++++++" << endl;
		}
		cin >> op;
	}
    return 0;
}

