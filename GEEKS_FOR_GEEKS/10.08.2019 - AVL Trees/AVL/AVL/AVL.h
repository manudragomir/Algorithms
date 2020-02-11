#pragma once
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
	int height;
	int info;
	node* left;
	node* right;
	node(node* left, node* right, int info) : info{ info },
		right{ right }, left{ left }, height{ 0 }{};
};

class AVL
{
private:
	node* root;
	int noElements;
	int h(node* nod) {
		if (nod == nullptr) {
			return -1;
		}
		return nod->height;
	}
	int getBalance(node* nod) {
		if (nod == nullptr) {
			return 0;
		}
		return h(nod->left) - h(nod->right);
	}
	int calculateHeight(node* nod) {
		return max(h(nod->left), h(nod->right)) + 1;
	}

	node* avlInsert(node* act, int value);
	node* avlRemove(node* act, int value);
	node* avlSuccesor(node* act, int value);
	node* SRL(node* actNode);
	node* SRR(node* actNode);
	node* DRL(node* actNode);
	node* DRR(node* actNode);
	

	void preOrderTraversal(node* curr) {
		if (curr != nullptr)
		{
			cout << curr->info << " ";
			preOrderTraversal(curr->left);
			preOrderTraversal(curr->right);
		}
	}

public:
	AVL() : root{ nullptr }, noElements{ 0 } {};
	void insert(int value) {
		noElements++;
		root = avlInsert(root, value);
	}

	void remove(int value) {
		root = avlRemove(root, value);
	}

	bool search(int value) {
		auto actNode = root;
		while (actNode != nullptr && actNode->info != value) {
			if (value <= actNode->info) {
				actNode = actNode->left;
			}
			else {
				actNode = actNode->right;
			}
		}
	}
	bool isEmpty() {
		return (noElements == 0);
	}
	int size() {
		return noElements;
	}
	~AVL();

	void preOrder() {
		preOrderTraversal(root);
	}
};
