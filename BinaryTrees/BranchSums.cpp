/* ####################################################################################################

Write a function that takes in a Binary Tree and returns a list of its branch sums ordered from leftmost
branch sum to rightmost branch sum.

A branch sum is the sum of all values in a Binary Tree branch. A Binary Tree branch is a path of nodes in
a tree that starts at the node and ends at any leaf node.

Each BinaryTree node has an integer value, a left child node, and a right child node. Children nodes can 
either be BinaryTree nodes themselves of None/ null.

##################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

class BinaryTree {
public:
	int value;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree(int value) {
	this->value = value;
	left = nullptr;
	right = nullptr;
	}
};

// void calculateBranchSums(BinaryTree *node, int runningSum, vector<int>& sums);

vector<int> branchSums(BinaryTree *root) {
	
	
	// Solution 1: iterative - O(n) time | O(n) space
	vector<int> sums;
	BinaryTree *current;
	vector<BinaryTree *> stack;
	vector<int>sumStack;
	sumStack.push_back(0);
	stack.push_back(root);
	int sum = 0;
	while(!stack.empty()) {
		current = stack[stack.size()-1];
		stack.pop_back();
		sum += current->value;
		if (current -> left == nullptr && current -> right == nullptr){
			sums.push_back(sum);
			sum = sumStack[sumStack.size()-1];
			sumStack.pop_back();
		}
		else {
			if (current -> right != nullptr) {
				stack.push_back(current->right);
				sumStack.push_back(sum);
			}
			if (current -> left != nullptr)
				stack.push_back(current -> left);
		}
	}
	return sums;
	
	/*
	// Solution 2: recursively - O(n) time | O(n) space
	vector<int> sums;
	calculateBranchSums(root, 0, sums);
	return sums;
	*/
}

/*
void calculateBranchSums(BinaryTree *node, int runningSum, vector<int>& sums) {
	if (node == nullptr)
		return;

	runningSum += node -> value;
	if (node -> left == nullptr & node -> right == nullptr) {
		sums.push_back(runningSum);
		return;
	}

	calculateBranchSums(node -> left, runningSum, sums);
	calculateBranchSums(node -> right, runningSum, sums);
}
*/

int main() {

	/*      1
	       /  \
	      2    3
	     / \  / \
	   4   5 6   7
	  / \  /
	 8  9 10		*/

	BinaryTree one(1);
	BinaryTree two(2);
	BinaryTree three(3);
	BinaryTree four(4);
	BinaryTree five(5);
	BinaryTree six(6);
	BinaryTree seven(7);
	BinaryTree eight(8);
	BinaryTree nine(9);
	BinaryTree ten(10);

	one.left = &two;
	one.right = &three;
	two.left = &four;
	two.right = &five;
	three.left = &six;
	three.right = &seven;
	four.left = &eight;
	four.right = &nine;
	five.left = &ten;

	// expected output: [15, 16, 18, 10, 11]
	vector<int> sums;
	sums = branchSums(&one);
	cout<< "[";
	for (int i = 0; i < sums.size(); i++)
		cout << sums[i] << ", ";
	cout << "\b" << "\b]" << endl;

	return 0;
}