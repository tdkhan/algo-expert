/* ####################################################################################################

Write a function that takes in an array of integers and return the length of the longest peak in the 
array.

A peak is defined as adjacent integers in the array that are strictly increasing until they reach a tip
(the highest value in the peak), at which point they ceomce strictly decreasing. At least three integers
are required to form a peak.

For example, the integers '1, 4, 10, 2' form a peak, but the integers '4, 0, 10' don't and neither do the
integers '1, 2, 2, 0'. Similarly, the integers '1, 2, 3' don't form a peak because there aren't any 
strictly decreasing integers after 3.

##################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

int longestPeak(vector<int> array) {
	
  	// Solution 1: O(n) time | O(1) space
	int count = 1;
	int peak = 0;
	bool flag = false;
	for (int i = 1; i < array.size(); i++){
		if (array[i] > array[i-1] && flag == false){
			count += 1;
		}
		else if (count >= 2 && array[i] < array[i - 1]){
		    count++;
		    flag = true;
		    if (count>peak)
		        peak = count;
		}
		else{
			flag = false;
			if (array[i] > array[i-1])
			    count = 2;
			else
			count = 1;
		}
	}
  	return peak;
	/*
  	// Solution 2: O(n) time | O(1) space
  	int peak = 0;
	int count = 0;
	if(array.empty() == 1)
	    return peak;
	else{
    	for (int i = 1; i < array.size() - 1; i++){
    		if (array[i] > array[i+1] && array[i] > array[i-1]){
    			count = 3;
    			int rIdx = i+1;
    			int lIdx = i-1;
    			while((lIdx > 0 ) && (array[lIdx] > array[lIdx-1])){
    				count++;
    				lIdx--;
    			}
    			while((rIdx < (array.size()-1)) && (array[rIdx] > array[rIdx+1])){
    				count++;
    				i++;
    				rIdx++;
    			}
    		}
    		if (count > peak)
    			peak = count;
    		count = 0;
    	}
    }
	return peak;
	*/
}

int main() {

	vector<int> array{1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
	int ans;

	// expected output: 6 {peak: 0, 10, 6, 5, -1, -3}
	ans = longestPeak(array);
	cout << ans << endl;
	return 0;
}