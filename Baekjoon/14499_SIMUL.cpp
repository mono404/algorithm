#include<iostream>
#include<vector>

using namespace std;

int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

int n, m, x, y, k;
int arr[21][21];
int dice[4][3], ndice[4][3];
/*
{ 0, 1 } : 0 1 0
{ 1, 0 } : 1 0 0
{ 1, 1 } : 0 1 0
{ 1, 2 } : 0 0 1
{ 2, 1 } : 0 1 0
{ 3, 1 } : 0 1 0
*/

void move(int t)
{
	if (t == 1)
	{
		//ndice[0][1] = dice[0][1];
		ndice[1][1] = dice[1][0];
		ndice[1][2] = dice[1][1];
		ndice[3][1] = dice[1][2];
		//ndice[2][1] = dice[2][1];
		ndice[1][0] = dice[3][1];
	}
	else if (t == 2)
	{
		//ndice[0][1] = dice[0][1];
		ndice[3][1] = dice[1][0];
		ndice[1][0] = dice[1][1];
		ndice[1][1] = dice[1][2];
		//ndice[2][1] = dice[2][1];
		ndice[1][2] = dice[3][1];
	}
	else if (t == 3)
	{
		ndice[3][1] = dice[0][1];
		//ndice[1][0] = dice[1][0];
		ndice[0][1] = dice[1][1];
		//ndice[1][2] = dice[1][2];
		ndice[1][1] = dice[2][1];
		ndice[2][1] = dice[3][1];
	}
	else if (t == 4)
	{
		ndice[1][1] = dice[0][1];
		//ndice[1][0] = dice[1][0];
		ndice[2][1] = dice[1][1];
		//ndice[1][2] = dice[1][2];
		ndice[3][1] = dice[2][1];
		ndice[0][1] = dice[3][1];
	}

	dice[0][1] = ndice[0][1];
	dice[1][0] = ndice[1][0];
	dice[1][1] = ndice[1][1];
	dice[1][2] = ndice[1][2];
	dice[2][1] = ndice[2][1];
	dice[3][1] = ndice[3][1];
}

int main(void)
{
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cy = y;
	int cx = x;

	for (int i = 0; i < k; i++)
	{
		int t;
		cin >> t;

		int ny = cy + dy[t];
		int nx = cx + dx[t];

		if (ny >= 0 && ny < n && nx >= 0 && nx < m)
		{
			cy = ny;
			cx = nx;

			move(t);

			cout << dice[1][1] << endl;

			if (arr[cy][cx] != 0)
			{
				dice[3][1] = arr[cy][cx];
				arr[cy][cx] = 0;
			}
			else if (arr[cy][cx] == 0)
			{
				arr[cy][cx] = dice[3][1];
			}
		}
	}
}