#include<iostream>
#include<vector>

using namespace std;

int n, ans;
int arr[1001];
int ldp[1001];
int rdp[1001];

vector<int> v;

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[j] < arr[i])
				ldp[i] = max(ldp[i], ldp[j]);
		}
		ldp[i]++;

		for (int j = (n - i) + 1; j <= n; j++)
		{
			if (arr[j] < arr[n - i])
				rdp[n - 1] = max(rdp[n - 1], rdp[j]);
		}
		rdp[n - 1]++;
	}

	//for (int i = n; i > 0; i--)
	//{
	//	for (int j = i + 1; j <= n; j++)
	//	{
	//		if (arr[j] < arr[i])
	//			rdp[i] = max(rdp[i], rdp[j]);
	//	}
	//	rdp[i]++;
	//}

	for (int i = 1; i <= n; i++)
	{
		if (i == 0)
		{
			ans = max(ans, rdp[i]);
		}
		else if (i == n - 1)
		{
			ans = max(ans, ldp[i]);
		}
		else
		{
			ans = max(ans, rdp[i] + ldp[i] - 1);
		}
	}

	cout << ans << "\n";
}