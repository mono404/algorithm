#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool BFS(int y, int x, vector<string> &room)
{
	queue<pair<int, int>> q;
	int visit[6][6] = { 0, };
	int dis = 0;

	q.push({ y, x });

	while (!q.empty())
	{
		int qsize = q.size();
		dis++;
		for (int k = 0; k < qsize; k++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (visit[ny][nx] == 1 || ny > 4 || ny < 0 || nx > 4 || nx < 0)
					continue;

				if (room[ny][nx] == 'P')
				{
					if (dis < 2)
						return false;
				}
				//else if (room[ny][nx] == 'O')
				//{

				//}
				//else if (room[ny][nx] == 'X')
				//{

				//}

				visit[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}

		if (dis == 2)
			return true;
	}
}

int dis_check(vector<string> &room)
{
	vector<pair<int, int>> parti;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (room[i][j] == 'P')
			{
				if (BFS(i, j, room) == false)
				{
					return 0;
				}
			}
			else if (room[i][j] == 'O')
			{
				int cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny > 4 || ny < 0 || nx > 4 || ny < 0)
						continue;

					if (room[ny][nx] == 'P')
						cnt++;

					if (cnt > 1)
						return 0;
				}
			}
		}
	}

	return 1;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < places.size(); i++)
	{
		answer.push_back(dis_check(places[i]));
	}

	return answer;
}

int main(void)
{
	vector<vector<string>> input = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
	vector<int> out = solution(input);

	return 0;
}