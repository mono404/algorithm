#include<iostream>
#include<unordered_map>

using namespace std;

int m;
string oper;
unordered_map<int, int> s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> oper;

		if (oper.compare(0, 3, "add") == 0)
		{
			int val;
			cin >> val;

			s[val] = 1;
		}
		else if (oper.compare(0, 6, "remove") == 0)
		{
			int val;
			cin >> val;

			s[val] = 0;
		}
		else if (oper.compare(0, 5, "check") == 0)
		{
			int val;
			cin >> val;

			if (s[val] == 0)
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (oper.compare(0, 6, "toggle") == 0)
		{
			int val;
			cin >> val;

			if (s[val] == 0)
				s[val] = 1;
			else
				s[val] = 0;
		}
		else if (oper.compare(0, 3, "all") == 0)
		{
			for (int i = 1; i <= 20; i++)
			{
				s[i] = 1;
			}
		}
		else if (oper.compare(0, 5, "empty") == 0)
		{
			s.clear();
		}
	}
}