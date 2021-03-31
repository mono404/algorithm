#include<iostream>

using namespace std;

string str1, str2;
int dp[1002][1002];

int main(void)
{
	cin >> str1;
	cin >> str2;

	//if (str1[0] == str2[0])
	//{
	//	for (int i = 1; i <= str1.size(); i++)
	//		dp[1][i] = 1;

	//	for (int i = 1; i <= str2.size(); i++)
	//		dp[i][1] = 1;
	//}

	for (int i = 0; i < str2.size(); i++)
	{
		for (int j = 0; j < str1.size(); j++)
		{
			if (str1[j] == str2[i])
			{
				if (j == 0)
					dp[i + 1][j + 1]++;
				else
					dp[i + 1][j + 1] = dp[i][j] +1;
					

				if (dp[i + 1][j + 1] > i + 1)
					dp[i + 1][j + 1] = i + 1;

				if (dp[i + 1][j + 1] > j + 1)
					dp[i + 1][j + 1] = j + 1;
			}
			else
			{
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

				if (dp[i + 1][j + 1] > i + 1)
					dp[i + 1][j + 1] = i + 1;

				if (dp[i + 1][j + 1] > j + 1)
					dp[i + 1][j + 1] = j + 1;
			}
		}
	}

	for (int i = 1; i <= str2.size(); i++)
	{
		for (int j = 1; j <= str1.size(); j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	cout << dp[str2.size()][str1.size()] << "\n";
}