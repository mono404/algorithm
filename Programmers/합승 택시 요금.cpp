#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;

	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < 201; j++)
		{
			if (i == j)
				dist[i][j] == 0;
			else
				dist[i][j] = 99999999;
		}
	}

	for (int i = 0; i < fares.size(); i++)
	{
		dist[fares[i][0]][fares[i][1]] = fares[i][2];
		dist[fares[i][1]][fares[i][0]] = fares[i][2];
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	answer = 99999999;
	for (int i = 1; i <= n; i++)
	{
		answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
	}
	return answer;
}

int main(void)
{
	cout << solution(6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}} ) << endl;
	cout << solution(7, 3, 4, 1, {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}} ) << endl;
	cout << solution(6, 4, 5, 6, {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}} ) << endl;
}