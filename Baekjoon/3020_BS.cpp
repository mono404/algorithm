#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int n, h;
vector<int> v;
vector<int> u;
vector<int> d;
map<int, int> m;

int main(void)
{
	cin >> n;
	cin >> h;


	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (i % 2 == 0)
		{
			u.push_back(a);
		}
		else
		{
			d.push_back(a);
		}
	}

	sort(u.begin(), u.end());
	sort(d.begin(), d.end());

	//for (int i = 0; i < d.size(); i++)
	//	cout << d[i] << " ";
	//cout << endl;
	//for (int i = 0; i < u.size(); i++)
	//	cout << u[i] << " ";
	//cout << endl;

	//cout << lower_bound(d.begin(), d.end(), 1) - d.begin() << " "
	//	<< lower_bound(u.begin(), u.end(), 5) - u.begin()<< " "
	//	<< 14 - (lower_bound(d.begin(), d.end(), 1) - d.begin()) - (lower_bound(u.begin(), u.end(), 5) - u.begin()) << "\n";

	//cout << lower_bound(d.begin(), d.end(), 2) - d.begin() << " "
	//	<< lower_bound(u.begin(), u.end(), 4) - u.begin() << " "
	//	<< 14 - (lower_bound(d.begin(), d.end(), 2) - d.begin()) - (lower_bound(u.begin(), u.end(), 4) - u.begin()) << "\n";

	for (int i = 0; i < h; i++)
	{
		m[n - (lower_bound(d.begin(), d.end(), i + 1) - d.begin())
			- (lower_bound(u.begin(), u.end(), h - i) - u.begin())]++;
	}

	cout << m.begin()->first << " " << m.begin()->second << "\n";
}