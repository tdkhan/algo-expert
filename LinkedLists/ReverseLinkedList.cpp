/* ####################################################################################################

Write a function that takes in the head of a Singly Linked List, reverses the list in place (i.e.,
doesn't create a brand new list), and returns its new head.

Each LinkedList node has an integer vlaue as well as a next node pointing to the next node in the list
or to None/ null if it's the tail of the list.

You can assume that the input Linked List will always have at least one node; in other words, the head 
will never be None/ null.

##################################################################################################### */

#include <iostream> 
#include <vector>

using namespace std;

class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value) {
		this->value = value;
		this->next = nullptr;
	}
};

LinkedList *newLinkedList(vector<int> values) {
	LinkedList *ll = new LinkedList(values[0]);
	LinkedList *current = ll;
	for (int i = 1; i < values.size(); i++) {
		current->next = new LinkedList(values[i]);
		current = current->next;
	}
	return ll;
}

LinkedList *reverseLinkedList(LinkedList *head) {
	
	// Solution 1: O(n) time | O(1) space
	LinkedList *temp, *current, *prev;
	current = head;
	prev = nullptr;
	while (current != nullptr){
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	return prev;
}

void printLinkedList(LinkedList *head) {
	LinkedList *current = head;
	while (current != nullptr){
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << "\b\b\b   " << endl;
}

int main() {

	// Linked List: 0 -> 1 -> 2 -> 3 -> 4 -> 5
	vector<int> values{0, 1, 2, 3, 4, 5};
	LinkedList *ll;
	ll = newLinkedList(values);
	
	// expected output: 5 -> 4 -> 3 -> 2 -> 1 -> 0  
	LinkedList *reversed;
	reversed = reverseLinkedList(ll);
	printLinkedList(reversed);
	return 0;
}