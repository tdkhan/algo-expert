/* ####################################################################################################

Write a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from
each array) whose absolute difference is closest to zero, and returns an array containing these two 
numbers, with the number from the first array in the first position.

Note that the absolute difference of two integers is the distance between them on the real number line. 
For example, the absolute difference of -5 and 5 is 10, and the absolute difference of -5 and -4 is 1.

You can assume that there will only be one pair of numbers with the samllest difference.

##################################################################################################### */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  	
  	/*
  	// Solution 1: Brute Force approach - O(n^2) time | O(1) space
	vector<int> ans;
	int diff = INT_MAX;
	
	for (int i = 0; i < arrayOne.size(); i++)
	{
		for (int j = 0; j < arrayTwo.size(); j++)
		{
			if (abs(arrayOne[i] - arrayTwo[j]) < diff)
			{
				diff = abs(arrayOne[i] - arrayTwo[j]);
				ans.clear();
				ans.push_back(arrayOne[i]);
				ans.push_back(arrayTwo[j]);
			}
		}
	}
  	return ans;
  	*/

  	// Solution 2: O(nlog(n)+mlog(m)) time | O(1) time
  	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	int first = 0;
	int second = 0;
	int diff = numeric_limits<int>::max();
	int sum;
	vector<int> ans;
	while (first < arrayOne.size() && second < arrayTwo.size()){
		sum = abs(arrayOne[first] - arrayTwo[second]);
		if (sum == 0){
			ans.clear();
			ans.push_back(arrayOne[first]);
			ans.push_back(arrayTwo[second]);
			return ans;
		}
		else{
			if (sum < diff){
				diff = sum;
				ans.clear();
				ans.push_back(arrayOne[first]);
				ans.push_back(arrayTwo[second]);		
			}
			if (arrayOne[first] < arrayTwo[second])
				first++;
			else
				second++;
		}
	}
	return ans;

}


int main() {

	vector<int> arrayOne{-1, 5, 10, 20, 28, 3};
	vector<int> arrayTwo{26, 134, 135, 15, 17};

	vector<int> ans;

	// expected output: [28, 26]
	ans = smallestDifference(arrayOne, arrayTwo);
	cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

	return 0;
}