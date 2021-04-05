#include<iostream>

using namespace std;

int n, k, res;



int main(void)
{
	cin >> n;
	cin >> k;

	int cnt = 0;
	int left = 1;
	int right = k;
	int mid = (right + left) / 2;

	while (left <= right)
	{
		cnt = 0;
		mid = (right + left) / 2;

		for (int i = 1; i <= n; i++)
		{
			//cnt += min(mid / n, i);
			for (int j = 1; j <= n; j++)
			{
				if (i * j <= mid)
					cnt++;
			}
		}

		if (cnt >= k)
		{
			res = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << left << " " << mid << " " << right << " " << res << endl;
}