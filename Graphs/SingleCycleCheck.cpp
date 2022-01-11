/* ####################################################################################################

You're given an array of intgers where eaach integer represents a jump of its value in the array. For 
instance, the integer 2 represents a jump of two indices forward in the array; the integer -3 represents
a jump of three indices backward in the array.

If a jump spills past the array's bounds, it wraps over to the other side. For instace, a jump of -1 at
index 0 brings us to the last index in the array. Similarly, a jump of 1 at the last index in the array 
brings us to the index 0.

Write a function that returns a boolean representing whether the jumps in the array form a single cycle.
A single cycle occurs if, starting at any index in the array and following the jumps, every element in 
the array is visited exactly once before landing back on the starting back index.

##################################################################################################### */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasSingleCycle(vector<int> array) {

	
  	// Solution 1: Brute Force - O(n) time | O(n) space
	unordered_set<int> indices;
	int idx = 0;
	int size = array.size();
	int next;
	
	while ((int)indices.size() < size){
		if (indices.find(idx) == indices.end())
			indices.insert(idx);
		else
			return false;

		next = (idx + array[idx])%size;
		idx = next >= 0 ? next : next + size;
	}
  	return idx == 0;
  	
	/*
  	// Solution 2: O(n) time | O(1) space
  	int visitedNodes = 0;
  	int idx = 0;

  	while (visitedNodes < array.size()){
  		if (visitedNodes > 0 && idx == 0)
  			return false;

  		visitedNodes++;
  		idx += array[idx];
  		int next = idx % (int)array.size();
  		idx = next >= 0 ? next : next + array.size();
  	}
  	return idx == 0;
  	*/
}

int main() {

	vector<int> test{10, 11, -6, -23, -2, 3, 88, 908, -26};
	bool ans = hasSingleCycle(test);

	// expected output: 1
	cout << ans << endl;

	return 0;
}