/* ####################################################################################################

Write a function that takes in an array of at least two integers and that returns an array of the starting
and ending indices of the smallest subarray in the input array that needs to be sorted in place in order
for the entire input array to be sorted (in ascending order).

If the input array is already sorted, the function should return [-1, 1].

##################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> subarraySort(vector<int> array) {
  	
  	// Solution 1: Brute Force - O(nlog(n)) time | O(n) space
	vector<int> copy = array;
	sort(array.begin(), array.end());
	if (array == copy)
		return {-1, -1};
	int left, right;
	for(int k = 0; k < array.size(); k++){
		if (array[k] != copy[k]){
			left = k;
			break;
		}
	}
	for(int k = array.size()-1; k >= 0; k--){
		if (array[k] != copy[k]){
			right = k;
			break;
		}
	}
	return{left, right};
	
	/*
	// Solution 2: O(n) time | O(1) space
	vector <int> unsorted;
	if (array[0] > array[1])
		unsorted.push_back(array[0]);
	for (int i = 1; i <= array.size()-2; i++){
		if (array[i] < array[i-1] || array[i] > array[i+1]){
			unsorted.push_back(array[i]);
		}
	}
	if (array[array.size()-1] < array[array.size()-2])
		unsorted.push_back(array[array.size()-1]);
	
	if (unsorted.empty()==1)
		return {-1, -1};
	
	int min = *min_element(unsorted.begin(), unsorted.end());
	int max = *max_element(unsorted.begin(), unsorted.end());
	int l, r;
	int i = 0;
	while (array[i] <= min){
		i++;
	}
	l = i;
	i = array.size()-1;
	while (array[i] >= max){
		i--;
	}
	r = i;
	return {l, r};
	*/
}

int main() {

	vector<int> array{1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
	vector<int> ans;

	// expected output: [3, 9]
	ans = subarraySort(array);
	cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
	return 0;
}