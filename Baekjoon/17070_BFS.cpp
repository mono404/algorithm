#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int dy[3] = { 0,1,1 };
int dx[3] = { 1,0,1 };

int n, cnt, state;
int arr[18][18];
int visit[18][18];
queue<pair<pair<int, int>, int>> q;

void BFS()
{
	int ny;
	int nx;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int s = q.front().second;
		q.pop();

		if (y == n && x == n)
			cnt++;

		if (s == 0)
		{
			ny = y + dy[0];
			nx = x + dx[0];

			if (arr[ny][nx] == 0)
				q.push({ {ny, nx}, 0 });
		}
		else if (s == 1)
		{
			ny = y + dy[1];
			nx = x + dx[1];

			if (arr[ny][nx] == 0)
				q.push({ {ny, nx}, 1 });
		}
		else if (s == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				ny = y + dy[i];
				nx = x + dx[i];

				if (arr[ny][nx] == 0)
					q.push({ {ny, nx}, i });
			}
		}

		int c = 0;
		for (int i = 0; i < 3; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];

			if (arr[ny][nx] == 0)
				c++;
			else if (arr[ny][nx] == 1)
				break;
		}

		if (c == 3)
		{
			ny = y + dy[2];
			nx = x + dx[2];

			if (arr[ny][nx] == 0)
				q.push({ {ny, nx}, 2 });
		}
	}
}

int main(void)
{
	memset(arr, -1, sizeof(arr));

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	q.push({ { 1, 2 }, 0 });

	BFS();

	cout << cnt << "\n";
}