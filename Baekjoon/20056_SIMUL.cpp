#include<iostream>
#include<cstring>
#include<unordered_set>
#include<vector>
#include<deque>
#include<set>

using namespace std;

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

typedef struct fireball {
	int r = 0;
	int c = 0;
	int m = 0;
	int s = 0;
	int d = 0;
}fireball;

int n, m, K, ans;
vector<fireball> dup[55][55];
vector<fireball> tmp[55][55];

void move(int y, int x)
{
	for (int i = 0; i < dup[y][x].size(); i++)
	{
		int r = dup[y][x][i].r;
		int c = dup[y][x][i].c;
		int m = dup[y][x][i].m;
		int s = dup[y][x][i].s;
		int d = dup[y][x][i].d;

		int ny = r + (dy[d] * (s % n));
		int nx = c + (dx[d] * (s % n));

		if (nx > n)
			nx -= n;
		else if (nx < 1)
			nx += n;
		if (ny > n) 
			ny -= n;
		else if (ny < 1) 
			ny += n;

		tmp[ny][nx].push_back({ ny, nx, m, s, d });
	}
	dup[y][x] = vector<fireball>();;
}

void merge(int y, int x)
{
	int m = 0;
	int s = 0;
	int d = 0;
	bool check = true;
	int size = dup[y][x].size();

	for (int i = 0; i < size; i++)
	{
		m += dup[y][x][i].m;
		s += dup[y][x][i].s;
		if (i > 0 && dup[y][x][i - 1].d % 2 != dup[y][x][i].d % 2)
			check = false;
	}

	m /= 5;
	s /= size;

	dup[y][x] = vector<fireball>();

	if (m == 0)
		return;

	if (check == true)
		d = 0;
	else
		d = 1;

	for (int i = d; i < 8; i += 2)
	{
		dup[y][x].push_back({ y, x, m, s, i });
	}
}

int main(void)
{
	cin >> n >> m >> K;

	for (int i = 0; i < m; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;

		dup[r][c].push_back({ r, c, m, s, d });
	}

	for (int k = 0; k < K; k++)
	{
		int aa = 9;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dup[i][j].size() > 0)
					move(i, j);
			}
		}

		memcpy(dup, tmp, sizeof(dup));
		memset(tmp, 0, sizeof(tmp));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dup[i][j].size() > 1)
					merge(i, j);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dup[i][j].size() == 0)
				continue;

			for (int k = 0; k < dup[i][j].size(); k++)
				ans += dup[i][j][k].m;
		}
	}

	cout << ans << endl;

	return 0;
}