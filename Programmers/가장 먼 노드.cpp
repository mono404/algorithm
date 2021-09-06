#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

map<int, vector<int>> m;
int visit[20001];
vector<vector<int>> g;
queue<int> q;

void BFS()
{
	int dis = 0;
	while (!q.empty())
	{
		dis++;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int cur = q.front();
			q.pop();

			for (int j = 0; j < g[cur].size(); j++)
			{
				if (visit[g[cur][j]] == 1)
					continue;

				m[dis].push_back(g[cur][j]);
				visit[g[cur][j]] = 1;
				q.push(g[cur][j]);
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	m.clear();
	g.clear();
	g.resize(20000);
	memset(visit, 0, sizeof(visit));
	
	for (int i = 0; i < edge.size(); i++)
	{
		g[edge[i][0]].push_back(edge[i][1]);
		g[edge[i][1]].push_back(edge[i][0]);
	}

	visit[1] = 1;
	q.push(1);
	BFS();

	map<int, vector<int>>::iterator it = --m.end();

	answer = it->second.size();

	return answer;
}

int main(void)
{
	cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}} ) << endl;
	cout << solution(7, { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}, {5, 7} }) << endl;

}