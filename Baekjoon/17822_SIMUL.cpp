#include<iostream>
#include<deque>
#include<cstring>

using namespace std;

int n = 1, m, T, x, d, k, ans;
bool check;
deque<double> disk[51];
int tmp[51][51];

void erase()
{
	check = false;
	memset(tmp, 0, sizeof(tmp));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (disk[i][j] != 0)
			{
				if (j == m - 1)
				{
					if (disk[i][m - 1] == disk[i][0])
					{
						tmp[i][0] = 1;
						tmp[i][m - 1] = 1;
						check = true;
					}
				}
				else if (disk[i][j] == disk[i][j + 1])
				{
					tmp[i][j] = 1;
					tmp[i][j + 1] = 1;
					check = true;
				}

				if (i < n)
				{
					if (disk[i][j] == disk[i + 1][j])
					{
						tmp[i][j] = 1;
						tmp[i + 1][j] = 1;
						check = true;
					}
				}
			}
		}
	}

	if (check == true)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tmp[i][j] == 1)
					disk[i][j] = 0;
			}
		}
	}
	else
	{
		double avg = 0, cnt = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (disk[i][j] != 0)
				{
					avg += disk[i][j];
					cnt++;
				}
			}
		}

		avg = avg / cnt;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (disk[i][j] != 0 && disk[i][j] > avg)
				{
					disk[i][j]--;
				}
				else if (disk[i][j] != 0 && disk[i][j] < avg)
				{
					disk[i][j]++;
				}
			}
		}
	}
}

void rotate(int x, int d, int k)
{
	for (int i = 1; i * x <= n; i++)
	{
		if (d == 0)
		{
			for (int j = 0; j < k; j++)
			{
				int tmp;
				tmp = disk[i * x].back();
				disk[i * x].pop_back();
				disk[i * x].push_front(tmp);
			}
		}
		else
		{
			for (int j = 0; j < k; j++)
			{
				int tmp;
				tmp = disk[i * x].front();
				disk[i * x].pop_front();
				disk[i * x].push_back(tmp);
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> T;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			disk[i].push_back(a);
		}
	}


	for (int t = 1; t <= T; t++)
	{
		cin >> x >> d >> k;

		rotate(x, d, k);
		erase();
	}


	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		cout << disk[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans += disk[i][j];
		}
	}

	cout << ans << endl;
}