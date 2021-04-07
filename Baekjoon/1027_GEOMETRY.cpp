#include<iostream>
#include<vector>

using namespace std;

int n;
vector<long double> v;
long double arr[51];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		long double lmax = -1000000000, rmax = -1000000000;

		for (int j = i - 1; j >= 0; j--)
		{
			if ((v[j] - v[i]) / abs(i - j) > lmax)
			{
				lmax = (v[j] - v[i]) / abs(i - j);
				arr[i]++;
			}
		}
		for (int j = i + 1; j < n; j++)
		{
			if ((v[j] - v[i]) / abs(j - i) > rmax)
			{
				rmax = (v[j] - v[i]) / abs(j - i);
				arr[i]++;
			}
		}
	}

	long double ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (ans < arr[i])
			ans = arr[i];
	}
	cout << ans << "\n";
}