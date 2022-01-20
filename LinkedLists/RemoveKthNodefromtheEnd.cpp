/* ###################################################################################################

Write a function that takes in the head of a Singly Linked List and an integer k and removes the kth 
node from the end of the list.

The removal should be done in place, meaning that the original data structure should be mutated (no new
structure should be created).

Furthermore, the imput head of the linked list should remain the head of the linked list after the 
removal is done, even if the head is the node that's supposed to be removed. In other words, if the head
is the node that's supposed to be removed, your function should simply mutate its value and next pointer.

Note that your function doesn't need to return anything.

You can assume that the input Linked List will always have at least two nodes and, more specifically, at 
least k nodes.

Each LinkedList node has an integer calue as well as a next node pointing to the next node in the list or 
to None/ null if it's the tail of the list.

#################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value);
	void addMany(vector<int> values);
	void printLinkedList();
};

LinkedList::LinkedList(int value) {
	this->value = value;
	this->next = nullptr;
}

void LinkedList::addMany(vector<int> values) {
	LinkedList *current = this;
	while (current->next != nullptr) {
		current = current->next;
	}
	for (int value : values) {
		current->next = new LinkedList(value);
		current = current->next;
	}
}

void LinkedList::printLinkedList() {
	LinkedList *current = this;
	while (current != nullptr) {
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << "null" << endl;
}

void removeKthNodeFromEnd(LinkedList *head, int k) {
  	

  	// Solution 1: Brute force approach - O(n+b) time | O(1) space
	LinkedList *current = head;
	int count = 0;
	
	while (current != nullptr) 
	{
		count++;
		current = current -> next;
	}
	
	int b = count - k;
	count = 0;
	current = head;
	LinkedList *prev = nullptr;
	
	if (b+1 == 1)
	{
		current -> value = current -> next -> value;
		current -> next = current -> next -> next;
		return;
	}
	
	while (current != nullptr)
	{
		count++;
		if(count == b)
		{
			current -> next = current -> next -> next;
			return;
		}
		current = current -> next;
	}
	
	/*
	// Solution 2: O(n) time | O(1) space
	LinkedList *first, *second, *prev;
	first = head;
	second = head;
	int count = 0;

	while (first != nullptr) 
	{
		count++;
		if (count <= k)
			first = first -> next;
		else
		{
			first = first -> next;
			prev = second;
			second = second -> next;
		}
	}
	
	if (second == head)
	{
		second -> value = second -> next -> value;
		second -> next = second -> next -> next;
	}
	else
		prev -> next = second -> next;
	*/
}

int main() {

	// Linked List: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
	LinkedList head(0);
	vector<int> nodes{1, 2, 3, 4, 5, 6, 7, 8, 9};
	head.addMany(nodes);

	int k = 4;

	// Expected Output: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 7 -> 8 -> 9
	removeKthNodeFromEnd(&head, k);
	head.printLinkedList();

	return 0;
}