#include<iostream>
#include<algorithm>

using namespace std;

int n, res;
int arr[301];
int dp[305];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j <= i; j++)
	//	{
	//		dp[i][j] = arr[i];
	//	}
	//}

	dp[0] = 10;
	dp[1] = max(arr[1], arr[0] + arr[1]);
	dp[2] = max(dp[0] + arr[2], dp[1] + arr[2]);

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	std::cout << dp[n - 1];
}