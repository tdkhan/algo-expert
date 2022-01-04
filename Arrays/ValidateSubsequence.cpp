/* ###################################################################################################

Given two non-empty arrays of integers, write a function that determines whether the second array is a 
subsequence of the first one.

A subsequence of an array is a set of numbers that aren't necessarily adjacent in the array but that are 
in the same order as they appear in the array. For instance, the numbers [1, 3, 4] form a subsequence
of the array [1, 2, 3, 4], and so do the numbers [2, 4]. Note that a single number in an array and the 
array itself are both valid subsequnces of the array. 

#################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {

	// SOLUTION 1: brute force approach - O(n) time | O(1) space 
	int arrCount, seqCount;
	arrCount = 0;
	seqCount = 0;
	
	while (arrCount < array.size() && seqCount < sequence.size())
	{
		if (array [arrCount] == sequence[seqCount])
			seqCount++;
		
		arrCount++;
	}
	
	return seqCount == sequence.size();
}

int main() {

	vector<int> array{5, 1, 22, 25, 6, -1, 8, 10};
	vector<int> sequence{1, 6, -1, 10};

	bool ans;
	ans = isValidSubsequence(array, sequence);

	// expected output: 1
	cout << ans << endl;

	return 0;
}