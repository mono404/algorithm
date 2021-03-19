#include<iostream>
#include<cstring>
#include <queue>

using namespace std;

void BFS();

int n, m, ans;
int arr[1002][1002];
int check[1002][1002];
queue<pair<int, int>> q;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
	memset(arr, -1, sizeof(arr));

	cin >> n;
	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				check[i][j] = -1;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1)
			{
				q.push(pair<int, int>(i, j));
				check[i][j] = 1;
				ans = 1;
			}
		}
	}

	BFS();

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << check[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check[i][j] == 0)
			{
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	cout << ans - 1 << endl;
}

void BFS()
{
	int cur_y = q.front().first;
	int cur_x = q.front().second;

	while (!q.empty())
	{
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (arr[next_y][next_x] == 0 && check[next_y][next_x] == 0)
			{
				check[next_y][next_x] = check[cur_y][cur_x] + 1;
				q.push(pair<int, int>(next_y, next_x));

				if (ans < check[next_y][next_x])
					ans = check[next_y][next_x];
			}
		}
	}
}
