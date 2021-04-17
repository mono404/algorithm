#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, ans, MIN = 1000000001, MAX;
int arr[12];
int oper[4];
vector<int> pick;

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
		for (int j = 0; j < oper[i]; j++)
		{
			pick.push_back(i);
		}
	}

	sort(pick.begin(), pick.end());

	do {
		ans = arr[0];
		for (int i = 0; i < n - 1; i++)
		{
			if (pick[i] == 0)
			{
				ans = ans + arr[i + 1];
			}
			else if (pick[i] == 1)
			{
				ans = ans - arr[i + 1];
			}
			else if (pick[i] == 2)
			{
				ans = ans * arr[i + 1];
			}
			else if (pick[i] == 3)
			{
				if (ans < 0 && arr[i + 1] > 0)
				{
					ans = abs(ans) / abs(arr[i + 1]);
					ans = ans * -1;
				}
				else
					ans = ans / arr[i + 1];
			}
		}

		MIN = min(ans, MIN);
		MAX = max(ans, MAX);
	} while (next_permutation(pick.begin(), pick.end()));

	cout << MAX << "\n" << MIN << "\n";
}