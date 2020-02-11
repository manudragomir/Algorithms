#include <iostream>
#include "AVL.h"

using namespace std;

int main()
{
	AVL tree;
	tree.insert(9);
	tree.insert(5);
	tree.insert(10);
	tree.insert(0);
	tree.insert(6);
	tree.insert(11);
	tree.insert(-1);
	tree.insert(1);
	tree.insert(2);
	tree.preOrder();
	cout << "\n";

	tree.remove(10);
	tree.preOrder();
	return 0;
}