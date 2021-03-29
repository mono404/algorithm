#include<iostream>
#include<vector>

using namespace std;

int n, res;
int arr[501][501];
int dp[501][501];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j - 1 >= 0)
			{
				if (dp[i - 1][j] > dp[i - 1][j - 1])
					dp[i][j] += dp[i - 1][j];
				else
					dp[i][j] += dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] += dp[i - 1][j];
			}			
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		if (res < dp[n - 1][i])
			res = dp[n - 1][i];
	}

	cout << res << endl;
}