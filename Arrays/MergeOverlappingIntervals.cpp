/* ###################################################################################################

Write a function that takes in a non-empty array of arbitrary intervals, merges any overlappong intervals,
and returns the new intervals in no particular order.

Each interval is an array of two integers, with interval[0] as the start of the interval and interval[i]
as the end of the interval.

Note that back-to-back intervals aren't considered to be overlapping. For example [1, 5] and [6, 7] aren't
overlapping; however, [1,6] and [6, 7] are indeed overlapping.

Also note that the start of any particular interval will always be less than or equal to the end of that
interval.

#################################################################################################### */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortVec (vector<int> &a, vector<int> &b){
	return a[0] < b[0];
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  	
  	// Solution 1: O(nlog(n)) time | O(n) space
	sort(intervals.begin(), intervals.end(), sortVec);
	vector<vector<int>*> mergedIntervals;
	vector<int>* currentInterval = &intervals[0];
	mergedIntervals.push_back(currentInterval);
	
	for (auto &nextinterval : intervals){
		int currentIntervalEnd = currentInterval->at(1);
		int nextIntervalEnd = nextinterval[1];
		int nextIntervalStart = nextinterval[0];
		
		if(nextIntervalStart <= currentIntervalEnd)
			currentInterval->at(1) = max(nextIntervalEnd, currentIntervalEnd);
		else{
			mergedIntervals.push_back(&nextinterval);
			currentInterval = &nextinterval;
		}
	}

	vector<vector<int>> ans;
	for (int i = 0; i < mergedIntervals.size(); i++){
		ans.push_back({mergedIntervals[i]->at(0),mergedIntervals[i]->at(1)});
	}

	return ans;
}


int main() {

	vector<vector<int>> intervals{{1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10}};
	vector<vector<int>> ans;

	// expected output: [[1, 2], [3, 8], [9, 10]]
	ans = mergeOverlappingIntervals(intervals);
	cout << "[";
	for (int i = 0; i < ans.size(); i++)
		cout << "[" << ans[i][0] << ", " << ans[i][1] << "], ";
	cout << "\b" << "\b]" << endl;
	return 0;
}  