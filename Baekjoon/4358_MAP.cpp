#include<iostream>
#include<map>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

float cnt;
map<string, float> m;
vector<string> v;

int main(void)
{
	string s;

	//while (getline(cin, s))
	//{
	//	cnt++;
	//	m[s]++;
	//}

	for (int i = 0; i < 29; i++)
	{
		getline(cin, s);
		cnt++;
		m[s]++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << (it->second / cnt) * 100 << "\n";
	}
}