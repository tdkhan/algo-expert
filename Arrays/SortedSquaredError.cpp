/* ###################################################################################################

Write a function that takes in a non-empty array of integers that are sorted in ascending order and 
returns a new array of the same length with the squares of the original integers also sorted in ascending
order.

#################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {

	
	// SOLUTION 1: brute force approach - O(nlog(n)) time | O(n) space 
	vector<int> SquaredArray;
	
	for (int i = 0; i < array.size(); i++)
	{
		SquaredArray.push_back(array[i]*array[i]);
	}

  	sort(SquaredArray.begin(), SquaredArray.end());
	return SquaredArray;
	

	/*
	// Solution 2: O(n) time | O(n) space
	int sIdx = 0;
	int eIdx = array.size()-1;
	int count = array.size()-1;
	vector<int> sortedSquaredArray(array.size());
	
	while (count >= 0)
	{
		if (abs(array[sIdx]) > abs(array[eIdx]))
		{
			sortedSquaredArray[count] = array[sIdx]*array[sIdx];
			sIdx++;
		}
		else 
		{
			sortedSquaredArray[count] = array[eIdx]*array[eIdx];
			eIdx--;
		}
		count--;
			
	}
  	return sortedSquaredArray;
	*/
}

int main() {

	vector<int> array{1, 2, 3, 4, 6, 8, 9};
	vector<int> ans;

	ans = sortedSquaredArray(array);

	// expected output: [1, 4, 9, 25, 36, 64, 81]
	cout << "[";
	for (int i = 0; i < ans.size()-1; i++)
	{
		cout << ans[i] << ", ";
	}
	cout << ans[ans.size()-1] << "]" << endl;

	return 0;
}