#include<iostream>

using namespace std;

int n, x, y, d1, d2;
int arr[22][22];
int tmp[22][22];

int check()
{
	int area[6] = { 0, };
	int amax = 0, amin = 1000000000;

	for (int r = 1; r <= n; r++)
	{
		for (int c = 1; c <= n; c++)
		{
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x)))
			{
				area[1] += arr[r][c];
				tmp[r][c] = 1;
			}
			else if (r <= x + d2 && y < c && !(r >= x && c <= y + (r - x)))
			{
				area[2] += arr[r][c];
				tmp[r][c] = 2;
			}
			else if (x + d1 <= r && c < y - d1 + d2 && !(r < x + d1 + d2 && c >= (y - d1 + d2) - (x + d1 + d2 - r)))
			{
				area[3] += arr[r][c];
				tmp[r][c] = 3;
			}
			else if (x + d2 < r && y - d1 + d2 <= c && !(r <= x + d1 + d2 && c <= (y - d1 + d2) + (x + d1 + d2 - r)))
			{
				area[4] += arr[r][c];
				tmp[r][c] = 4;
			}
			else
			{
				area[5] += arr[r][c];
				tmp[r][c] = 5;
			}
		}
	}

	//for (int r = 1; r <= n; r++)
	//{
	//	for (int c = 1; c <= n; c++)
	//	{
	//		if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x)))
	//			tmp[r][c] = 1;
	//		else if (r <= x + d2 && y < c && !(r >= x && c <= y + (r - x)))
	//			tmp[r][c] = 2;
	//		else if (x + d1 <= r && c < y - d1 + d2 && !(r < x + d1 +d2 && c >= (y - d1 + d2) - (x + d1 + d2 - r)))
	//			tmp[r][c] = 3;
	//		else if (x + d2 < r && y - d1 + d2 <= c && !(r <= x + d1 + d2 && c <= (y - d1 + d2) + (x + d1 + d2 - r)))
	//			tmp[r][c] = 4;
	//		else
	//			tmp[r][c] = 5;
	//	}
	//}

	//if (x == 2 && y == 4 && d1 == 2 && d2 == 2)
	//{
	//	cout << endl << "x = 2, y = 4, d1 = 2, d2 = 2;" << endl;
	//	for (int i = 1; i <= n; i++)
	//	{
	//		for (int j = 1; j <= n; j++)
	//			cout << tmp[i][j] << " ";
	//		cout << endl;
	//	}
	//}

	//if (x == 2 && y == 5 && d1 == 3 && d2 == 2)
	//{
	//	cout << endl << "x = 2, y = 5, d1 = 3, d2 = 2;" << endl;
	//	for (int i = 1; i <= n; i++)
	//	{
	//		for (int j = 1; j <= n; j++)
	//			cout << tmp[i][j] << " ";
	//		cout << endl;
	//	}
	//}

	//if (x == 4 && y == 3 && d1 == 1 && d2 == 1)
	//{
	//	cout << endl << "x = 4, y = 3, d1 = 1, d2 = 1;" << endl;
	//	for (int i = 1; i <= n; i++)
	//	{
	//		for (int j = 1; j <= n; j++)
	//			cout << tmp[i][j] << " ";
	//		cout << endl;
	//	}
	//}

	//if (x == 3 && y == 3 && d1 == 1 && d2 == 1)
	//{
	//	cout << endl << "x = 3, y = 3, d1 = 1, d2 = 1;" << endl;
	//	for (int i = 1; i <= n; i++)
	//	{
	//		for (int j = 1; j <= n; j++)
	//			cout << tmp[i][j] << " ";
	//		cout << endl;
	//	}
	//}

	for (int i = 1; i <= 5; i++)
	{
		if (amax < area[i])
			amax = area[i];

		if (amin > area[i])
			amin = area[i];
	}

	//if (x == 1 && y == 3 && d1 == 2 && d2 == 3)
	//	int zzz = 123;
	//
	//if (x == 2 && y == 3 && d1 == 1 && d2 == 2)
	//	int zzz = 123;

	//cout << endl << "x = " << x << ", y = " << y << ", d1 = " << d1 << ", d2 = " << d2 << endl;
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= n; j++)
	//		cout << tmp[i][j] << " ";
	//	cout << endl;
	//}
	//cout << amax << " - " << amin << " = " << amax - amin << endl;


	return (amax - amin);
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

	int ans = 1000000000;

	for (x = 1; x <= n; x++)
	{
		for (y = 1; y <= n; y++)
		{
			for (d1 = 1; d1 <= n; d1++)
			{
				for (d2 = 1; d2 <= n; d2++)
				{
					if (x + d1 + d2 <= n && 1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= n)
					{
						ans = min(check(), ans);
					}
				}
			}
		}
	}

	cout << ans << "\n";
}