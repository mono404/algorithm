#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int n, m, zcnt, vcnt, t, ans, res;
int arr[52][52];
int visit[52][52];
vector<pair<int, int>> v;
vector<int> pick;
queue<pair<int, int>> q;

void BFS()
{
	while (!q.empty())
	{
		t++;
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

				if (arr[ny][nx] == -1 || arr[ny][nx] == 1 || visit[ny][nx] > 0)
					continue;

				if (arr[ny][nx] == 0)
				{
					res = max(res, t);
					vcnt++;
				}

				visit[ny][nx] = t;
				q.push({ ny, nx });
			}
		}
	}
}

int  main(void)
{
	memset(arr, -1, sizeof(arr));

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				zcnt++;
			else if (arr[i][j] == 2)
				v.push_back({ i, j });
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (i < v.size() - m)
			pick.push_back(0);
		else
			pick.push_back(1);
	}

	ans = -1;

	do {
		memset(visit, 0, sizeof(visit));
		t = 0;
		vcnt = 0;
		res = 0;

		for (int i = 0; i < pick.size(); i++)
		{
			if (pick[i] == 1)
				q.push({ v[i].first, v[i].second });
		}

		BFS();

		if (zcnt == vcnt)
		{
			if (ans == -1)
				ans = res;
			else
				ans = min(res, ans);
		}
	} while (next_permutation(pick.begin(), pick.end()));

	cout << ans << "\n";
}