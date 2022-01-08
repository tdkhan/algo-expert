/* ####################################################################################################

Write a function that takes in an array of integers and returns a boolean representing whether the array
is monotonic.

An array is said to be monotonic if its elements, from left to right, are entirely non-increasing or 
entirely non-decreasing.

Non-increasing elements aren't necessarily exclusively decreasing; they dimply don't increase. Similarly,
non-decreasing elements aren't necessarily excusively increasing; they simply don't decrease.

Note that empty arrays and arrays of one element are monotonic.

##################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMonotonic(vector<int> array) {

	
  	// Solution 1: brute force approach - O(nlog(n)) time | O(n) space
	vector<int> a, b;
	a = array;
	b = array;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	
	if (a == array || b == array)
		return true;
	else
  	return false;
  	
	/*
	// Solution 2: O(n) time | O() space
	bool isDec = true;
	bool isInc = true;

	if (array.empty() == true)
		return true;
	for (int i = 0; i < array.size()-1; i++){
		if (array[i] < array[i+1])
		 isDec = false;
		if (array[i] > array[i+1])
		 isInc = false;
		if (isDec == false && isInc == false)
			return false;
	}
  	return true;
  	

  	// Solution 3: O(n) time | O(1) space
  	if (array.size() <= 2)
    return true;

	int i = 0;
	while(array[i] == array[i+1] && i < (array.size() - 1))
		i++;
	if (array[i] > array[i+1] && (i+1) < array.size()){
		for (int j = i+1; j < (array.size()-1); j++){
			if (array[j] < array[j+1])
				return false;
		}
	}
	else if (array[i] < array[i+1] && (i+1) < array.size()){
		for (int j = i+1; j < (array.size()-1); j++){
			if (array[j] > array[j+1])
			return false;
		}			
	}
  	return true;
	*/
}

int main() {

	vector<int> array{-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
	bool ans;

	// expected output: 1
	ans = isMonotonic(array);
	cout << ans << endl;
}