#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cstdlib>
#include<ctime>

using namespace std;

int u, v;
double w, cnt, n;
bool check;
map<int, vector<int>> tree;
vector<int> vec[500001];
int water[500002];
int temp[500002];

int main(void)
{
	srand((unsigned int)time(NULL));

	cin >> n >> w;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;

		vec[u].push_back(v);
		vec[v].push_back(u);
		//if (u < v)
		//	vec[u].push_back(v);
		//else
		//	vec[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (vec[i].size() == 1)
			cnt++;
	}

	cout << fixed;
	cout.precision(10);

	cout << w / cnt << "\n";

	return 0;
}