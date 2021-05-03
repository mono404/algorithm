#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>

using namespace std;

int n, m, s, d, ans, minv, midv, maxv;
vector<int> g[10001];
map<pair<int, int>, int> w;
queue<int> q;
int visit[10001];

int BFS()
{
	int res = -1;
	while (!q.empty())
	{
		int c = q.front();
		q.pop();

		for (int i = 0; i < g[c].size(); i++)
		{
			if (visit[g[c][i]] == 1)
				continue;

			if (g[c][i] == d && w[{c, g[c][i]}] >= midv)
				res = 1;

			if (w[{c, g[c][i]}] >= midv)
			{
				visit[g[c][i]] = 1;
				q.push(g[c][i]);
			}
		}
	}

	return res;
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pair<int, int> p1 = { a, b };
		pair<int, int> p2 = { b, a };


		w[p1] = c;
		w[p2] = c;

		if (c > maxv)
			maxv = c;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	cin >> s >> d;

	minv = 1;
	while (minv <= maxv)
	{
		memset(visit, 0, sizeof(visit));
		midv = (minv + maxv) / 2;

		visit[s] = 1;
		q.push(s);
		int check = BFS();

		if (check == 1)
			minv = midv + 1;
		else
			maxv = midv - 1;
	}
	
	cout << minv - 1 << "\n";

	return 0;
}