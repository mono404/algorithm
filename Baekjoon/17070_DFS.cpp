#include<iostream>

using namespace std;

int dy[3] = { 0,1,1 };
int dx[3] = { 1,0,1 };

int n, cnt, state;
int arr[18][18];
int visit[18][18];

void DFS(int y, int x, int s)
{
	int ny;
	int nx;

	if (y == n && x == n)
	{
		cnt++;
		return;
	}

	if (s == 0)
	{
		ny = y + dy[0];
		nx = x + dx[0];
		
		if (arr[ny][nx] == 0)
		{
			visit[ny][nx] = 1;
			DFS(ny, nx, 0);
			visit[ny][nx] = 0;
		}
	}
	else if (s == 1)
	{
		ny = y + dy[1];
		nx = x + dx[1];

		if (arr[ny][nx] == 0)
		{
			visit[ny][nx] = 1;
			DFS(ny, nx, 1);
			visit[ny][nx] = 0;
		}
	}
	else if (s == 2)
	{
		ny = y + dy[0];
		nx = x + dx[0];

		if (arr[ny][nx] == 0)
		{
			visit[ny][nx] = 1;
			DFS(ny, nx, 0);
			visit[ny][nx] = 0;
		}

		ny = y + dy[1];
		nx = x + dx[1];

		if (arr[ny][nx] == 0)
		{
			visit[ny][nx] = 1;
			DFS(ny, nx, 1);
			visit[ny][nx] = 0;
		}
	}

	int c = 0;
	for (int i = 0; i < 3; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (arr[ny][nx] == 0)
			c++;
	}

	if (c == 3)
	{
		ny = y + dy[2];
		nx = x + dx[2];

		if (arr[ny][nx] == 0)
		{
			visit[ny][nx] = 1;
			DFS(ny, nx, 2);
			visit[ny][nx] = 0;
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

	visit[1][1] = 1;
	visit[1][2] = 1;
	DFS(1, 2, 0);

	cout << cnt << "\n";
}