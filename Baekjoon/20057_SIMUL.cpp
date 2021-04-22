#include<iostream>
#include<cstring>

using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };

//double ratio[4][5][5] = {
//	{
//		{ 0, 0, 0.02, 0, 0},
//		{ 0, 0.1, 0.07, 0.01, 0},
//		{ 0.05, 0, 0, 0, 0},
//		{ 0, 0.1, 0.07, 0.01, 0},
//		{ 0, 0, 0.02, 0, 0}
//	},
//	{
//		{ 0, 0, 0, 0, 0},
//		{ 0, 0.01, 0, 0.01, 0},
//		{ 0.02, 0.07, 0, 0.07, 0.02},
//		{ 0, 0.1, 0, 0.1, 0},
//		{ 0, 0, 0.05, 0, 0}
//	},
//	{
//		{ 0, 0, 0.02, 0, 0},
//		{ 0, 0.01, 0.07, 0.1, 0},
//		{ 0, 0, 0, 0, 0.05},
//		{ 0, 0.01, 0.02, 0.1, 0},
//		{ 0, 0, 0.07, 0, 0}
//	},
//	{
//		{ 0, 0, 0.05, 0, 0},
//		{ 0, 0.1, 0, 0.1, 0},
//		{ 0.02, 0.07, 0, 0.07, 0.02},
//		{ 0, 0.01, 0, 0.01, 0},
//		{ 0, 0, 0, 0, 0}
//	}
//};

int ratio[4][5][5] = {
	{
		{ 0,  0,  2,  0,  0},
		{ 0, 10,  7,  1,  0},
		{ 5,  0,  0,  0,  0},
		{ 0, 10,  7,  1,  0},
		{ 0,  0,  2,  0,  0}
	},
	{
		{ 0,  0,  0,  0, 0},
		{ 0,  1,  0,  1, 0},
		{ 2,  7,  0,  7, 2},
		{ 0, 10,  0, 10, 0},
		{ 0,  0,  5,  0, 0}
	},
	{
		{ 0,  0,  2,  0,  0},
		{ 0,  1,  7, 10,  0},
		{ 0,  0,  0,  0,  5},
		{ 0,  1,  7, 10,  0},
		{ 0,  0,  2,  0,  0}
	},
	{
		{ 0,  0,  5,  0,  0},
		{ 0, 10,  0, 10,  0},
		{ 2,  7,  0,  7,  2},
		{ 0,  1,  0,  1,  0},
		{ 0,  0,  0,  0,  0}
	}
};

int n, ans;
int arr[510][510];
int visit[510][510];

void spread(int y, int x, int dir)
{
	int posy = y - 2;
	int posx = x - 2;
	int alpha = 0;
	int value = arr[y][x];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 2 && j == 2)
				continue;
			else if (posy + i < 1 || posy + i > n || posx + j < 1 || posx + j > n)
				ans += (value * ratio[dir][i][j]) / 100;
			else
				arr[posy + i][posx + j] += (arr[y][x] * ratio[dir][i][j]) / 100;
			alpha += (arr[y][x] * ratio[dir][i][j]) / 100;
		}
	}
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (ny < 1 || ny > n || nx < 1 || nx > n)
		ans += value - alpha;
	else
		arr[ny][nx] += value - alpha;
	arr[y][x] = 0;
}

void tornado(int y, int x, int dir)
{
	int blow = dir - 1;
	if (blow < 0)
		blow = 3;

	visit[y][x] = 1;

	if (y == n / 2 + 1 && x == n / 2 + 1);
	else
		spread(y, x, dir);


	if (y == 1 && x == 1)
		return;

	int nd = (dir + 1) % 4;

	if (visit[y + dy[nd]][x + dx[nd]] == 0)
		tornado(y + dy[nd], x + dx[nd], nd);
	else
		tornado(y + dy[dir], x + dx[dir], dir);
}

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cy = n / 2 + 1;
	int cx = n / 2 + 1;

	tornado(cy, cx, 3);

	cout << ans << endl;
}