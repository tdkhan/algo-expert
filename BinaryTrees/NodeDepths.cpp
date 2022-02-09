/* ####################################################################################################

The distance between a node in a Binary Tree and the tree's root is called the node's depth.

Write a function that takes in a Binary Tree and returns the sum of its nodes' depths.

Each BinaryTree node has an integer value, a left child node, and a right child node. Children nodes
can either be BinaryTree nodes themselves or None/ null.

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

struct elements{
	BinaryTree *node;
	int level;
};

int findDepth(BinaryTree *node, int depth){
	if(node == nullptr)
		return 0;
	return depth + findDepth(node->right, depth+1) + findDepth(node->left, depth+1);
}

int nodeDepths(BinaryTree *root) {
  	
  	// Solution 1: iterative - O(n) time | O(h) space
	int depth = 0;
	vector<elements> stack{{root, 0}};
	BinaryTree *current;
	int level;
	
	while (!stack.empty()) {
		current = stack.back().node;
		level = stack.back().level;
		stack.pop_back();
		depth = depth + level;
		if (current->right != nullptr)
			stack.push_back({current->right, level+1});
		if (current->left != nullptr)
			stack.push_back({current->left, level+1});
	}
	return depth;

	/*
	// Solution 2: recursive - O(n) time | O(h) space
	int depth = 0;
	depth = findDepth(root, depth);
  	return depth;
  	*/
}

int main() {

	/*      1
	       /  \
	      2    3
	     / \  / \
	   4   5 6   7
	  / \  
	 8  9  		*/

	BinaryTree one(1);
	BinaryTree two(2);
	BinaryTree three(3);
	BinaryTree four(4);
	BinaryTree five(5);
	BinaryTree six(6);
	BinaryTree seven(7);
	BinaryTree eight(8);
	BinaryTree nine(9);

	one.left = &two;
	one.right = &three;
	two.left = &four;
	two.right = &five;
	three.left = &six;
	three.right = &seven;
	four.left = &eight;
	four.right = &nine;

	// expected output: 16
	int ans;
	ans = nodeDepths(&one);
	cout << ans << endl;
	return 0;
}