/* ####################################################################################################

Write a function that takes in the heads of two Singly Linked Lists that are in sorted order, respectively.
The fucntion should merge the lists in place (i.e., it shouldn't create a breand new list) and return
the head of the merged list; the merged list should be in sorted order.

Each LinkedList node has an integer value as well as a next node pointing to the next node in the list
or to None/ null if it's the tail of the list.

You can assume that the input linked lists will always have at least one node; in other words, the heads
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

void addMany(LinkedList *ll, vector<int> values) {
	LinkedList *current = ll;
	while (current->next != nullptr) {
		current = current->next;
	}
	for (auto value : values) {
		current->next = new LinkedList(value);
		current = current->next;
	}
}

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {

  	// Solution 1: O(n+m) time | O(1) space
	LinkedList *main, *second, *temp;
	if (headOne->value <= headTwo->value){
		main = headOne;
		second = headTwo;
	}
	else{
		main = headTwo;
		second = headOne;
	}
	while (main->next != nullptr){
		if (main->next->value <= second->value)
			main = main->next;
		else{
			temp = main->next;
			main->next = second;
			second = temp;
			main = main->next;
		}
	}
	main->next = second;
  	return headOne->value <= headTwo->value ? headOne : headTwo;;
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

	// Linked List 1: 2 -> 6 -> 7 -> 8
	LinkedList *ll1 = new LinkedList(2);
	vector<int> values1{6, 7, 8};
	addMany(ll1, values1);
	cout << "Linked List 1: ";
	printLinkedList(ll1);

	// Linked List 2: 1 -> 3 -> 4 -> 5 -> 9 -> 10
	LinkedList *ll2 = new LinkedList(1);
	vector<int> values2{3, 4, 5, 9, 10};
	addMany(ll2, values2);
	cout << "Linked List 2: ";
	printLinkedList(ll2);

	// expected output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
	LinkedList *ans;
	ans = mergeLinkedLists(ll1, ll2);
	cout << "Merged Linked List: ";
	printLinkedList(ans);

	return 0;
}