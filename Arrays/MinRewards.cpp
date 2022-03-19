/* ####################################################################################################

Imagine that you're a teacher who's just graded the final exam in class. You have a list of student 
scores on the final exam in a particular order (not necessarily sorted), and you want to reward your 
students. You decide to do so fairly by giving them aribitary rewards following two rules:
	
	1. All students must receive at least one reward.
	2. Any given student must receive strictly more rewards than an adjacent student (a student immediately)
	   to the left or to the right) with a lower score and must receive strictly fewer rewards than an
	   adjacent student with a higher score.

Write a function that takes in a list of scores and returns the minimum number of rewards that you must
give out to students to satisfy the two rules.

You can assume that all students have different scores; in other words, the scores are all unique. 

##################################################################################################### */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int minRewards(vector<int> scores) {

  	// Solution 1: O(n) time | O(n) space
	if (scores.size() == 1)
		return 1;
	vector<int> min_indices{};

	if (scores[0] < scores[1])
		min_indices.push_back(0);
	for (int i = 1; i < scores.size()-1; i++){
		if (scores[i]<scores[i+1] && scores[i]<scores[i-1])
			min_indices.push_back(i);
	}
	if (scores[scores.size()-1] < scores[scores.size()-2])
		min_indices.push_back(scores.size()-1);
	
	vector<int> rewards(scores.size(), 0);
	for (int x : min_indices){
		rewards[x] = 1;
		int reward = 2;
		int i = x;
		while (scores[x] < scores[x+1] && x+1 < scores.size()){
			if (rewards[x+1] < reward)
				rewards[x+1] = reward;
			reward++;
			x++;
		}
		reward = 2;
		x = i;
		while (scores[x] < scores[x-1] && x-1 >= 0){
			if (rewards[x-1] < reward)
				rewards[x-1] = reward;
			reward++;
			x--;
		}
	}
	int sum = accumulate(rewards.begin(), rewards.end(), 0);
  	return sum;
}

int main() {

	vector<int> scores{8, 4, 2, 1, 3, 6, 7, 9, 5};
	int ans;

	// expected output: 25
	ans = minRewards(scores);
	cout << ans << endl;
	return 0;
}