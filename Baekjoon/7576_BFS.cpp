#include <iostream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

void BFS();

int n, m, h, ans;
int arr[102][102][102];
int check[102][102][102];
queue<pair<int, pair<int, int>>> q;

int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void)
{
	memset(arr, -1, sizeof(arr));

	cin >> n;
	cin >> m;
	cin >> h;

	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{

				cin >> arr[k][i][j];
				if (arr[k][i][j] == -1)
					check[k][i][j] = -1;
				else if (arr[k][i][j] == 1)
				{
					q.push(pair<int, pair<int, int>>(k, make_pair(i, j)));
					check[k][i][j] = 1;
					ans = 1;
				}

			}
		}
	}

	BFS();

	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{

				if (check[k][i][j] == 0)
				{
					cout << "-1" << endl;
					return 0;
				}

			}
		}
	}

	cout << ans - 1 << endl;
}

void BFS()
{
	int cur_z = q.front().first;
	int cur_y = q.front().second.first;
	int cur_x = q.front().second.second;

	while (!q.empty())
	{
		cur_z = q.front().first;
		cur_y = q.front().second.first;
		cur_x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			int next_z = cur_z + dz[i];

			if (arr[next_z][next_y][next_x] == 0 && check[next_z][next_y][next_x] == 0)
			{
				check[next_z][next_y][next_x] = check[cur_z][cur_y][cur_x] + 1;
				q.push(pair<int, pair<int, int>>(next_z, make_pair(next_y, next_x)));

				if (ans < check[next_z][next_y][next_x])
					ans = check[next_z][next_y][next_x];
			}
		}
	}
}
