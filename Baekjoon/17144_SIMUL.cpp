#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int R, C, T;
int arr[52][52];
int tmp[52][52];
vector<pair<int, int>> v;

void spread()
{
	memset(tmp, 0, sizeof(tmp));

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			int dust = arr[i][j];
			for (int k = 0; k < 4; k++)
			{
				int nr = i + dy[k];
				int nc = j + dx[k];

				if (arr[nr][nc] == -1)
					continue;

				tmp[nr][nc] += dust / 5;
				arr[i][j] -= dust / 5;
			}
		}
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			arr[i][j] += tmp[i][j];
		}
	}
}

void activate(int idx)
{
	if (idx == 0)
	{
		for (int i = v[idx].first - 1; i > 1; i--)
			arr[i][1] = arr[i - 1][1];

		for (int i = 1; i <= C - 1; i++)
			arr[1][i] = arr[1][i + 1];

		for (int i = 1; i <= v[idx].first - 1; i++)
			arr[i][C] = arr[i + 1][C];

		for (int i = C; i > 2; i--)
			arr[v[idx].first][i] = arr[v[idx].first][i - 1];

		arr[v[idx].first][2] = 0;
	}
	else if (idx == 1)
	{
		for (int i = v[idx].first + 1; i <= R - 1; i++)
			arr[i][1] = arr[i + 1][1];

		for (int i = 1; i <= C - 1; i++)
			arr[R][i] = arr[R][i + 1];

		for (int i = R; i >= v[idx].first + 1; i--)
			arr[i][C] = arr[i - 1][C];

		for (int i = C; i > 2; i--)
			arr[v[idx].first][i] = arr[v[idx].first][i - 1];

		arr[v[idx].first][2] = 0;
	}
}

int main(void)
{
	memset(arr, -1, sizeof(arr));

	cin >> R >> C >> T;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				v.push_back({ i, j });
		}
	}

	for (int t = 0; t < T; t++)
	{
		spread();
		activate(0);
		activate(1);
	}

	int ans = 0;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (arr[i][j] == -1)
				continue;

			ans += arr[i][j];
		}
	}

	cout << ans << "\n";
}