#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, t, cnt;
set<int> s;
vector<vector<int>> v(50);

int main(void)
{
	int a, b;
	cin >> n;
	cin >> m;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a;
		s.insert(a);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cin >> b;
			v[i].push_back(b);
		}
	}

	bool check = false;

	for (int i = 0; i < m; i++)
	{
		if (v[i][0] == 999)
			continue;

		check = false;
		for (int j = 0; j < v[i].size(); j++)
		{
			if (s.find(v[i][j]) != s.end())
			{
				check = true;
				break;
			}
		}

		if (check == true)
		{
			for (int j = 0; j < v[i].size(); j++)
				s.insert(v[i][j]);
			
			v[i].clear();
			v[i].push_back(999);

			i = -1;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (v[i][0] == 999)
			continue;

		cnt++;
	}

	cout << cnt << "\n";
}