/* ###################################################################################################

Given an array of positive integers representing the values of coins in your possession, write a function
that returns the minimum amount of change (the minimum sum of money) that you cannot create. The given 
coins can have any positive integer value and aren't unique (i.e., you can have multiple coins of the same
value).

For example, if you're given coins=[1, 2, 5], the minimum amount of change that you can't create is 4. If
you're given no coins, the minimum amount of change that you can't create is 1.

#################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nonConstructibleChange(vector<int> coins) {
  
  	// Solution 1: O(nlog(n)) time | O(1) space
	sort(coins.begin(), coins.end());
	int sum = 0;
	
	for (int i = 0; i < coins.size(); i++)
	{
		if(coins[i] > sum + 1)
			return (sum + 1);
		
		else
			sum = sum + coins[i];	
	}
  	return (sum + 1);
}

int main() {

	vector<int> coins{5, 7, 1, 1, 2, 3, 22};
	int ans;

	// expected output: 20
	ans = nonConstructibleChange(coins);
	cout << ans << endl;

	return 0;
}