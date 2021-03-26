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

queue<pair<int, int>> q;

void BFS()
{
	memset(visit, 0, sizeof(visit));
	q.push(make_pair(0, 0));
	visit[0][0] = 1;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (visit[ny][nx] == 1)
				continue;

			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
			{
				if (arr[ny][nx] == 0)
				{
					q.push(make_pair(ny, nx));
					visit[ny][nx] = 1;
				}
				else
				{
					cheese[cnt]++;
					arr[ny][nx] = 0;
					visit[ny][nx] = 1;
				}
			}
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
		BFS();

		//cout << endl;
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << visit[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		//cout << "시행 : " << cnt << "\t치즈 수 : " << cheese[cnt] << endl;

		//

		if (cheese[cnt] == 0)
			break;

		cnt++;
	}

	cout << cnt << endl << cheese[cnt - 1] << endl;
}