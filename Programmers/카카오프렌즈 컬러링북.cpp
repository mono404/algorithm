#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

queue<pair<int, int>> q;
int visit[101][101];

int BFS(int m, int n, vector<vector<int>> picture)
{
    int size = 1;
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n || visit[ny][nx] == 1)
                continue;

            if (picture[ny][nx] == picture[cy][cx])
            {
                size++;
                visit[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }
    }

    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    memset(visit, 0, sizeof(visit));
    q = queue<pair<int, int>>();

    for (int i = 0; i < picture.size(); i++)
    {
        for (int j = 0; j < picture[i].size(); j++)
        {
            if (picture[i][j] == 0 || visit[i][j] == 1)
                continue;

            visit[i][j] = 1;
            q.push({ i, j });
            number_of_area++;
            max_size_of_one_area = max(BFS(m, n , picture), max_size_of_one_area);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(void)
{
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    vector<int> ans = solution(6, 4, picture);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}