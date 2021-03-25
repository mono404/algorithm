#include<iostream>
#include <queue>
#include<cstring>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m, cnt = 1;
int arr[1001][1001];
int dp[1001][1001];
bool visit[1001][1001][2];

void BFS()
{
	int cy;
	int cx;
	int wall;

	queue < pair< pair<int, int>, int>> q;

	q.push(make_pair(make_pair(1, 1), 0));

	while (!q.empty())
	{
		int q_size = q.size();
		for (int j = 0; j < q_size; j++) {


			cy = q.front().first.first;
			cx = q.front().first.second;
			wall = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (arr[ny][nx] == -1)
					continue;
				if (ny == n && nx == m) {
					dp[ny][nx] = dp[cy][cx] + 1;
					return;
				}

				if (ny >= 1 && ny <= n && nx >= 1 && nx <= m)
				{
					if (arr[ny][nx] == 1)
					{
						if (wall == 1 || visit[ny][nx][1] == 1)
							continue;

						visit[ny][nx][1] = 1;
						q.push({ { ny, nx }, 1 });
						dp[ny][nx] = dp[cy][cx] + 1;
					}
					else
					{
						if (visit[ny][nx][wall] == 1)
							continue;

						visit[ny][nx][wall] = 1;
						q.push({ {ny, nx}, wall });
						dp[ny][nx] = dp[cy][cx] + 1;
					}
				}

				//dp[ny][nx] = dp[cy][cx] + 1;
			}
		}
	}
}

int main(void)
{
	memset(arr, -1, sizeof(arr));
	char input;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{

			cin >> input;
			arr[i][j] = input - 48;
			//dp[i][j][1] = 999;
		}
	}
	//arr[6][4] = 5;
	//for (int i = 0; i <= n+1; i++)
	//{
	//	for (int j = 0; j <= m+1; j++)
	//	{
	//		cout << arr[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	//DFS(6, 4, 0, 1);



	dp[1][1] = 1;
	//dp[1][1][1] = 1;

	BFS();

	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		//cout << dp[i][j] << " ";
	//		cout << visit[i][j][0] << " ";
	//	}
	//	cout << endl;
	//}

	if (dp[n][m] == 0)
		cout << -1 << endl;
	else
		cout << dp[n][m] << endl;
}