#include<iostream>
#include<cstring>

using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

typedef struct Ball {
	int y = 0;
	int x = 0;
	bool goal = false;
}Ball;

int n, m, ans = 99;
char arr[10][10];


void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}

void tilt(int dir, int depth)
{
	bool Rcheck = false;
	bool Bcheck = false;

	if (depth == 11)
	{
		return;
	}

	Ball Red, Blue;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'R')
				Red = { i, j, false };
			else if (arr[i][j] == 'B')
				Blue = { i, j, false };
		}
	}

	for (int t = 0; t < 8; t++)
	{
		int Rny = Red.y + dy[dir];
		int Rnx = Red.x + dx[dir];

		int Bny = Blue.y + dy[dir];
		int Bnx = Blue.x + dx[dir];

		if (Bcheck == false)
		{
			if (arr[Bny][Bnx] == 'O')
			{
				Blue.goal = true;
				arr[Blue.y][Blue.x] = '.';
				Bcheck = true;
			}
			else if (arr[Bny][Bnx] == '.')
			{
				arr[Blue.y][Blue.x] = '.';
				Blue.y = Bny;
				Blue.x = Bnx;
				arr[Blue.y][Blue.x] = 'B';
			}
		}

		if (Rcheck == false)
		{
			if (arr[Rny][Rnx] == 'O')
			{
				Red.goal = true;
				arr[Red.y][Red.x] = '.';
				Rcheck = true;
			}
			else if (arr[Rny][Rnx] == '.')
			{
				arr[Red.y][Red.x] = '.';
				Red.y = Rny;
				Red.x = Rnx;
				arr[Red.y][Red.x] = 'R';
			}
		}

		if (Rcheck == true && Bcheck == true)
			break;
	}

	//cout << "\ndir = " << dir << "depth = " << depth << "\n";
	//print();

	if (Blue.goal == false && Red.goal == true)
	{
		ans = min(ans, depth);
		return;
	}
	else if (Blue.goal == true || Red.goal == true)
	{
		return;
	}

	char tmp[10][10];
	memcpy(tmp, arr, sizeof(arr));

	for (int i = 0; i < 4; i++)
	{
		if (i == dir)
			continue;

		tilt(i, depth + 1);
		memcpy(arr, tmp, sizeof(arr));
	}
}

int main(void)
{
	Ball Red, Blue;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char input;
			cin >> input;
			arr[i][j] = input;
			if (input == 'R')
				Red = { i, j, false };
			else if (input == 'B')
				Blue = { i , j, false };
		}
	}


	char tmp[10][10];
	memcpy(tmp, arr, sizeof(arr));

	for (int i = 0; i < 4; i++)
	{
		tilt(i, 1);
		memcpy(arr, tmp, sizeof(arr));
	}

	//print();
	//tilt(2, 2);
	//print();

	if (ans == 99)
		ans = -1;

	cout << ans << endl;
}
/*
##########
#R.......#
#######.##
#.....#.B#
#.....#O##
##########
*/