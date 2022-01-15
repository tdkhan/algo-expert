/* ####################################################################################################

You're given a two-dimensional array (a matrix) of potentially unequal height and width containing only
0s and 1s. Each 0 represents land, and each 1 represents part of a river. A river consists of any number
of 1s that are either horizontally or vertically adjacent (but not diagnolly adjacent). The number of
adjacent 1s forming a river determine its size.

Note that a river can twist. In other words, it doesn't have to be straight vertical line or a 
straight horizontal line; it can be L-shaped for example.

Write a fucntion that returns an array of the sizes of all rivers represented in the input matrix. The 
sizes don't need to be in any particular order.

##################################################################################################### */

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

int depthFirstSearch (vector<vector<int>> *matrix, set<pair<int, int>> *visited, pair<int, int> index);
vector<pair<int, int>> getNeighbors (pair<int, int> current, int cols, int rows);

vector<int> riverSizes(vector<vector<int>> matrix) {
  	// Solution 1: O(w*h) time | O(w*h) space
	set<pair<int, int>> visited;
	vector <int> rivers;
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 1) {
				if (visited.find(make_pair(i, j)) == visited.end()){
					visited.insert(make_pair(i, j));
					pair<int, int> index(i, j);
					int size = 0;
					size = depthFirstSearch(&matrix, &visited, index);
					rivers.push_back(size);
				}
			}
		}
	}
  	return rivers;
}

int depthFirstSearch (vector<vector<int>> *matrix, set<pair<int, int>> *visited, pair<int, int> index) {
	vector<pair<int, int>> neighbors;
	int size = 0;
	vector<pair<int, int>> stack{index};
	pair<int, int> current;
	while (!stack.empty()) {
		current = stack[stack.size()-1];
		size++;
		stack.pop_back();
		int cols = matrix->at(0).size();
		int rows = matrix->size();
		neighbors = getNeighbors(current, cols, rows);
		for (int i = 0; i < neighbors.size(); i++) {
			int k = neighbors[i].first;
			int j = neighbors[i].second;
			if (visited->find(neighbors[i]) == visited->end()) {
				visited->insert(neighbors[i]);
				if ((*matrix)[k][j] == 1) 
					stack.push_back(neighbors[i]);
			}
		}
	}
	return size;
}

vector<pair<int, int>> getNeighbors (pair<int, int> current, int cols, int rows) {
	vector<pair<int, int>> neighbors{};
	if (current.second < cols-1)
		neighbors.push_back(make_pair(current.first, current.second + 1));
	if (current.first < rows -1)
		neighbors.push_back(make_pair(current.first + 1, current .second));
	if (current.second > 0)
		neighbors.push_back(make_pair(current.first, current.second - 1));
	if (current.first > 0)
		neighbors.push_back(make_pair(current.first - 1, current.second));
	return neighbors;
}

int main() {
	
	vector<vector<int>> matrix{{1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, 
								{0, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0}};
	/* matrix = [
		[1, 0, 0, 1, 0],
		[1, 0, 1, 0, 0],
		[0, 0, 1, 0, 1],
		[1, 0, 1, 0, 1],
		[1, 0, 1, 1, 0]
	]
	*/

	// expexted output: [1, 2, 2, 2, 5]
	vector <int> ans;
	ans = riverSizes(matrix);
	sort(ans.begin(), ans.end());
	cout << "[";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ", ";

	cout << "\b" << "\b]" << endl;
	return 0;
}