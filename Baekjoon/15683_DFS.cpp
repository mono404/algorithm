#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

// 0 : 왼쪽, 1 : 아래, 2 : 오른쪽, 3 : 위
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int n, m, cnt, res, zcnt, answer;
int arr[10][10];
int visit[10][10];
int tmp[9][10][10];
vector<pair<int, pair<int, int>>> v;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.first > b.first;
}

int check(pair<int, int> p, int dir)
{
	int ny = p.first + dy[dir];
	int nx = p.second + dx[dir];
	int out = 0;

	if (arr[ny][nx] == -1 || arr[ny][nx] == 6)
	{
		return 0;
	}
	else if(arr[ny][nx] == 0 && visit[ny][nx] == 0)
	{
		out++;
		visit[ny][nx] = 1;
		out += check({ ny, nx }, dir);
		//visit[ny][nx] = 0;
	}
	else if (arr[ny][nx] >= 0 && arr[ny][nx] < 6)
	{
		out = check({ ny, nx }, dir);
	}

	return out;
}

int DFS(int idx)
{
	int out = 0, ans = 0;
	memcpy(tmp[idx], visit, sizeof(visit));
	if (idx == v.size())
	{
		return 0;
	}

	if (v[idx].first == 5)
	{
		out = 0;
		for (int i = 0; i < 4; i++)
			out += check(v[idx].second, i);

		out += DFS(idx + 1);
		ans = out;
	}
	else if (v[idx].first == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			out = 0;
			for (int j = 0; j < 3; j++)
			{
				out += check(v[idx].second, (i + j) % 4);
			}
			ans = max(out + DFS(idx + 1), ans);
			memcpy(visit, tmp[idx], sizeof(visit));
		}
	}
	else if (v[idx].first == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			out = 0;
			for (int j = 0; j < 2; j++)
			{
				out += check(v[idx].second, (i + j) % 4);
			}
			ans = max(out + DFS(idx + 1), ans);
			memcpy(visit, tmp[idx], sizeof(visit));
		}
	}
	else if (v[idx].first == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			out = check(v[idx].second, i);
			out += check(v[idx].second, i + 2);
			ans = max(out + DFS(idx + 1), ans);
			memcpy(visit, tmp[idx], sizeof(visit));
		}
	}
	else if (v[idx].first == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			out = check(v[idx].second, i);
			ans = max(out + DFS(idx + 1), ans);
			memcpy(visit, tmp[idx], sizeof(visit));
		}
	}

	return ans;
}

int main(void)
{
	//for (;;)
	//{
		memset(arr, -1, sizeof(arr));
		cin >> n >> m;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 0)
					zcnt++;
				else if (arr[i][j] > 0 && arr[i][j] < 6)
				{
					v.push_back({ arr[i][j], { i, j} });
				}
			}
		}

		sort(v.begin(), v.end(), cmp);

		answer = DFS(0);

		//cout << check(v[0].second, 3);

		//cout << zcnt << " " << answer  << " " << answer << endl;

		cout << zcnt - answer << endl;
	//}
}