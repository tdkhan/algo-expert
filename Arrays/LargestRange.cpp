/* ####################################################################################################

Write a function that takes in an array of integers and returns an array of length 2 representing the 
largest range of integers contained in that array.

The first number in the output array should be the first number in the range, while the second number 
should be the last number in the range.

A range of numbers is defined as a set of numbers that come right after each other in the set of real
integers. For instance, the output array [2, 6] represents the range {2, 3, 4, 5, 6}, which is a range 
of length 5. Note that numbers don't need to be sorted or adjacent in the input array in order to form 
a range.

You can assume that there will only be one largest range.

##################################################################################################### */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> largestRange(vector<int> array) {
  	/*
  	// Solution 1: Brute Force Approach: O(nlog(n)) time | O(1) space
	if (array.size() == 1)
		return {array[0], array[0]};
	sort(array.begin(), array.end());
	int count, first;
	int range = 0;
	vector<int> ans;
	for (int i = 0; i < array.size(); i++){
		count = 0;
		first = array[i];
		while (i < array.size() && (array[i+1]-array[i] == 1 || array[i+1] == array[i])){
			if (array[i+1] != array[i])
				count++;
			i++;
		}
		if (count > range){
			range = count;
			ans.clear();
			ans = {first, array[i]};
		}
	}
	return ans;
	*/

	// Solution 2: O(n) time | O(n) space
	unordered_map<int, bool> map;
	for (int i = 0; i < array.size(); i++){
		if (map.find(array[i]) == map.end())
			map[array[i]] = false;
	}
	int count = 0; 
	int k, l;
	int start, end;
	for(int i = 0; i < array.size(); i++){
		if (map[array[i]] == false){
			map[array[i]] = true;
			k = 1;
			while (map.find(array[i]-k)!=map.end()){
				map[array[i]-k] = true;
				k++;
			}
			l = 1;
			while (map.find(array[i]+l)!=map.end()){
				map[array[i]+l] = true;
				l++;
			}
			if (l+k-2 >= count){
				count = l+k-2;
				start = array[i]-k+1;
				end = array[i]+l-1;
			}
		}
	}
  	return {start, end};

}

int main() {

	vector<int> array{1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};

	// expected output: [0, 7]
	vector<int> ans;
	ans = largestRange(array);
	cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
	return 0;
}