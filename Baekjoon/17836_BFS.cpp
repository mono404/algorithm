#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int n, m, t, cnt, res, ans;
int arr[102][102];
int visit[102][102];
queue<pair<int, int>> q;

void BFS()
{
	while (!q.empty())
	{
		cnt++;
		int qsize = q.size();
		for (int k = 0; k < qsize; k++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (visit[ny][nx] > 0)
					continue;

				if (arr[ny][nx] == -1 || arr[ny][nx] == 1)
					continue;

				if (arr[ny][nx] == 2)
				{
					res = cnt + (n - ny) + (m - nx);
					if (res > t)
						res = 0;
				}

				q.push({ ny, nx });
				visit[ny][nx] = cnt;
			}
		}
		if (cnt > t)
			return;
	}
}

int main(void)
{
	memset(arr, -1, sizeof(arr));

	cin >> n;
	cin >> m;
	cin >> t;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	q.push({ 1, 1 });
	visit[1][1] = 1;

	if (arr[1][1] == 2)
		res = cnt + (n - 1) + (m - 1);

	BFS();

	if(visit[n][m] == 0 && res == 0)
		cout << "Fail" << "\n";
	else if (visit[n][m] == 0 && res != 0)
		cout << res << "\n";
	else if (visit[n][m] != 0 && res == 0)
		cout << visit[n][m] << "\n";
	else
	{
		if (visit[n][m] > res)
			cout << res << "\n";
		else
			cout << visit[n][m] << "\n";
	}


	//cout << visit[n][m] << " " << res << endl;
	//if (visit[n][m] == 0)
	//	cout << "Fail" << "\n";
	//else
	//	cout << visit[n][m] << "\n";

	//cout << endl;
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		cout << visit[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}