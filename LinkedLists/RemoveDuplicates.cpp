/* ###################################################################################################

You are given the head of a Singly Linked List whose nodes are in sorted order with respect to their 
values. Write a function that returns a modified version of the Linked List that doesn't contain any 
nodes with duplicate values. The Linked List should be modified in place (i.e., you shouldn't create a
brand new list), and the modified Linked List should still have its nodes sorted with respect to their 
values.

Each Linked List node has an integer value as well as a next node pointing to the next node in the list 
or to None/ Null if it's the tail of the list.

#################################################################################################### */

#include <iostream>

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  
  // Soution 1: O(n) time | O(1) space 
	LinkedList *currentNode = linkedList;
	
	while (currentNode != nullptr){
		while(currentNode->next != nullptr && currentNode->value == currentNode->next->value){
			currentNode->next = currentNode->next->next;
		}
		currentNode = currentNode->next;
	}
	
  return linkedList;
}

void printLinkedList(LinkedList *list){

	LinkedList *currentNode = list;

	while (currentNode != nullptr){

		cout << currentNode->value << " -> ";
		currentNode = currentNode->next;
	}
	cout << "NULL" << endl;
}

int main() {

	// linked list: 1 -> 1 -> 1 -> 2 -> 4 -> 4 -> 4 -> 5 -> 6 -> 6 -> NULL
	LinkedList one(1);
	LinkedList two(1);
	LinkedList three(2);
	LinkedList four(4);
	LinkedList five(4);
	LinkedList six(4);
	LinkedList seven(5);
	LinkedList eight(6);
	LinkedList nine(6);

	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	five.next = &six;
	six.next = &seven;
	seven.next = &eight;
	eight.next = &nine;

	// expected output: 1 -> 2 -> 4 -> 5 -> 6 -> NULL
	LinkedList *ans;
	ans = removeDuplicatesFromLinkedList(&one);
	printLinkedList(ans);
}