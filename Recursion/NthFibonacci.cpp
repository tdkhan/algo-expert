/* ####################################################################################################

The Fibonacci sequence is defined as follows: the first number of the sequence is 0, the second number
is 1, and the nth number is the sum of the (n-1)th and (n-2)th numbers. Write a function that takes in 
an itneger n and returns the nth Fibonacci number.

Important note: the Fibonacci sequence is often defined with its first numbers as F0 = 0 and F1 = 1. For
the purpose of this question, the first Fibonacci number is F0; therefore, getNthFib(1) is equal to F0,
getNthFib(2) is equal to F1, etc..

##################################################################################################### */

#include <iostream>
#include <unordered_map>

using namespace std;

int helper(int n, unordered_map<int, int> memoize) {
	if(memoize.find(n) != memoize.end())
		return memoize[n];
	else
		return helper(n-1, memoize) + helper(n-2, memoize);
}

int getNthFib(int n) {
	
 	// Solution 1: Recursive - O(2^n) time | o(n) space
  	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return getNthFib(n-1) + getNthFib(n-2);
	
	/*
	// Solution 2: Recursive - O(n) time | O(n) space
	unordered_map<int, int> memoize({{1, 0}, {2, 1}});
	return helper(n, memoize);
	
	
	// Solution 3: Iterative - O(n) time | O(1) space
	int f0 = 0;
	int f1 = 1;
	
	for (int i = 3; i <= n; i++) {
		int temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return n > 1 ? f1 : f0;
	*/
}

int main() {

	// n = 6, sequence: 0, 1, 1, 2, 3, 5
	int n = 6;

	// expected output: 5
	int ans;
	ans = getNthFib(n);
	cout << ans << endl;
	return 0;
}