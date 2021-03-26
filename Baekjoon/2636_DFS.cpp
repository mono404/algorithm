#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int m, n, cnt;
int arr[101][101];
int visit[101][101];
int cheese[11];

void DFS(int y, int x)
{
	visit[y][x] = 1;
	if (arr[y][x] == 1)
	{
		cheese[cnt]++;
		arr[y][x] = 0;
		visit[y][x] = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n)
		{
			if (visit[ny][nx] == 1)
				continue;


			DFS(ny, nx);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (;;)
	{
		memset(visit, 0, sizeof(visit));
		DFS(0, 0);

		if (cheese[cnt] == 0)
			break;

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		//cout << endl;

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << visit[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		cnt++;
	}

	cout << cnt << endl << cheese[cnt - 1] << endl;
}