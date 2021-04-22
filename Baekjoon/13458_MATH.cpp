#include<iostream>

using namespace std;

int n, b, c, ans;
int arr[1000001];

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cin >> b >> c;

	for (int i = 1; i <= n; i++)
	{
		int tmp = arr[i] - b;
		ans++;
		if (tmp <= 0)
		{
			continue;
		}
		else
		{
			if (tmp % c == 0 && tmp / c > 0)
				ans += tmp / c;
			else
				ans += tmp / c + 1;
		}
	}

	cout << ans << endl;
}