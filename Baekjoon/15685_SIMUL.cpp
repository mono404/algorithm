#include<iostream>
#include<vector>

using namespace std;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

int n, x, y, d, g, cnt;
int arr[102][102];
vector<int> v;

void move()
{
	int vsize = v.size();
	for (int i = vsize - 1; i >= 0; i--)
	{
		int nd = (v[i] + 1) % 4;
		x = x + dx[nd];
		y = y + dy[nd];
		arr[y][x] = 1;

		v.push_back(nd);
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> g;
		
		v.clear();

		arr[y][x] = 1;
		x = x + dx[d];
		y = y + dy[d];
		arr[y][x] = 1;

		v.push_back(d);
		for (int j = 0; j < g; j++)
			move();
	}
	

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1 && arr[i][j + 1] == 1 &&	
				arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1)
				cnt++;
		}
	}
	cout << cnt << "\n";
}