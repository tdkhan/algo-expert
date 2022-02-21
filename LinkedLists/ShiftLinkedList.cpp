/* ####################################################################################################

Write a function that takes in the head of a Singly Linked List and an integer k, shifts the list in
place (i.e., doesn't create a brand new list) by k positions, and returns its new head.

Shifting a Linked List means moving its nodes forward or backward and wrapping them around the list 
where appropriate. For example, shifting a Linked List forward by one postion would make its tail become
the new head of the linked list.

Whether nodes are moved forward or backward is determined by whether k is positive or negative.

Each LinkedList node had an integer value as well as a next node pointing to the next node in the list
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
		next = nullptr;
	}
};

void printLinkedList(LinkedList *list){
	LinkedList *currentNode = list;
	while (currentNode != nullptr){
		cout << currentNode->value << " -> ";
		currentNode = currentNode->next;
	}
	cout << "null" << endl;
}

void addMany(LinkedList *ll, vector<int> values) {
	LinkedList *current = ll;
	while (current->next != nullptr) {
		current = current->next;
	}
	for (int value : values) {
		current->next = new LinkedList(value);
		current = current->next;
	}
}

LinkedList *shiftLinkedList(LinkedList *head, int k) {
  	
  	// Solution 1: O(n) time | O(1) space
	LinkedList *one, *two;
	one = head;
	two = head;
	int size = 1;
	while (one->next != nullptr){
		one = one->next;
		size++;
	}
	k = k%size;
	if (k > 0)
		k = size - k;
	if (k != 0){
		for (int i = 1; i < abs(k); i++)
			two = two->next;
		one->next = head;
		head = two->next;
		two->next = nullptr;
	}
  return head;
}

int main() {

	// Linked List: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> null
	LinkedList ll(0);
	vector<int> values{1, 2, 3, 4, 5};
	addMany(&ll, values);
	int k = 2;

	// expected output: 4 -> 5 -> 0 -> 1 -> 2 -> 3 -> null
	LinkedList *ans;
	ans = shiftLinkedList(&ll, 2);
	printLinkedList(ans);
	return 0;
}