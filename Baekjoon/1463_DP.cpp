#include<iostream>

using namespace std;

int n, cnt;
int dp[1000001];

int main(void)
{
	cin >> n;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	//for(int i = 0; i <= n; i++)
	//	cout << i << " : " << dp[i] << "\n";
	cout << dp[n] << "\n";
}