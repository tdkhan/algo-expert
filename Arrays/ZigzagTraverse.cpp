/* ####################################################################################################

Write a function that takes in an n x m two-dimenstional array (that can be square-shaped when n==m) and
returns a one-dimensional array of all the array's elements in zigzag order.

Zigzag order starts at the top left corner of the two-dimensional array, goes down by one element, and
proceeds in a zigzag pattern all the way to the bottom right corner.

##################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array) {
  	
  	// Solution 1: O(n) time | O (n) space
	int dir = 0; // 0 down and 1 up
	int rows = array.size();
	int cols = array[0].size();
	int cc = 0;
	int cr = 0;
	int total = rows*cols;
	vector<int> ans{};

	while (ans.size() < total){
		if (cc == 0 && cr < rows-1){
		    ans.push_back(array[cr][cc]);
			cr++;
			dir = 1;
		}
		else if (cr == 0 && cc < cols-1){
		    ans.push_back(array[cr][cc]);
			cc++;
			dir = 0;
		}
		else if (cr == rows-1 && cc < cols){
		    ans.push_back(array[cr][cc]);
			cc++;
			dir = 1;
		}
		else if (cc == cols-1 && cr < rows){
		    ans.push_back(array[cr][cc]);
			cr++;
			dir = 0; 
		}
		
		while (ans.size() < total && dir == 1 && cr > 0 && cc < cols-1){
			ans.push_back(array[cr][cc]);
			cr--;
			cc++;
		}
		while (ans.size() < total && dir == 0 && cc > 0 && cr < rows-1){
			ans.push_back(array[cr][cc]);
			cr++;
			cc--;
		}
	}
  	return ans;
}

int main() {
	
	/* input:
	array = [
	[1, 3, 4, 10],
	[2, 5, 9, 11],
	[6, 8, 12, 15],
	[7, 13, 14, 16],
	] */

	vector<vector<int>> array{{1, 3, 4, 10}, {2, 5, 9, 11}, {6, 8, 12, 15}, {7, 13, 14, 16}};

	// expected output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
	vector<int> ans;
	ans = zigzagTraverse(array);
	cout << "[";
	for (auto x : ans)
		cout << x << ", ";
	cout << "\b\b]" << endl;
	return 0;
}