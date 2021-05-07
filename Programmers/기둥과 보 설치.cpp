#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dy[] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 0, 1, 1, 0, -1, -1, -1, 0, 1 };

int b_arr[101][101];
int p_arr[101][101];

bool build(int x, int y, int a, int b)
{
    if (a == 0 && b == 0) // 기둥 삭제
    {
        int p_tmp = p_arr[y][x];

        p_arr[y][x] = 0;

        for (int i = 0; i < 9; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0)
            {
                if ((b_arr[ny][nx] != 0 && build(nx, ny, b_arr[ny][nx] - 1, 1) == false) ||
                    (p_arr[ny][nx] != 0 && build(nx, ny, p_arr[ny][nx] - 1, 1) == false))
                {
                    p_arr[y][x] = p_tmp;
                    return false;
                }
            }
        }
        return true;
    }
    else if (a == 0 && b == 1) // 기둥 설치
    {
        if (y == 0 || b_arr[y][x - 1] == 2 || b_arr[y][x] == 2 || p_arr[y - 1][x] == 1)
        {
            p_arr[y][x] = a + 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (a == 1 && b == 0) // 보 삭제
    {
        int b_tmp = b_arr[y][x];

        b_arr[y][x] = 0;

        for (int i = 0; i < 9; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0)
            {
                if ((b_arr[ny][nx] != 0 && build(nx, ny, b_arr[ny][nx] - 1, 1) == false) ||
                    (p_arr[ny][nx] != 0 && build(nx, ny, p_arr[ny][nx] - 1, 1) == false))
                {
                    b_arr[y][x] = b_tmp;
                    return false;
                }
            }
        }
        return true;
    }
    else if (a == 1 && b == 1) // 보 설치
    {
        if (p_arr[y - 1][x] == 1 || p_arr[y - 1][x + 1] == 1 || (b_arr[y][x - 1] == 2 && b_arr[y][x + 1] == 2))
        {
            b_arr[y][x] = a + 1;
            return true;
        }
        else
        {
            return false;
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    memset(b_arr, 0, sizeof(b_arr));

    for (int i = 0; i < build_frame.size(); i++)
    {
        build(build_frame[i][0], build_frame[i][1], build_frame[i][2], build_frame[i][3]);
    }

    for (int j = 0; j <= n; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (p_arr[i][j] != 0)
                answer.push_back({ j, i, p_arr[i][j] - 1 });
            if (b_arr[i][j] != 0)
                answer.push_back({ j, i, b_arr[i][j] - 1 });
        }
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> ans;    
    ans = solution(5, { {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} });
    ans = solution(5, { {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} });
}
