#include<iostream>
#include<deque>

using namespace std;

int k;
deque<int> g[5];//2,6

void recur(int gnum, int rotate, char dir)
{
	if (gnum + 1 < 5 && dir != 'L')
	{
		if (g[gnum][2] != g[gnum + 1][6])
			recur(gnum + 1, rotate * -1, 'R');
	}
	if(gnum - 1 > 0 && dir != 'R')
	{
		if (g[gnum][6] != g[gnum - 1][2])
			recur(gnum - 1, rotate * -1, 'L');
	}

	if (rotate == 1)
	{
		int tmp = g[gnum].back();
		g[gnum].pop_back();
		g[gnum].push_front(tmp);
	}
	else
	{
		int tmp = g[gnum].front();
		g[gnum].pop_front();
		g[gnum].push_back(tmp);
	}
}

int main(void)
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char a;
			cin >> a;
			g[i].push_back(a - '0');
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int gnum, rotate;
		cin >> gnum >> rotate;

		recur(gnum, rotate, 'C');
	}

	cout << g[1][0] + (g[2][0] * 2) + (g[3][0] * 4) + (g[4][0] * 8) << endl;
}