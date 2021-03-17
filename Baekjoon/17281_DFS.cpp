#include<iostream> 
#include<algorithm>
#include<cstring>

using namespace std;

void DFS(int n);
void play(void);

int inning;
int res[51][10];
int order[10] = { 0, };
int lineup[10];
int ans = 0;

int main(void)
{
	cin >> inning;

	for (int i = 0; i < inning; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> res[i][j];
		}
	}

	order[3] = 1;
	lineup[3] = 0;

	DFS(1);

	cout << ans << endl;
}

void DFS(int n)
{
	if (n == 9)
	{
		play();
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (order[i] == 1)
			continue;
		order[i] = 1;
		lineup[i] = n;
		DFS(n + 1);
		order[i] = 0;
	}
}

void play()
{
	int point = 0;
	int base[5] = { 0, };
	int player = 0;

	for (int i = 0; i < inning; i++)
	{
		int outcnt = 0;
		int next = 0;
		memset(base, 0, sizeof(base));

		for(;;)
		{
			for (int j = player; j < 9; j++)
			{
				if (res[i][lineup[j]] == 0)
				{
					outcnt++;
				}
				else if (res[i][lineup[j]] == 1)
				{
					base[4] += base[3];
					base[3] = 0;

					base[3] += base[2];
					base[2] = 0;

					base[2] += base[1];
					base[1] = 0;

					base[1] = 1;
				}
				else if (res[i][lineup[j]] == 2)
				{
					base[4] += base[3];
					base[3] = 0;

					base[4] += base[2];
					base[2] = 0;

					base[3] += base[1];
					base[1] = 0;

					base[2] = 1;
				}
				else if (res[i][lineup[j]] == 3)
				{
					base[4] += base[3];
					base[3] = 0;

					base[4] += base[2];
					base[2] = 0;

					base[4] += base[1];
					base[1] = 0;

					base[3] = 1;
				}
				else if (res[i][lineup[j]] == 4)
				{
					base[4] += base[1] + base[2] + base[3] + 1;
					base[1] = 0;
					base[2] = 0;
					base[3] = 0;

				}

				if (outcnt == 3)
				{
					player = j + 1;
					if (player == 9)
						player = 0;
					next = 1;
					break;
				}
			}
			if (next == 1) 
				break;
			player = 0;
		}
		point += base[4];
	}
	if (ans < point)
		ans = point;

}
