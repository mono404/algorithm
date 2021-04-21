#include<iostream>
#include<cstring>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

typedef struct passenger {
	int departure_r = 0;
	int departure_c = 0;
	int arrival_r = 0;
	int arrival_c = 0;
} passenger;

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };

int n, m, f, r, c, dist, pcnt;
int arr[22][22];
int visit[22][22];
vector<passenger> v;
deque<pair<int, int>> q;
vector<passenger>::iterator it;

bool qcmp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int BFS(int pnum)
{
	while (!q.empty())
	{
		if (f < 0)
			return -2;

		sort(q.begin(), q.end(), qcmp);

		int qsize = q.size();
		for (int k = 0; k < qsize; k++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop_front();

			if (pnum == -1)
			{
				//for (int i = 0; i < v.size(); i++)
				//{
				//	int dest_y = v[i].departure_r;
				//	int dest_x = v[i].departure_c;

				//	if (cy == dest_y && cx == dest_x)
				//	{
				//		q.clear();
				//		q.push_back({ cy, cx });
				//		return i;
				//	}
				//}

				for (it = v.begin(); it != v.end(); it++)
				{
					int dest_y = it->departure_r;
					int dest_x = it->departure_c;

					if (cy == dest_y && cx == dest_x)
					{
						q.clear();
						q.push_back({ cy, cx });
						return 1;
					}
				}
			}
			else
			{
				int dest_y = it->arrival_r;
				int dest_x = it->arrival_c;

				if (cy == dest_y && cx == dest_x)
				{
					f += dist * 2;
					pcnt++;
					q.clear();
					q.push_back({ cy, cx });

					v.erase(it);

					return -1;
				}
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (arr[ny][nx] == -1 || visit[ny][nx] > 0 || arr[ny][nx] == 1)
					continue;

				visit[ny][nx] = dist;
				q.push_back({ ny, nx });
			}
		}
		f--;
		dist++;
	}

	return -2;
}

int main(void)
{
	memset(arr, -1, sizeof(arr));

	cin >> n >> m >> f;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> r >> c;
	q.push_back({ r, c });

	for (int i = 0; i < m; i++)
	{
		int dep_r, dep_c, ari_r, ari_c;
		cin >> dep_r >> dep_c >> ari_r >> ari_c;
		v.push_back({ dep_r, dep_c, ari_r, ari_c });
	}

	int res = -1;
	while (1)
	{
		memset(visit, 0, sizeof(visit));
		visit[q.front().first][q.front().second] = 1;
		dist = 0;

		res = BFS(res);

		if (res == -2)
		{
			cout << -1 << endl;
			return 0;
		}

		if (v.size() == 0)
		{
			cout << f << endl;
			return 0;
		}
	}
}