#include<iostream>
#include <bitset>

using namespace std;

int m;
string oper;
unsigned int bits;

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

			bits |= 1 << val;

			cout << bitset<21>(bits) << "\n";
		}
		else if (oper.compare(0, 6, "remove") == 0)
		{
			int val;
			cin >> val;

			int a = 0;
			int b = 0;

			bits &= ~(1 << val);
			cout << bitset<21>(bits) << "\n";
		}
		else if (oper.compare(0, 5, "check") == 0)
		{
			int val;
			cin >> val;

			if (bits & (1 << val))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (oper.compare(0, 6, "toggle") == 0)
		{
			int val;
			cin >> val;

			if (bits & (1 << val))
				bits &= ~(1 << val);
			else
				bits |= (1 << val);

			cout << bitset<21>(bits) << "\n";
		}
		else if (oper.compare(0, 3, "all") == 0)
		{
			int val = 0;

			bits |= ~val;

			cout << bitset<21>(bits) << "\n";
		}
		else if (oper.compare(0, 5, "empty") == 0)
		{
			int val = 0;

			bits &= val;

			cout << bitset<21>(bits) << "\n";
		}
	}
}