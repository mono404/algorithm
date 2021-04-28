#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int n, m, cnt;
unordered_map<char, vector<string>> s;

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		s[input[0]].push_back(input);
	}

	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;

		for (int i = 0; i < s[input[0]].size(); i++)
		{
			if (s[input[0]][i].compare(0, input.size(), input) == 0)
			{
				cnt++;
				break;
			}
		}
	}

	cout << cnt << "\n";
}