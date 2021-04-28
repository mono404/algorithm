#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

int n, m, cnt;
unordered_set<string> s;

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
		s.insert(input);
	}

	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;

		if (s.find(input) != s.end())
			cnt++;
	}

	cout << cnt << "\n";
}