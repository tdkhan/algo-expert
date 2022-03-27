/* ####################################################################################################

Write a function that takes in an array of integers and returns a sorted version of that array. Use the
Bubble Sort algorithm to sort the array.

##################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> array) {
  	
  	// Solution 1: O(n^2) time | O(1) space
	bool sort = true;
	int counter = 0;
	while (sort == true){
		sort = false;
		for (int i = 0; i < array.size()-1-counter; i++){
			if (array[i] > array[i+1]) {
				swap(array[i], array[i+1]);
				sort = true;
			}
		}
		counter++;
	}
  	return array;
}

int main() {

	vector<int> array{8, 5, 2, 9, 5, 6, 3};

	// expected output: [2, 3, 5, 5, 6, 8, 9]
	vector<int> ans;
	ans = bubbleSort(array);
	cout << "[";
	for (auto x : ans)
		cout << x << ", ";
	cout << "\b\b]" << endl;
	return 0;
}