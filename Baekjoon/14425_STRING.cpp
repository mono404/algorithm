#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, cnt;
vector<string> s;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		s.push_back(input);
	}

	sort(s.begin(), s.end());

	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;

		if (*lower_bound(s.begin(), s.end(), input) == input)
			cnt++;
	}

	cout << cnt << "\n";
}