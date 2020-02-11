#include "AVL.h"

//SIMPLE ROTATION TO LEFT
node* AVL::SRL(node* actNode) {
	auto rightNode = actNode->right;
	actNode->right = rightNode->left;
	rightNode->left = actNode;

	actNode->height = calculateHeight(actNode);
	rightNode->height = calculateHeight(rightNode);
	return rightNode;
}

//SIMPLE ROTATION TO RIGHT
node* AVL::SRR(node* actNode) {
	auto leftNode = actNode->left;
	actNode->left = leftNode->right;
	leftNode->right = actNode;

	actNode->height = calculateHeight(actNode);
	leftNode->height = calculateHeight(leftNode);
	return leftNode;
}

//DOUBLE ROTATION TO LEFT
node* AVL::DRL(node* actNode) {
	actNode->right = SRR(actNode->right);
	actNode = SRL(actNode);
	return actNode;
}

//DOUBLE ROTATION TO RIGHT
node* AVL::DRR(node* actNode) {
	actNode->left = SRL(actNode->left);
	actNode = SRR(actNode);
	return actNode;
}

//return the node with the smallest key bigger than value
node* AVL::avlSuccesor(node* act, int value)
{
	auto succ = act->right;
	while (succ->left != nullptr) {
		succ = succ->left;
	}
	return succ;
}

//insertion in an AVL TREE
//act - curent node in recursion
//value - key to insert
node* AVL::avlInsert(node* act, int value) {
	//base case of recursion
	if (act == nullptr) {
		node* nod = new node{ nullptr, nullptr, value };
		return nod;
	}

	//we insert in the left subtree
	if (value <= act->info) {
		act->left = avlInsert(act->left, value);
	}

	//we insert in the right subtree
	else {
		act->right = avlInsert(act->right, value);
	}

	act->height = calculateHeight(act);
	//get the factor of balance
	int balance = getBalance(act);

	if (balance == -2) {
		if (value > act->right->info) {
			act = SRL(act);
		}
		else {
			act = DRL(act);
		}
	}
	else if (balance == 2) {
		if (value < act->left->info) {
			act = SRR(act);
		}
		else {
			act = DRR(act);
		}
	}
	return act;
}

//removing from an avl tree recursively
//act - actual node in recursion
//value - the key to insert
node* AVL::avlRemove(node* act, int value) {
	if (act == nullptr) {
		return act;
	}

	//searching and removing in the left subtree
	if (value < act->info) {
		act->left = avlRemove(act->left, value);
	}

	//s and r in the right subtree
	else if (value > act->info) {
		act->right = avlRemove(act->right, value);
	}

	//if has both childs
	else if(act->left != nullptr && act->right != nullptr) {
		auto succ = avlSuccesor(act, value);
		act->info = succ->info;
		act->right = avlRemove(act->right, act->info);
	}

	else{
		node* nodeToReturn;
		//has only the left child
		if (act->left != nullptr) {
			nodeToReturn = act->left;
		}
		//has only the right child
		else if (act->right != nullptr) {
			nodeToReturn = act->right;
		}
		//has neither of them
		else {
			nodeToReturn = nullptr;
		}

		delete act;
		return nodeToReturn;
	}

	act->height = calculateHeight(act);
	int balance = getBalance(act);

	//we remove from the right subtree
	if (balance == 2) {
		if (getBalance(act->left) >= 0) {
			act = SRR(act);
		}
		else {
			act = DRR(act);
		}
	}
	else if (balance == -2) {
		if (getBalance(act->right) <= 0) {
			act = SRL(act);
		}
		else{
			act = DRL(act);
		}
	}

	return act;
}

AVL::~AVL() {
	queue < node* > Q;
	Q.push(root);
	while (!Q.empty()) {
		auto actNode = Q.front();
		Q.pop();

		if (actNode->right != nullptr) {
			Q.push(actNode->right);
		}

		if (actNode->left != nullptr) {
			Q.push(actNode->left);
		}

		delete actNode;
	}
}