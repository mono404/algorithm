#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int n, l, r, cnt, sum, evg, res;
int arr[52][52];
int visit[52][52];
vector<pair<int, int>> v;

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (arr[ny][nx] == -1 || visit[ny][nx] > 0)
			continue;

		if (abs(arr[ny][nx] - arr[y][x]) >= l && abs(arr[ny][nx] - arr[y][x]) <= r)
		{
			visit[ny][nx] = 1;
			sum += arr[ny][nx];
			v.push_back({ ny, nx });
			DFS(ny, nx);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(arr, -1, sizeof(arr));
	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (;;)
	{
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (visit[i][j] == 1)
					continue;

				v.clear();
				visit[i][j] = 1;
				sum = arr[i][j];
				v.push_back({ i, j });
				cnt++;
				DFS(i, j);

				evg = sum / v.size();

				for (int k = 0; k < v.size(); k++)
					arr[v[k].first][v[k].second] = evg;
			}
		}

		if (cnt == n * n)
			break;

		res++;
	}

	cout << res << endl;
}