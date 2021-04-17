#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int n, m, k, ans;
int a[11][11];
int g[11][11];
deque<int> tree[11][11];

void spring_summer(int y, int x)
{
	int dsize = tree[y][x].size();
	auto it = tree[y][x].begin();
	int die = 0;
	for (int i = 0; i < dsize; i++)
	{
		if (tree[y][x][i] <= g[y][x])
		{
			g[y][x] -= tree[y][x][i];
			tree[y][x][i]++;
			it++;
		}
		else
		{
			die += tree[y][x][i] / 2;
		}
	}
	g[y][x] += die;
	tree[y][x].erase(it, tree[y][x].end());

	//for (auto it = tree[y][x].begin(); it != tree[y][x].end();)
	//{
	//	if (*it <= g[y][x])
	//	{
	//		g[y][x] -= *it;
	//		(*it)++;
	//		it++;
	//	}
	//	else
	//	{
	//		g[y][x] += *it / 2;
	//		it = tree[y][x].erase(it);
	//	}
	//}
}

void fall(int y, int x)
{
	int dsize = tree[y][x].size();
	for (int i = 0; i < dsize; i++)
	{
		if (tree[y][x][i] % 5 == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny > 0 && ny <= n && nx > 0 && nx <= n)
					tree[ny][nx].push_front(1);
			}
		}
	}
}

void winter(int y, int x)
{
	g[y][x] += a[y][x];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			g[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	for (int l = 0; l < k; l++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				spring_summer(i, j);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				fall(i, j);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				winter(i, j);
		}
	}

	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans += tree[i][j].size();
		}
	}

	cout << ans << "\n";
}