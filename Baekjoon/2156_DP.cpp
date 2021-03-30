#include<iostream>

using namespace std;

int n, res;
int arr[10005];
int dp[10005];

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = max(arr[1] + arr[2], arr[2]);
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	//dp[4] = max(dp[1] + arr[3] + arr[4], max(dp[1] + arr[4], dp[2] + arr[4]));
	//dp[4] = max(dp[1] + arr[4], dp[2] + arr[4], dp[1] + arr[3] + arr[4]);
	//dp[5] = max(dp[1] + arr[5], dp[2] + arr[5], dp[3] + arr[5], dp[2] + arr[4] + arr[5]);

	for (int i = 4; i <= n; i++)
	{
		int m;

		for (int j = 1; j <= i - 2; j++)
		{
			if(j > 1)
				dp[i] = max(dp[j] + arr[i], max(dp[j - 1] + arr[i - 1] + arr[i] , dp[j - 2] + arr[i - 1] + arr[i]));
			else
				dp[i] = max(dp[j] + arr[i], dp[j - 1] + arr[i - 1] + arr[i]);

		}

		//dp[i] = max(dp[i - ] + arr[i], max(dp[j - 1] + arr[i - 1] + arr[i], dp[i]));
		//dp[i] = max(m, dp[i - 3] + arr[i - 1] + arr[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		//cout << dp[i] << " ";
		res = max(res, dp[i]);
	}
	//cout << endl;

	cout << res << endl;
}