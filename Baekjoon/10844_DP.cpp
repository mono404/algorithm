#include<iostream>

using namespace std;

long long n, ans;
long long dp[102][11];

int main(void)
{
	cin >> n;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 1; i < 10; i++)
		ans += dp[n][i];

	cout << ans % 1000000000 << endl;
}