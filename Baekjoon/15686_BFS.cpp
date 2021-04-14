#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int n, m, ans = 999999999, res;
int arr[52][52];
int visit[52][52];
bool check;

queue<pair<int, int>> q;
vector<pair<int, int>> house;
vector<pair<int, int>> chick;
vector<int> pick;

int BFS()
{
	check = false;
	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
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

				if (arr[ny][nx] == -1 || visit[ny][nx] == 1)
					continue;

				if (arr[ny][nx] == 2)
				{
					check = true;
					break;
				}
				else
				{
					q.push({ ny,nx });
					visit[ny][nx] = 1;
				}
			}
		}

		if (check == true)
			break;
	}

	return cnt;
}

int main(void)
{
	memset(arr, -1, sizeof(arr));
	memset(visit, 0, sizeof(visit));

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				house.push_back({ i, j });
			else if (arr[i][j] == 2)
			{
				chick.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < chick.size(); i++)
	{
		if (i < m)
			pick.push_back(1);
		else
			pick.push_back(0);
	}

	sort(pick.begin(), pick.end());

	do {
		res = 0;

		for (int i = 0; i < pick.size(); i++)
		{
			if (pick[i] == 0)
				arr[chick[i].first][chick[i].second] = 0;
		}

		for (int i = 0; i < house.size(); i++)
		{
			q = queue<pair<int, int>>();
			memset(visit, 0, sizeof(visit));

			q.push(house[i]);
			visit[house[i].first][house[i].second] = 1;

			res += BFS();
		}

		for (int i = 0; i < pick.size(); i++)
		{
			if (pick[i] == 0)
				arr[chick[i].first][chick[i].second] = 2;
		}

		if (ans > res)
			ans = res;
	} while (next_permutation(pick.begin(), pick.end()));

	cout << ans << endl;
}