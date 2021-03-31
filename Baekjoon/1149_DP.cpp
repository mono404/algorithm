#include<iostream>

using namespace std;

int n;
int dp[1000001];

int main(void)
{
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 10007;
	}

	cout << dp[n] << endl;
}