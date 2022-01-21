/* ###################################################################################################

Write a function that takes in an nxm two-dimensional array (that can be square-shaped when n==m) and 
returns a one-dimensional array of all the array's elements in spiral order.

Spiral order starts at the top left corner of the two-dimensional array, goes to the right, and proceeds
in a spiral pattern all the way until every element has been visited.

#################################################################################################### */

#include <iostream>
#include <vector>

using namespace std;

//void traverse(vector<vector <int>> array, vector<int> &ans, int sc, int sr, int ec, int er);

vector<int> spiralTraverse(vector<vector<int>> array) {

	
  	// Solution 1: iterative - O(N) time | O(N) space 
	if (array.empty() == true)
		return {};
	int cols = array[0].size()-1;
	int rows = array.size()-1;
	vector<int> topLeft = {0,0};
	vector<int> topRight = {1, cols};
	vector<int> bottomRight = {rows, cols-1};
	vector<int> bottomLeft = {rows-1, 0};
	vector<int> ans;
	int total = array.size()*array[0].size();
	while (ans.size() < total){
		for (int i = topLeft[1]; i <= topRight[1]; i++)
			ans.push_back(array[topLeft[0]][i]);
		topLeft[0]+=1;
		topLeft[1]+=1;
		if (ans.size() == total)
		    break;
		for (int i = topRight[0]; i <= bottomRight[0]; i++)
			ans.push_back(array[i][topRight[1]]);
		topRight[0]+=1;
		topRight[1]-=1;
		if (ans.size() == total)
		    break;
		for (int i = bottomRight[1]; i >= bottomLeft[1]; i--)
			ans.push_back(array[bottomRight[0]][i]);
		bottomRight[0]-=1;
		bottomRight[1]-=1;
		if (ans.size() == total)
		    break;
		for (int i = bottomLeft[0]; i >= topLeft[0]; i--)
			ans.push_back(array[i][bottomLeft[1]]);
		bottomLeft[0]-=1;
		bottomLeft[1]+=1;
	}
  	return ans;
  	
	/*
  	// Solution 2: recursive - O(N) time | O(N) space
  	vector<int> ans;
	traverse(array, ans, 0, 0, array[0].size()-1, array.size()-1);
  	return ans;
	*/
}

/*
void traverse(vector<vector <int>> array, vector<int> &ans, int sc, int sr, int ec, int er){
	if (sc > ec || sr > er)
		return;
	for (int i = sc; i <= ec; i++)
		ans.push_back(array[sr][i]);
	for (int i = sr+1; i <= er; i++)
		ans.push_back(array[i][ec]);
	for (int i = ec-1; i >= sc; i--){
		if (er == sr)
		break;
		ans.push_back(array[er][i]);
	}
	for (int i = er-1; i >= sr+1; i--){
		if (sc == ec)
		break;
		ans.push_back(array[i][sc]);
	}
	sc += 1;
	sr += 1;
	ec -= 1;
	er -= 1;
	traverse(array, ans, sc, sr, ec, er);
}
*/

int main() {

	vector<vector<int>> array{{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};

	// expected output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
	vector<int> ans;
	ans = spiralTraverse(array);
	cout << "[";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ", ";
	}
	cout << "\b" << "\b]" << endl;
	return 0;
}