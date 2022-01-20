/* ####################################################################################################

You're given a Node class that has a name and an array of optional children nodes. When put together, 
nodes form an acyclic tree-like structure.

Implement the breadthFirstSearch method on the Node class, which takes in an empty array, traverses the
tree using the Breadth-first Search approach (specifically navigating the tree from left to right),
stores all of the ndoes' names in the input array, and returns it.

##################################################################################################### */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
  	string name;
  	vector<Node *> children;

  	Node(string str) { name = str; }

  	vector<string> breadthFirstSearch(vector<string> *array) {
    	
		// Solution 1: O(n+e) time | O(n) space
		Node *current = this;
		queue<Node *> visited;
		visited.push(current);
		while (visited.empty() != true){
			array->push_back(visited.front()->name);
			visited.pop();
			for (int i = 0; i < current -> children.size(); i++) {
				visited.push(current -> children[i]);
			}
			current = visited.front();
		}
		return *array;
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

	// expected result: {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"}
	vector<string> ans{};
	ans = graph.breadthFirstSearch(&ans);
	cout << "{";
	for (int i = 0; i < ans.size(); i++){
		cout << "\""<< ans[i] << "\", ";
	}
	cout << "\b" << "\b}" << endl;

	return 0;
}