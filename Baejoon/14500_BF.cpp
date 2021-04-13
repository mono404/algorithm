#include<iostream>

using namespace std;

int n, m, sum;
int arr[520][520];

void check(int y, int x)
{
	// 1번
	sum = max(sum, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3]);
	sum = max(sum, arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x]);

	// 2번
	sum = max(sum, arr[y][x] + arr[y][x + 1] + arr[y + 1][x] + arr[y + 1][x + 1]);
	sum = max(sum, arr[y][x - 1] + arr[y][x] + arr[y + 1][x - 1] + arr[y + 1][x]);

	// 3번
	sum = max(sum, arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1]);
	sum = max(sum, arr[y][x - 2] + arr[y][x - 1] + arr[y][x] + arr[y + 1][x - 2]);
	sum = max(sum, arr[y - 2][x - 1] + arr[y - 2][x] + arr[y - 1][x] + arr[y][x]);
	sum = max(sum, arr[y - 1][x + 2] + arr[y][x] + arr[y][x + 1] + arr[y][x + 2]);

	//3번 대칭
	sum = max(sum, arr[y][x] + arr[y][x + 1] + arr[y + 1][x] + arr[y + 2][x]);
	sum = max(sum, arr[y][x - 2] + arr[y][x - 1] + arr[y][x] + arr[y + 1][x]);
	sum = max(sum, arr[y - 2][x] + arr[y - 1][x] + arr[y][x - 1] + arr[y][x]);
	sum = max(sum, arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 1][x + 2]);

	// 4번
	sum = max(sum, arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x + 1]);
	sum = max(sum, arr[y][x - 1] + arr[y][x] + arr[y + 1][x - 2] + arr[y + 1][x - 1]);
	sum = max(sum, arr[y - 2][x - 1] + arr[y - 1][x - 1] + arr[y - 1][x] + arr[y][x]);
	sum = max(sum, arr[y - 1][x + 1] + arr[y - 1][x + 2] + arr[y][x] + arr[y][x + 1]);

	//4번 대칭
	sum = max(sum, arr[y][x] + arr[y + 1][x - 1] + arr[y + 1][x] + arr[y + 2][x - 1]);
	sum = max(sum, arr[y - 1][x - 2] + arr[y - 1][x - 1] + arr[y][x - 1] + arr[y][x]);
	sum = max(sum, arr[y - 2][x + 1] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y][x]);
	sum = max(sum, arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y + 1][x + 2]);


	// 5번
	sum = max(sum, arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x]);
	sum = max(sum, arr[y][x - 2] + arr[y][x - 1] + arr[y][x] + arr[y + 1][x - 1]);
	sum = max(sum, arr[y - 2][x] + arr[y - 1][x - 1] + arr[y - 1][x] + arr[y][x]);
	sum = max(sum, arr[y - 1][x + 1] + arr[y][x] + arr[y][x + 1] + arr[y][x + 2]);

	//5번 대칭
	sum = max(sum, arr[y][x] + arr[y + 1][x - 1] + arr[y + 1][x] + arr[y + 2][x]);
	sum = max(sum, arr[y - 1][x - 1] + arr[y][x - 2] + arr[y][x - 1] + arr[y][x]);
	sum = max(sum, arr[y - 2][x] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y][x]);
	sum = max(sum, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1]);
}

int main(void)
{
	cin >> n;
	cin >> m;

	for (int i = 3; i <= n + 2; i++)
	{
		for (int j = 3; j <= m + 2; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 3; i <= n + 2; i++)
	{
		for (int j = 3; j <= m + 2; j++)
		{
			check(i, j);
		}
	}

	cout << sum << "\n";
}
