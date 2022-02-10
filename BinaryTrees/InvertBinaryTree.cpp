/* ####################################################################################################

Write a function that takes in a Binary Tree and inverts it. In other words, the function should swap 
every left node in the tree for its corresponding right node.

Each BinaryTree node has an integer value, a left child node, and a right child node. Children nodes
can either be BinaryTree nodes themselves or None/ null.

##################################################################################################### */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class BinaryTree {
public:
	int value;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree(int value);
	void insert(vector<int> values, int i = 0);
};

BinaryTree::BinaryTree(int value) {
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}

void BinaryTree::insert(vector<int> values, int i) {
	if (i >= values.size()) {
		return;
	}
	deque<BinaryTree *> queue;
	queue.push_back(this);
	while (queue.size() > 0) {
		BinaryTree *current = queue.front();
		queue.pop_front();
		if (current->left == nullptr) {
			current->left = new BinaryTree(values[i]);
			break;
		}
		queue.push_back(current->left);
		if (current->right == nullptr) {
			current->right = new BinaryTree(values[i]);
			break;
		}
		queue.push_back(current->right);
	}
	this->insert(values, i + 1);
}

void invertBinaryTree(BinaryTree *tree) {
	
	// Solution 1: iterative O(n) time | O(h) space
	vector<BinaryTree *> stack;
	BinaryTree *current = tree;
	stack.push_back(current);
	BinaryTree *temp = nullptr;
	while (!stack.empty()){
		current = stack.back();
		stack.pop_back();
		temp = current->left;
		current->left = current->right;
		current->right = temp;
		if (current->left != nullptr)
			stack.push_back(current->left);
		if (current->right != nullptr)
			stack.push_back(current->right);
	}
	
	/*
	// Solution 2: recursive O(n) time | O(h) space
	if (tree == nullptr)
		return;
	BinaryTree* temp = tree->left;
	tree->left = tree->right;
	tree->right = temp;
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
	*/
}

void printBinaryTree(BinaryTree *root) {
	vector<BinaryTree *> stack;
	BinaryTree *current = root;
	stack.push_back(current);
	while (!stack.empty()){
		current = stack.back();
		stack.pop_back();
		cout << current->value << ", ";
		if (current->right != nullptr)
			stack.push_back(current->right);
		if (current->left != nullptr)
			stack.push_back(current->left);
	}
}

int main() {
	
	/*      1
	       /  \
	      2    3
	     / \  / \
	   4   5 6   7
	  / \  
	 8  9  		 */

	BinaryTree root(1);
	root.insert({2, 3, 4, 5, 6, 7, 8, 9});

	// input: [1, 2, 4, 8, 9, 5, 3, 6, 7]
	cout << "input: [";
	printBinaryTree(&root);
	cout << "\b" << "\b]" << endl;
	// expected output: [1, 3, 7, 6, 2, 5, 4, 9, 8]
	invertBinaryTree(&root);
	cout << "output: [";
	printBinaryTree(&root); 
	cout << "\b" << "\b]" << endl;
	return 0;
}