/* ####################################################################################################

Given an array of integers between 1 and n, inclusive, where n is the length of the array, write a function
that returns the first integer that appears more than once (when the array is read from left to right).

In other words, out of all the integers that might occur more than once in the input array, your function
should return the one whose first duplicate value has the minimum index.

If no integer appears more than once, your function should return -1.

Note that you're allowed to mutate the input array.

##################################################################################################### */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int firstDuplicateValue(vector<int> array) {
	
	// Solution 1: o(n^2) time | O(1) space
	if (array.empty() == 1)
		return -1;
	int index = INT_MAX;
	for (int i = 0; i < array.size()-1; i++){
		for (int j = i+1; j < array.size(); j++){
			if (array[i] == array[j])
				index = min(j, index);
		}
	}
	if (index != INT_MAX)
		return array[index];
	else
		return -1;

	/*
	// Solution 2: O(n) time | O(n) space 
	unordered_set<int> traversed;
	for (int i = 0; i < array.size(); i++){
		if (traversed.find(array[i]) == traversed.end())
			traversed.insert(array[i]);
	    else
	      return array[i];
	}
	return -1;
	

	// Solution 3: O(n) time | O(1) space
	int index;
	for(int i = 0; i < array.size(); i++){
		index = abs(array[i]) - 1;
		if (array[index] < 0)
			return abs(array[i]);
		else 
			array[index] *= -1;
 	}
	return -1; 
	*/
}


int main() {

	vector<int> array{2, 1, 5, 2, 3, 3, 4};
	int ans;

	// expected output: 2
	ans = firstDuplicateValue(array);
	cout << ans << endl;
	return 0;
}