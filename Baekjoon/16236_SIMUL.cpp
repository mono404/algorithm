#include<iostream>
#include<queue>
#include<deque>
#include<cstring>

using namespace std;

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };

bool check;
int n, ans, t, sharksize, feedcnt;
int arr[22][22];
int visit[22][22];
pair<int, int> shark;
deque<pair<int, int>> q;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a < b;
}

pair<int, int> BFS()
{
	while (!q.empty())
	{
		t++;
		int qsize = q.size();
		sort(q.begin(), q.end(), cmp);
		for (int k = 0; k < qsize; k++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop_front();

			if (arr[cy][cx] < sharksize && arr[cy][cx] != 0)
			{
				check = true;
				feedcnt++;
				if (feedcnt == sharksize)
				{
					sharksize++;
					feedcnt = 0;
				}
				arr[cy][cx] = 0;

				ans += t;
				q = deque<pair<int, int>>();
				return { cy, cx };
			}			

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (arr[ny][nx] == -1 || visit[ny][nx] == 1)
					continue;

				if (arr[ny][nx] <= sharksize)
				{
					visit[ny][nx] = 1;
					q.push_back({ ny, nx });
				}

				//if (arr[ny][nx] < sharksize && arr[ny][nx] != 0)
				//{
				//	check = true;
				//	feedcnt++;
				//	if (feedcnt == sharksize)
				//	{
				//		sharksize++;
				//		feedcnt = 0;
				//	}
				//	arr[ny][nx] = 0;

				//	ans += t;
				//	q = deque<pair<int, int>>();
				//	return { ny, nx };
				//}
				//else if (arr[ny][nx] == 0 || arr[ny][nx] == sharksize)
				//{
				//	visit[ny][nx] = 1;
				//	q.push_back({ ny, nx });
				//}
				//else if (arr[ny][nx] == sharksize)
				//{
				//	q.push_back({ ny, nx });
				//}
			}
		}
	}

	return { 0, 0 };
}

int main(void)
{
	memset(arr, -1, sizeof(arr));

	sharksize = 2;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				visit[i][j] = 1;
				arr[i][j] = 0;
				q.push_back({ i, j });
			}
		}
	}
	pair<int, int> res = { 0, 0 };
	while (1)
	{
		t = -1;
		res = BFS();
		if (res.first == 0 && res.second == 0)
		{
			cout << ans << endl;
			return 0;
		}
		else
		{
			memset(visit, 0, sizeof(visit));
			visit[res.first][res.second] = 1;
			q.push_back(res);
		}
	}
}