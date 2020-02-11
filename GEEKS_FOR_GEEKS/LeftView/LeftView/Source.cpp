#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

void leftView(Node* root) {
	queue < pair < Node*, int > > Q;
	int height{ 0 };
	Q.push({ root,0 });
	while (!Q.empty()) {
		auto curr = Q.front().first;
		auto hei = Q.front().second;
		Q.pop();
		
		if (height == hei) {
			cout << curr->data << " ";
			height++;
		}

		if (curr->left != NULL) {
			Q.push({ curr->left, hei + 1 });
		}
		
		if (curr->right != NULL) {
			Q.push({ curr->right, hei + 1 });
		}
	}
}

int main() {

	return 0;
}