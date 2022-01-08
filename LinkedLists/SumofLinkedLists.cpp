/* ###################################################################################################

You're given two Linked Lists of potentially unequal length. Each Linked List represents a non-negative
integer, where each node in the Linked List is a digit of that integer, and the first node in each 
Linked List always represents the least significant digit of the integer. write a function that returns
the head of a new Linked List that represents the sum of the integers represented by the two input 
Linked Lists.

Each LinkedList node has an integer value as well as a next node pointing to the node in the list or to
None/ null if it's the tail of the list. The value of each LinkedList node is always in the range of 
0-9. 

Note: your function must create and return a new Linked List, and you're not allowed to modify either
of the input Linked Lists.

#################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne, LinkedList *linkedListTwo) {

	// Solution 1: O(n) time | O(k) space 
	int value1, value2, carry, sum, count;
	count = 0;
	carry = 0;
	LinkedList *prev, *ans;
	LinkedList *currentOne = linkedListOne;
	LinkedList *currentTwo = linkedListTwo;
	
	while (currentOne != nullptr || currentTwo != nullptr || carry != 0) {
		count++;
		
		value1 = currentOne != nullptr ? currentOne -> value : 0;
		currentOne = currentOne != nullptr ? currentOne -> next : nullptr;
		value2 = currentTwo != nullptr ? currentTwo -> value : 0;
		currentTwo = currentTwo != nullptr ? currentTwo -> next : nullptr;
		
		sum = value1 + value2 + carry;
		carry = sum / 10;
		sum = sum % 10;
		
		if (count == 1) {
			ans = new LinkedList(sum);
			prev = ans;
			
		}
		else {
			prev -> next = new LinkedList(sum);
			prev = prev -> next;
		}
	}
  return ans;
}

void addMany(LinkedList *list, vector<int> values) {
  LinkedList *current = list;
  while (current->next != nullptr) {
    current = current->next;
  }
  for (int value : values) {
    current->next = new LinkedList(value);
    current = current->next;
  }
}

void printLinkedList(LinkedList *list) {
	LinkedList *current = list;
	while (current != nullptr) {
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << "null" << endl;
}

int main() {

	// linkedList One represents 1742 : 2 -> 4 -> 7 -> 1
	LinkedList One(2);
	vector<int> nodesOne {4, 7, 1};
	LinkedList *list1 = &One;
	addMany(list1, nodesOne);
	cout << "LinkedList 1:" << endl;
	printLinkedList(list1);

	// linkedList Two represents 549 : 9 -> 4 -> 5 
	LinkedList Two(9);
	vector<int> nodesTwo {4, 5};
	LinkedList *list2 = &Two;
	addMany(list2, nodesTwo);
	cout << endl << "LinkedList 2:" << endl;
	printLinkedList(list2);

	// Expected Output: 1742 + 549 = 2291 | 1 -> 9 -> 2 -> 2 
	LinkedList *ans;
	ans = sumOfLinkedLists(list1, list2);
	cout << endl << "LinkedList Sum: " << endl;
	printLinkedList(ans);

	return 0;
}