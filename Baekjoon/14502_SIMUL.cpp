#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int n, m, cnt, res = 999999999;
int arr[10][10];
int visit[10][10];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
vector<int> pick;
vector<pair<int, int>> virus;

int BFS()
{
	while (!q.empty())
	{
		int qsize = q.size();
		for (int k = 0; k < qsize; k++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			
			q.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (arr[ny][nx] != 0 || visit[ny][nx] == 1)
					continue;

				q.push({ ny, nx });
				visit[ny][nx] = 1;
				cnt++;
			}
		}
	}

	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(arr, -1, sizeof(arr));

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				v.push_back({ i, j });
			else if (arr[i][j] == 2)
				virus.push_back({ i, j });
		}
	}

	for (int i = 0; i < v.size() - 3; i++)
		pick.push_back(0);

	pick.push_back(1);
	pick.push_back(1);
	pick.push_back(1);

	do {
		memset(visit, 0, sizeof(visit));
		cnt = 0;

		for (int i = 0; i < virus.size(); i++)
			q.push(virus[i]);

		for (int i = 0; i < pick.size(); i++)
		{
			if (pick[i] == 1)
				arr[v[i].first][v[i].second] = 1;
		}

		res = min(BFS(), res);

		for (int i = 0; i < pick.size(); i++)
		{
			if (pick[i] == 1)
				arr[v[i].first][v[i].second] = 0;
		}

	} while (next_permutation(pick.begin(), pick.end()));

	cout << v.size() - 3 - res << endl;
}