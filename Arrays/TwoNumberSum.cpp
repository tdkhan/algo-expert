/* ###################################################################################################

Write a function that takes in a non-empty array of distinct integers and an integer representeing a 
target sum. If any two numbers in the input array sum up to the target sum, the function should return
them in an array, in any order. If no two numbers sum up to the targe sum, the function should return
an empty array.

Note that the target sum has to be ontained by summing two different integers in the array; you can't
add a single integer to itself in order to obtain the target sum.

You can assume that there will be at most one pair of numbers summing up to the target sum.

#################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	
	vector<int> result;

	
	// SOLUTION 1: brute force approach - O(n^2) time | O(1) space 
	int sum;
	for(int i = 0; i < (array.size() - 1); i++)
	{
		for(int j = i + 1; j < array.size(); j++)
		{
			sum = array[i] + array[j];
			
			if (sum == targetSum)
			{
				result.push_back(array[i]);
				result.push_back(array[j]);
				return result;
			}
		}
	}
	return {};
	

	/*
	// SOLUTION 2: O(nlog(n)) time | O(1) space
	sort(array.begin(), array.end());
	int left = 0;
	int right = array.size()-1;
	int sum;

	while (right > left) 
	{
		sum = array[left] + array[right];
		
		if (sum == targetSum) 
		{
			result.push_back(array[right]);
			result.push_back(array[left]);
			return result;
		}
		
		else if (sum > targetSum)
			right--;

		else
			left++;  
	}
	return {};
	*/

	/*
	// SOLUTION 3: O(n) time complexity | O(n) space complexity
	unordered_set<int> uset;
	int diff;

	for (int i = 0; i < array.size(); i++) 
	{
		diff = targetSum - array[i];
		if (uset.find(diff) == uset.end())
		{
			uset.insert(array[i]);
		}

		else  
		{	
			result.push_back(array[i]);
			result.push_back(diff);
			break;
		}
	} 
	return result;
	*/

}

int main() {

	vector<int> array{3, 5, -4, 8, 11, -1, 6};
	int targetSum = 10;
	vector<int> ans;

	ans = twoNumberSum(array, targetSum);

	// expected output: [11, -1] or [-1, 11]
	cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

	return 0;
}