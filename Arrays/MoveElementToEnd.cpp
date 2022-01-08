/* ####################################################################################################

You're given an array of integers and an integer. Write a function that moves all instances of that
integer in the array to the end of the array and returns the array.

The function should perform this in place (i.e., it should mutate the input array) and doesn't need to
maintain the order of the other integers.

##################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  	

  	// Solution 1: brute force approach - O(nlog(n)) time | O(1) space
  	sort(array.begin(), array.end());
	if (array.empty() == true || array[array.size()-1] == toMove)
		return array;
	else{
		int idx = 0; 
		vector<int>::iterator i;

		while (array[idx] <= toMove && idx < array.size())
		{
			if (array[idx] == toMove)
			{
				i = array.begin() + idx;
				int holder = array[idx];
				array.erase(i);
				array.push_back(holder);
			}
			else
			{
				idx++;
			}	
		}
		return array;
	}
	
	/*
	// Solution 2: O(n) time | O(1) space
	int right = array.size() - 1;
	int left = 0;
	while (left < right)
	{
		if (array[right] == toMove)
			right--;
		else if (array[left] == toMove)
		{
			swap(array[right], array[left]);
			right--;
			left++;
		}
		else
			left++;
	}
  	return array;
	*/
}

int main() {

	vector<int> array{2, 1, 2, 2, 2, 3, 4, 2};
	int toMove = 2;

	// expected output [1, 3, 4, 2, 2, 2, 2, 2] or [4, 1, 3, 2, 2, 2, 2, 2] 
	array = moveElementToEnd(array, toMove);

	cout << "[";
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << ", ";
	}
	cout << "\b" << "\b]" << endl;

	return 0;
}