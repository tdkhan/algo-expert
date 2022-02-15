/* ####################################################################################################

Write a function that takes in a non-empty array of distinct integers and an integer representing a
target sum. The function should find all quadruplets in the array that sum up to the target sum and return
a two-dimensional array of all these quadruplets in no particular order.

If no four number sum up to the target sum, the function should return an empty array.

##################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
	
	/*
	// Solution 1: Brute force approach - O(n^4) time | o(n) space
	vector<vector<int>> ans;
	int size = array.size();
	for (int i = 0; i < size-3; i++){
		for (int j = i+1; j < size-2; j++){
			for (int k = j+1; k < size-1; k++){
				for (int l = k+1; l < size; l++){
					if (array[i]+array[j]+array[k]+array[l] == targetSum)
						ans.push_back({array[i], array[j], array[k], array[l]});
				}
			}
		}
	}
	return ans;
	*/

	// Solution 2: O(n^4) time | o(n) space
	int size = array.size();
	int start, end;
	sort(array.begin(), array.end());
	vector<vector<int>> ans;
	for (int i = 0; i < size-3; i++){
		for (int j = i+1; j < size-2; j++){
			start = j+1;
			end = size-1;
			while (start < end){
				if (array[i]+array[j]+array[start]+array[end] == targetSum){
					ans.push_back({array[i], array[j], array[start], array[end]});
					end--;
					start++;
				}
				else if (array[i]+array[j]+array[start]+array[end] > targetSum)
					end--;
				else
					start++;
			}
		}
	}
  	return ans;
  	
}

void printVector(vector<vector<int>> array) {
	if (array.empty() == 1){
		cout << "[ ]" << endl;
		return;
	}
	int rows = array.size();
	int cols = array[0].size();
	for (int i = 0; i < rows; i++){
		cout << "["; 
		for (int j = 0; j < cols; j++){
			cout << array[i][j] << ", ";
		}
		cout << "\b\b]" << endl;
	}
}

int main() {

	// input array: [7, 6, 4, -1, 1, 2]
	vector<int> array{7, 6, 4, -1, 1, 2};
	int targetSum = 16;

	// expected output: [7, 6, 4, -1], [7, 6, 1, 2] - the quadruplets can be ordered differently
	vector<vector<int>> ans;
	ans = fourNumberSum(array, targetSum);
	printVector(ans);
	return 0;
}