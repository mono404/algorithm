#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int R, C, K, rmax, cmax, idx, vmax;
int arr[101][101];
int cnt[101];
map<int, int> m;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

void Roper()
{
	for (int i = 0; i < rmax; i++)
	{
		m.clear();

		for (int j = 0; j < cmax; j++)
		{
			if (arr[i][j] == 0)
				continue;

			m[arr[i][j]]++;
		}

		vector<pair<int, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), cmp);

		cmax = max(cmax, (int)(v.size() * 2));
		cmax = min(cmax, 100);

		auto it = v.begin();
		for (int j = 0; j < cmax; j++)
		{
			if (it != v.end())
			{
				if (j % 2 == 0)
					arr[i][j] = it->first;
				else
				{
					arr[i][j] = it->second;
					it++;
				}
			}
			else
				arr[i][j] = 0;
		}
	}
}

void Coper()
{
	for (int i = 0; i < cmax; i++)
	{
		m.clear();

		for (int j = 0; j < rmax; j++)
		{
			if (arr[j][i] == 0)
				continue;

			m[arr[j][i]]++;
		}

		vector<pair<int, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), cmp);

		rmax = max(rmax, (int)(v.size() * 2));
		rmax = min(rmax, 100);

		auto it = v.begin();
		for (int j = 0; j < rmax; j++)
		{
			if (it != v.end())
			{
				if (j % 2 == 0)
					arr[j][i] = it->first;
				else
				{
					arr[j][i] = it->second;
					it++;
				}
			}
			else
				arr[j][i] = 0;
		}
	}
}

int main(void)
{
	cin >> R >> C >> K;

	rmax = 3;
	cmax = 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (arr[R - 1][C - 1] == K)
		{
			cout << i << "\n";
			return 0;
		}

		if (rmax >= cmax)
			Roper();
		else
			Coper();
	}

	cout << -1 << "\n";
	return 0;
}