/* ###################################################################################################

There's an algorithms tournament taking place in which teams of programmers compete against each other 
to solve algorithmic problems as fast as possible. Teams compete in a round robin, where each team faces
off against all other teams. Only two teams compete against each other at a time, and for each competition,
one team is designated the home team, while the other team is the away team. In each competetion there's 
always one winner and one loser; there are no ties. A team receives 3 points if it wins and 0 points if 
it loses. The winner of the tournament is the team that reveives the most amount of points.

Given an array of pairs representing the teams that have competed against each other and an array 
containing the results of each competition, write a function that returns the winner of the tournament. 
The input arrays are named competitions and results, respectively. The competitions array has elements 
in the form of [homeTeam, awayTeam], where each team is a string of at most 30 characters representing 
the name of the team. The results array contains information about the winner of each corresponding 
competition in the competitions array. Specifically, results[i] denotes the winner of competitions[i], 
where a 1 in the results array means that the home team in the corresponding competition won and a 0 
means that the away team won.

It's guaranteed that exactly one team will win the tournament and that each team will compete agianst all 
other teams exactly once. It's also guaranteed that the tournament will always have at least two teams.

#################################################################################################### */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {

	// Soution 1: O(n) time | O(k) space
	int maxScore = 0;
	string Winner = " ";
	unordered_map<string, int> score;
	
	for (int i = 0; i < competitions.size(); i++)
	{
		if (results[i] == 1)
		{
			if (score.find(competitions[i][0]) == score.end())
			{
				score[competitions[i][0]] = 3;
			}
			else
			{
				score.at(competitions[i][0]) += 3;
			}

			if (score.at(competitions[i][0]) > maxScore)
			{
				maxScore = score.at(competitions[i][0]);
				Winner = competitions[i][0];
			}
		}
		
		else
		{
			if (score.find(competitions[i][1]) == score.end())
			{
				score[competitions[i][1]] = 3;
			}
			else
			{
				score.at(competitions[i][1]) += 3;
			}
			
			if (score.at(competitions[i][1]) > maxScore)
			{
				maxScore = score.at(competitions[i][1]);
				Winner = competitions[i][1];
			}
		}
	}
	
  return Winner;
}

int main() {

	vector<vector<string>> competitions {{"HTML", "C#"}, {"C#", "Python"}, {"Python", "HTML"}};
	vector<int> results {0, 0, 1};
	string ans;

	// Expected Output: Python
	ans = tournamentWinner(competitions, results);
	cout << "Winner: " << ans << endl;
}