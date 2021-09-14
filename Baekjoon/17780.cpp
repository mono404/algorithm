#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef struct Pin {
	int num;
	int y;
	int x;
	int dir;
};

int dy[] = { 0, 0, 0, -1, 1 };
int dx[] = { 0, 1, -1, 0, 0 };

int n, k;
pair<int, deque<Pin*>> board_p[14][14];
deque<Pin*> pins_p;

pair<int, deque<Pin>> board[14][14];
deque<Pin> pins;

void change_dir(deque<Pin>& pins, deque<Pin>& tmp)
{
	if (pins[tmp[0].num].dir == 1)
		pins[tmp[0].num].dir = 2;
	else if (pins[tmp[0].num].dir == 2)
		pins[tmp[0].num].dir = 1;
	else if (pins[tmp[0].num].dir == 3)
		pins[tmp[0].num].dir = 4;
	else if (pins[tmp[0].num].dir == 4)
		pins[tmp[0].num].dir = 3;

	if (tmp[0].dir == 1)
		tmp[0].dir = 2;
	else if (tmp[0].dir == 2)
		tmp[0].dir = 1;
	else if (tmp[0].dir == 3)
		tmp[0].dir = 4;
	else if (tmp[0].dir == 4)
		tmp[0].dir = 3;
}

void move(deque<Pin>& tmp, int ny, int nx, int Reverse)
{
	for (int j = 0; j < tmp.size(); j++)
	{
		pins[tmp[j].num].y = ny;
		pins[tmp[j].num].x = nx;
		tmp[j].y = ny;
		tmp[j].x = nx;
	}

	if (Reverse == 1)
		reverse(tmp.begin(), tmp.end());
}

int main(void)
{
	cin >> n >> k;
	pins.push_back({ -1, -1, -1, -1 });

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j].first;
		}
	}

	for (int i = 1; i <= k; i++)
	{
		int y, x, dir;
		cin >> y >> x >> dir;
		pins.push_back({ i, y, x, dir });
		board[y][x].second.push_back({ i, y, x, dir });
	}

	int answer = 0;
	bool flag = false;

	while (1)
	{
		answer++;

		int ny = 0;
		int nx = 0;

		for (int i = 1; i < pins.size(); i++)
		{
			Pin p = pins[i];

			if (board[p.y][p.x].second[0].num != p.num)
				continue;

			ny = p.y + dy[p.dir]; 
			nx = p.x + dx[p.dir];

			deque<Pin> tmp = board[p.y][p.x].second;
			board[p.y][p.x].second.clear();
			
			if (board[ny][nx].first == 2 || (ny < 1 || ny > n || nx < 1 || nx > n))
			{
				nx = p.x - dx[p.dir];
				ny = p.y - dy[p.dir];
				
				if (board[ny][nx].first == 2 || (ny < 1 || ny > n || nx < 1 || nx > n))
				{
					change_dir(pins, tmp);

					ny = p.y;
					nx = p.x;
				}
				else
				{
					change_dir(pins, tmp);
					move(tmp, ny, nx, board[ny][nx].first);
				}
			}
			else if (board[ny][nx].first == 0 || board[ny][nx].first == 1)
			{
				move(tmp, ny, nx, board[ny][nx].first);
			}

			board[ny][nx].second.insert(board[ny][nx].second.end(), tmp.begin(), tmp.end());
		}

		if (board[ny][nx].second.size() >= 4)
			break;
		else if (answer > 1000)
		{
			answer = -1;
			break;
		}
	}

	cout << answer << endl;
}