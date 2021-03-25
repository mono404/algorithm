#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;

void DFS(int s);

int n, c, cnt;
vector<vector<int>> p(101);
int visit[101];

queue<int> q;

int main(void)
{
	cin >> n;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int a, b;

		cin >> a;
		cin >> b;

		p[a].push_back(b);
		p[b].push_back(a);

		//if (a == 1)
		//	q.push(b);

		//if (b == 1)
		//	q.push(a);
	}

	for (int i = 0; i < p[1].size(); i++)
	{
		q.push(p[1][i]);
	}

	DFS(1);



	//while (!q.empty())
	//{
	//	int a = q.front();
	//	q.pop();
	//	cout << a << endl;
	//}

	cout << cnt << endl;

	return 0;
}

void DFS(int s)
{
	visit[s] = 1;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		if (visit[a] == 1)
			continue;

		visit[a] = 1;
		cnt++;
		for (int i = 0; i < p[a].size(); i++)
		{
			if (visit[p[a][i]] == 1)
				continue;

			q.push(p[a][i]);
		}
	}
}