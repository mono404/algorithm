#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void calc();
void DFS(int cnt);

int n, res = 999;
int arr[22][22];
int order[21];
int Select[21];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	DFS(0);

	cout << res << endl;
}

void DFS(int cnt)
{
	if (cnt == n / 2)
	{
		calc();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (order[i] == 1)
			continue;
		order[i] = 1;
		DFS(cnt + 1);
		order[i] = 0;
		
	}
}

void calc()
{
	int start_sum = 0;
	int link_sum = 0;
	int diff;
	vector<int> start;
	vector<int> link;

	for (int i = 0; i < n; i++)
	{
		if (order[i] == 0)
			start.push_back(i);
		else
			link.push_back(i);
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			if (i == j)
				continue;

			start_sum += arr[start[i]][start[j]];
			link_sum += arr[link[i]][link[j]];
		}
	}
	diff = abs(start_sum - link_sum);

	if (res < diff)
		res = diff;
}