#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int n, m, ans = 999999999, res, sum;
int arr[52][52];
int visit[52][52];
bool check;

queue<pair<int, int>> q;
vector<pair<int, int>> house;
vector<pair<int, int>> chick;
vector<int> pick;

int main(void)
{
	memset(arr, -1, sizeof(arr));
	memset(visit, 0, sizeof(visit));

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				house.push_back({ i, j });
			else if (arr[i][j] == 2)
				chick.push_back({ i, j });
		}
	}

	for (int i = 0; i < chick.size(); i++)
	{
		if (i < m)
			pick.push_back(1);
		else
			pick.push_back(0);
	}

	sort(pick.begin(), pick.end());

	do {
		res = 999999999;
		sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			res = 999999999;
			for (int j = 0; j < chick.size(); j++)
			{
				if (pick[j] == 1)
				{
					res = min(abs(chick[j].first - house[i].first) + abs(chick[j].second - house[i].second), res);
				}
			}
			sum += res;
		}

		if (ans > sum)
			ans = sum;
	} while (next_permutation(pick.begin(), pick.end()));

	cout << ans << endl;
}