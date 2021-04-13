#include<iostream>
#include<cstring>
#include<vector>
#include<deque>

using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int n, k, l, d, dir, cnt;
int arr[105][105];
bool check;
vector<pair<int, int>> v;
deque<pair<int, int>> dq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;

		arr[a][b] = 1;
	}

	cin >> l;
	
	for (int i = 0; i < l; i++)
	{
		int a;
		char b;

		cin >> a;
		cin >> b;

		if (b == 'D')
			b = 1;
		else if(b == 'L')
			b = -1;

		v.push_back({ a, b });
	}

	dir = 0;
	d = 0;
	dq.push_back({ 1, 1 });

	for (;;)
	{
		cnt++;

		check = true;

		int ny = dq.back().first + dy[d];
		int nx = dq.back().second + dx[d];

		if (ny > 0 && ny <= n && nx > 0 && nx <= n)
		{
			for (int i = 0; i < dq.size(); i++)
			{
				if (ny == dq[i].first && nx == dq[i].second)
				{
					check = false;
				}
			}
			if (check == false)
				break;

			if (arr[ny][nx] == 1)
			{
				dq.push_back({ ny, nx });
				arr[ny][nx] = 0;
			}
			else
			{
				dq.push_back({ ny, nx });
				dq.pop_front();
			}
		}
		else
			break;

		if (dir < l)
		{
			if (v[dir].first == cnt)
			{
				d = d + v[dir].second;

				if (d > 3)
					d = 0;
				else if (d < 0)
					d = 3;
				dir++;
			}
		}
	}

	cout << cnt << endl;
}