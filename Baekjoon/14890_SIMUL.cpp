#include<iostream>

using namespace std;

int N, L, ans, cnt, xfixSum, yfixSum;
int arr[102][102];
int check[102][102];

int yfixCheck(int n)
{
	cnt = 1;
	for (int i = 0; i < N - 1; i++)
	{
		if (arr[n][i] == arr[n][i + 1]) // 다음 칸이 높이가 같을 때
		{
			cnt++;
			continue;
		}
		else if (arr[n][i] - arr[n][i + 1] == 1) //내려갈 때
		{
			for (int j = i + 1; j <= i + L; j++)
			{
				if (j > N)
					return -1;

				if (arr[n][i + 1] != arr[n][j])
				{
					return -1;
				}
			}
			cnt = 0;
			i = i + L - 1;
			check[n][i] = true;
		}
		else if (arr[n][i] - arr[n][i + 1] == -1) // 올라갈 때
		{
			if (cnt < L)
			{
				return -1;
			}
			cnt = 1;
		}
		else
			return -1;
	}

	return 1;
}

int xfixCheck(int n)
{
	cnt = 1;
	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i][n] == arr[i + 1][n]) // 다음 칸이 높이가 같을 때
		{
			cnt++;
			continue;
		}
		else if (arr[i][n] - arr[i + 1][n] == 1) //내려갈 때
		{
			for (int j = i + 1; j <= i + L; j++)
			{
				if (j > N)
					return -1;

				if (arr[i + 1][n] != arr[j][n])
				{
					return -1;
				}
			}
			cnt = 0;
			i = i + L - 1;
		}
		else if (arr[i][n] - arr[i + 1][n] == -1) // 올라갈 때
		{
			if (cnt < L)
			{
				return -1;
			}
			cnt = 1;
		}
		else
			return -1;
	}

	return 1;
}

int main(void)
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (xfixCheck(i) == 1)
			xfixSum++;
	}
	for (int i = 0; i < N; i++)
	{
		if (yfixCheck(i) == 1)
			yfixSum++;
	}
	ans = xfixSum + yfixSum;
	cout << ans << "\n";
}