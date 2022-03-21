/* ####################################################################################################

Write a function that takes in a non-empty array of integers and returns the maximum sum that can be
obtained by summing up all of the integers in a non-empty subarray of the input array. A subarray must 
only contain adjacent numbers (numbers next to each other in the input array).

##################################################################################################### */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kadanesAlgorithm(vector<int> array) {

  	// Solution 1: O(n) time | O(1) space
	int runningSum = 0;
	int ans = INT_MIN;
	
	for (int i = 0; i < array.size(); i++){
		runningSum = max(runningSum + array[i], array[i]);
		ans = max(ans, runningSum);
	}
  	return ans;
}

int main() {

	vector<int> array{3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4};

	// expected output: 19 - sum of elements {1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1}
	int ans;
	ans = kadanesAlgorithm(array);
	cout << "The maximum sum is: " << ans <<  endl;
	return 0;
}