/* ###################################################################################################

Write a function that takes in a non-empty array of distinct integers and an integer representing a 
target sum. The function should find all triplets in the array that sum up to the target sum and return
a two-dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending
order, and the triplets themselves should be ordered in ascending order with respect to the numbers they
hold.

If no three numbers sum up to the target sum, the function should return an empty array.

#################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  	
	vector<vector<int>> triplets {};
	vector<int> triplet;
	int size = array.size();

	sort(array.begin(), array.end());
	

  	// Solution 1: Brute force approach - O(n^3) time | O(N) space

	for(int i = 0; i < size - 2; i++)
	{
		for(int j = i+1; j < size - 1; j++)
		{
			for(int k = j+1; k < size; k++)
			{
				triplet = {};

				if((array[i] + array[j] + array[k]) == targetSum)
				{
					triplet.push_back(array[i]);
					triplet.push_back(array[j]);
					triplet.push_back(array[k]);
					triplets.push_back(triplet);
				}
			}
		}
	}
	

	/*
	// Solution 2: O(n^2) time | O(N) space

	int leftIdx, rightIdx, sum;
	
	for(int i = 0; i < size - 2; i++)
	{
		sum = targetSum - array[i];
		
		leftIdx = i+1;
		rightIdx = size-1;
		
		while(rightIdx > leftIdx)
		{
			if ((array[leftIdx] + array[rightIdx]) > sum)
				rightIdx--;

			else if ((array[leftIdx] + array[rightIdx]) < sum)
				leftIdx++;

			else 
			{
				triplet = {};
				triplet.push_back(array[i]);
				triplet.push_back(array[leftIdx]);
				triplet.push_back(array[rightIdx]);
				triplets.push_back(triplet);
				leftIdx++;
				rightIdx--;
			}
		}
	}
	*/

	return triplets;
}

int main() {

	vector<int> array{12, 3, 1, 2, -6, 5, -8, 6};
	int targetSum = 0;

	vector<vector<int>> ans;

	// expected output: [ [-8, 2, 6] [-8, 3, 5] [-6, 1, 5] ]
	ans = threeNumberSum(array, targetSum);

	cout << "[ ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << "[" << ans[i][0] << ", " << ans[i][1] << ", " << ans[i][2] << "] " ;
	}
	cout << "]" << endl;
}