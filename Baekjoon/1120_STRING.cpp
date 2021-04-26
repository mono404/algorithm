#include<iostream>

using namespace std;

string a, b;

int compare(string a, string b, int s)
{
	int cnt = 0;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == b[i + s])
			cnt++;
	}

	return cnt;
}

int main(void)
{
	cin >> a >> b;

	int i, max_value = 0, p = 0;
	for (i = 0; i <= b.size() - a.size(); i++)
	{
		int res = compare(a, b, i);
		if (max_value < res)
		{
			max_value = res;
			p = i;
		}
	}

	string front = b.substr(0, p);
	string back = b.substr(a.size() + front.size(), b.size());
	string ans = front + a + back;

	cout << b.size() - compare(ans, b, 0) << endl;
}