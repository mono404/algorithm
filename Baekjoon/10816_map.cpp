#include<iostream>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

int n, m, nsize;
unordered_map<int, int> nmap;
map<int, int> mmap;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b = 1;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		//nmap[a]++;

		if (!mmap.insert({ a, b }).second)
		{
			//nmap[a]++;
			b++;
			mmap[a] = b;
		}
		else
		{
			b = 1;
		}
	}
	
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		cout << mmap[a] << " ";
	}
}