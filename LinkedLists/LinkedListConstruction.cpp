/* ####################################################################################################

Write a DoublyLinkedList calss that has a head and a tail, both of which point to either a linked list
Node or None/ null. The class should support:
	
	1. Setting the head and tail of the linked list.
	2. Inserting nodes before and after other nodes as well as at given positions (the position of the 
	head node is 1).
	3. Removing given nodes and removing nodes with given values.
	4. Searching for nodes with given values.

Note that the setHead, setTail, insertBefore, insertAfter, insertAtPosition, and remove methods all take
in actual Nodes as input parameters -- not integers (except for insertAtPosition, which also takes in 
an integer representing the positon); this means that you don't need to create any new Nodes in these 
methods. The input nodes can be either stand-alone nodes or nodes that are already in the linked list. 
If they're nodes that are already in the linked list, the methods will effectively be moving the nodes 
within the linked list. You won't be told if the input nodes are already in the linked list, so your code
will have to defensively handle this scenario.

If you're doing this problem in an untyped language like Python or JavaScript, you may want to look at
the various function signatures in a typed language like Java or TypeScript to get a better idea of what 
each input parameter is.

Each Node has an integer value as well as a prev node and a next node, both of which can point to either 
another node or None/ null. 

##################################################################################################### */

#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node *prev;
	Node *next;

	Node(int value);
};

Node::Node(int value) {
	this->value = value;
	prev = nullptr;
	next = nullptr;
};

class DoublyLinkedList {
public:
	Node *head;
	Node *tail;

	DoublyLinkedList() {
	  head = nullptr;
	  tail = nullptr;
	}

	// Solution: each method has its own time and space complexity as indicated in the comments

	void setHead(Node *node) {
	  
	  // O(1) time | O(1) space
	  if (head == nullptr)
	  {
	    head = node;
	    tail = node;
	  }
	  
	  if (node != head)
	    insertBefore(head, node);
	}

	void setTail(Node *node) {

	  // O(1) time | O(1) space
	  if (tail == nullptr)
	  {
	  	head = node;
	  	tail = node;
	  }
	  
	  if (tail != node)
			insertAfter(tail, node);
	}

	void insertBefore(Node *node, Node *nodeToInsert) {
	  
	  // O(1) time | O(1) space
	  if (nodeToInsert == head && nodeToInsert == tail)
	  	return;
		remove(nodeToInsert);

	  Node *temp;
	  temp = node -> prev;

	  nodeToInsert -> next = node;
	  nodeToInsert -> prev = node -> prev;

	  node -> prev = nodeToInsert;
	  
	  if(node == head)
	  	head = nodeToInsert; 
	  else
			temp -> next = nodeToInsert;
	}

	void insertAfter(Node *node, Node *nodeToInsert) {
	  
	  // O(1) time | O(1) space
	  if (nodeToInsert == head && nodeToInsert == tail)
	  	return;
		
	  remove(nodeToInsert);
	  Node *temp;
	  temp = node -> next;

	  nodeToInsert -> next = node -> next;
	  nodeToInsert -> prev = node;

	  node -> next = nodeToInsert;

	  if(node == tail)
	  	tail = nodeToInsert; 
	  else
	  	temp -> prev = nodeToInsert;
	}

	void insertAtPosition(int position, Node *nodeToInsert) {
	 
	 	// O(p) time | O(1) space
		if (position == 1)
		{
			setHead(nodeToInsert);
			return;
		}

		int count = 2;
		Node *current = head->next;

		while (current != nullptr)
		{
			if (count == position)
			{
				insertBefore(current, nodeToInsert);
				break;
			}
			count++;
			current = current -> next;
		}

		if (current == nullptr)
			setTail(nodeToInsert);
	}

	void removeNodesWithValue(int value) {
	  
	  // O(n) time | O(1) space
		Node *current = head;
		Node *temp;

		while(current != nullptr)
		{
			if (current -> value == value)
			{
				temp = current -> next;
				remove(current);
				current = temp;
			}
			else
				current = current -> next;
		}
	}

	void remove(Node *node) {
	  
	  // O(1) time | O(1) space
		if (node == tail)
			tail = node -> prev;

		if (node == head)
			head = node -> next;

		if (node->next != nullptr)
			node -> next -> prev = node -> prev;

		if (node->prev != nullptr)
			node -> prev -> next = node -> next;

		node -> prev = nullptr;
		node -> next = nullptr;
	}

	bool containsNodeWithValue(int value) {
	  
	  // O(n) time | O(1) space
		Node *current = head;

		while (current != nullptr)
		{
			if (current -> value == value)
				return true;
			
			current = current -> next;
		}
		return false;
		}
};

void printLinkedList(Node *node){
	Node *currentNode = node;
	cout << "NUll <-> ";
	while (currentNode != nullptr){
		cout << currentNode->value << " <-> ";
		currentNode = currentNode->next;
	}
	cout << "NULL" << endl << endl;
}

int main() {

	// Stand alone nodes
	Node saone(3);
	Node satwo(3);
	Node sathree(6);

	// Linked List 1 <-> 2 <-> 3 <-> 4 <-> 5
	Node one(1);
	Node two(2);
	Node three(3);
	Node four(4);
	Node five(5);

	one.next = &two;
	two.prev = &one;
	two.next = &three;
	three.prev = &two;
	three.next = &four;
	four.prev = &three;
	four.next = &five;
	five.prev = &four;

	DoublyLinkedList alpha;
	alpha.head = &one;
	alpha.tail = &five;

	cout << "The original Linked List: " << endl;
	printLinkedList(alpha.head);

	// expected output: 4 <-> 1 <-> 2 <-> 3 <-> 5
	alpha.setHead(&four);
	cout << "Set Head method call: " << endl;
	printLinkedList(alpha.head);

	// expected output: 4 <-> 1 <-> 2 <-> 3 <-> 5 <-> 6
	alpha.setTail(&sathree);
	cout << "Set Tail method call: " << endl;
	printLinkedList(alpha.head);

	// expected output: 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6
	alpha.insertBefore(&sathree, &three);
	cout << "insert Before method call: " << endl;
	printLinkedList(alpha.head);	

	// expected output: 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 <-> 3
	alpha.insertAfter(&sathree, &saone);
	cout << "insert After method call: " << endl;
	printLinkedList(alpha.head);	

	// expected output: 3 <-> 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 <-> 3
	alpha.insertAtPosition(1, &satwo);
	cout << "insert At Position method call: " << endl;
	printLinkedList(alpha.head);

	// expected output: 4 <-> 1 <-> 2 <-> 5 <-> 6 
	alpha.removeNodesWithValue(3);
	cout << "remove Nodes With Value method call: " << endl;
	printLinkedList(alpha.head);

	// expected output: 4 <-> 1 <-> 5 <-> 6 
	alpha.remove(&two);
	cout << "remove method call: " << endl;
	printLinkedList(alpha.head);

	// expected output: 1
	bool ans;
	ans = alpha.containsNodeWithValue(5);
	cout << "contains Node With Value method call: " << endl;
	cout << ans << endl;

	return 0;
}
