/* ###################################################################################################

Write a function that takes in a non-empty string and that returns a boolean representing wether the 
string is a palindrome.

A palindrome is defined as a string that's written the same forward and backward. Note that single-
character strings are palindromes.

#################################################################################################### */

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
  	
  	// Solution 1: O(n) time | O(1) space
	int right = str.length() - 1;
	int left = 0;
	
	while (left < right){
		if (str[left] != str[right])
			return false;
		right--;
		left++;
	}
  	return true;
}


int main() {

	string test = "abcdcba";
	bool ans;
	
	// expected output: 1
	ans = isPalindrome(test);
	cout << ans << endl;
	return 0;
}