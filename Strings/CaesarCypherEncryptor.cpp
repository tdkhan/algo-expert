/* ####################################################################################################

Given a non-empty string of lowercase letters and a non-negative integer representing a key, write a 
function that returns a new string obtained by shifting every letter in the input string by k positons
in the alphabet, where k is the key.

Note that letters should "wrap" around the alphabet; in other words, the letter z shifted by one returns
the letter a.

##################################################################################################### */

#include <iostream>
#include <string>

using namespace std;

string caesarCypherEncryptor(string str, int key) {
  	
  	// Solution 1: O(n) time | O(1) space
	for (int i = 0; i < str.size(); i++){
		int aschii = (int)str[i] + key%26;
		aschii = aschii <= 122 ? aschii : aschii - 26; 
		str[i] = (char)aschii;
	}
  	return str;
}

int main() {

	string str = "xyz";
	int key = 2;
	string ans;

	// expected output: zab
	ans = caesarCypherEncryptor(str, key);
	cout << ans << endl;
	return 0;
}