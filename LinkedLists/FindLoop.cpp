/* ####################################################################################################

Write a function that takes in the head of a Singly Linked List that contains a loop (in other words,
the list's tail node points to some node in the list instead of None/ null). The function should return 
node (the actual node--not just its value) from which the loop originates inconstant space.

Each LinkedList node has an integer value as well as a next node pointing to the next node in the list.

##################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList::LinkedList(int value) {
  this->value = value;
  this->next = nullptr;
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

LinkedList *getNthNode(LinkedList *ll, int n) {
  int counter = 1;
  LinkedList *current = ll;
  while (counter < n) {
    current = current->next;
    counter++;
  }
  return current;
}

LinkedList *findLoop(LinkedList *head) {
  	
  	// Solution 1: O(n) time | O(1) space
	LinkedList *first = head;
	LinkedList *second = head;

	do {
		first = first -> next;
		second = second -> next -> next;
	}
	while (first != second);
	
	second = head;
	while (first != second){
		first = first -> next;
		second = second -> next;
	}
  	return first;
}

int main() {

	// LinkedList: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6
	//                                 ^         |
	//                                 |         V
	//                                 9 <- 8 <- 7

	LinkedList list(0);
	vector<int> nodes{1, 2, 3, 4, 5, 6, 7, 8, 9};
	addMany(&list, nodes);
	LinkedList *tail = getNthNode(&list, 10);
	LinkedList *loop = getNthNode(&list, 5);
	tail -> next = loop;

	// Expected Output : 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> repeat
	LinkedList *ans;
	ans = findLoop(&list);

	LinkedList *current = ans->next;
	cout << ans -> value << " -> ";
	while (current != ans){
		cout << current -> value << " -> ";
		current = current -> next;
	}
	cout << "repeat" << endl;

	return 0;
}