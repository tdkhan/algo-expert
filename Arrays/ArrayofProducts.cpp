/* ####################################################################################################

Write a function that takes in a non-empty array of integers and returns an array of the same length, 
where each element in the output array is equal to the product of every other number in the input array.

In other words, the value at output[i] is equal to the product of every number in the input array other
than input [i].

Note you're expected to solve this problem without using division.

##################################################################################################### */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  	
  	// Solution 1: C++ STL - O(n^2) time | O(n) space 
	vector<int> copy;
	vector<int> ans;
	vector<int>::iterator it;
	
	for (int i = 0; i < array.size(); i++){
		copy = array;
		it = copy.begin() + i;
		copy.erase(it);
		ans.push_back(accumulate(copy.begin(), copy.end(), 1, multiplies<int>()));
	}
  	return ans;
	 
	/*
  	// Solution 2: nested loops - O(n^2) time | O(n) space
  	vector<int> ans;
	int i = 0;
	int left;
	int right;
	int lp;
	int rp;
	while (i < array.size()){
		right = i+1;
		left = i-1;
		lp = 1;
		rp = 1;
		while (left >= 0){
			lp *= array[left];
			left--;
		}
		while (right < array.size()){
			rp *= array[right];
			right++;
		}
		ans.push_back(lp*rp);
		i++;
	}
  	return ans;
	

  	// Solution 3: O(n) time | O(n) space
	vector<int> ans;
	int product = 1;
	for (int i = 0; i < array.size(); i++){
		ans.push_back(product);
		product *= array[i];
	}
	product = 1;
	for (int i = array.size()-1; i >= 0; i--){
		ans[i] *= product; 
		product *= array[i];
	}
  	return ans;
  	*/
}

int main() {

	vector<int> array{5, 1, 4, 2};
	vector<int> ans;

	// expected output: [8, 40, 10, 20]
	ans = arrayOfProducts(array);
	cout << "[";
	for (auto i : ans)
		cout << i << ", ";
	cout << "\b" << "\b]" << endl;
	return 0;
}