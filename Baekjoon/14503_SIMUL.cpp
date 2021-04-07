#include<iostream>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int n, m, r, c, d, k, cnt;
int arr[51][51];
int visit[51][51];
int cx, cy, nx, ny;
bool check;

void simul()
{
	cnt++;
	visit[cy][cx] = 1;

	for (;;)
	{
		k = d;
		int i = 0;
		for (i = 0; i < 4; i++)
		{
			k--;
			if (k < 0)
				k = 3;

			ny = cy + dy[k];
			nx = cx + dx[k];

			if (arr[ny][nx] == 0 && visit[ny][nx] == 0)
			{
				visit[ny][nx] = 1;
				cnt++;
				cy = ny;
				cx = nx;
				d = k;
				check = true;
				break;
			}
		}

		if (i == 4)
		{
			//d++;
			if (d > 3)
				d = 0;

			ny = cy - dy[d];
			nx = cx - dx[d];

			if (arr[ny][nx] == 1)
				break;
			else
			{
				cy = ny;
				cx = nx;
			}
		}
	}
}

int main(void)
{
	fill(&arr[0][0], &arr[50][51], 1);
	cin >> n;
	cin >> m;
	cin >> r;
	cin >> c;
	cin >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	//for (int i = 0; i <= n + 1; i++)
	//{
	//	for (int j = 0; j <= m + 1; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	cy = r;
	cx = c;

	simul();

	cout << cnt << "\n";
}