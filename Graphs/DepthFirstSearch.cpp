/* ####################################################################################################

You're given a Node class that has a name and an array of optional children nodes. When put together,
nodes form an acyclic tree-like structure.

Implement the depthFirstSearch method on the Node class, which takes in an empty array, traverse the 
tree using the Depth-first Search approach (specifically navigating the tree from left to right), stores
all of the nodes' names in the Input array, and returns it.

##################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	string name;
  	vector<Node *> children;

  	Node(string str) { name = str; }

  	vector<string> depthFirstSearch(vector<string> *array) {
    	
  		
    	// Solution 1: iterative - O(e+n) time | O(n) space
		vector<Node *> stack;
		Node *current = this;
		stack.push_back(current);
		while (stack.empty() == false) {
			array -> push_back(stack[stack.size()-1]->name);
			stack.pop_back();
			int size = current->children.size();
			for (int i = size-1; i>=0; i--) {
				stack.push_back(current->children[i]);
			}
			current = stack[stack.size()-1];
		}
		return *array;
		
  		/*
		// Solution 2: recursive O(e+n) time | O(n) space
		array->push_back(this->name);
		for (int i = 0; i < this->children.size(); i++)
			children[i]->depthFirstSearch(array);
		return *array;
		*/
	}

  	Node *addChild(string name) {
	    Node *child = new Node(name);
	    children.push_back(child);
	    return this;
	}
};

int main() {

	/*      A
	      / | \
             B  C  D
            / \   / \  
	   E   F G   H
	      / \ \
	     I   J k
	*/

	Node graph("A");
	graph.addChild("B")->addChild("C")->addChild("D");
	graph.children[0]->addChild("E")->addChild("F");
	graph.children[2]->addChild("G")->addChild("H");
	graph.children[0]->children[1]->addChild("I")->addChild("J");
	graph.children[2]->children[0]->addChild("K");

	// expected result: {"A", "B", "E", "F", "I", "J", "C", "D", "G", "K", "H"}
	vector<string> ans{};
	ans = graph.depthFirstSearch(&ans);
	cout << "{";
	for (int i = 0; i < ans.size(); i++){
		cout << "\""<< ans[i] << "\", ";
	}
	cout << "\b" << "\b}" << endl;

	return 0;
}
