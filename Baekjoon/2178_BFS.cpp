#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int n, m, cnt;
int arr[102][102];
int visit[102][102];
queue<pair<int, int>> q;

void BFS()
{
	while (!q.empty())
	{
		cnt++;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int cy = q.front().first;
			int cx = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny + 1 == n && nx + 1 == m)
					return;

				if (ny >= 0 && ny < n && nx >= 0 && nx < m)
				{
					if (arr[ny][nx] == 0)
						continue;

					if (visit[ny][nx] == 1)
						continue;

					visit[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main(void)
{
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	q.push({ 0, 0 });
	visit[0][0] = 1;
	BFS();

	cout << cnt + 1 << "\n";
}