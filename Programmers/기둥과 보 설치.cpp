#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int b_arr[101][101];
int p_arr[101][101];

bool check(int x, int y, int a, int b)
{
    if (a == 0 && b == 0) // ��� ����
    {
        int p_tmp = p_arr[y][x];

        p_arr[y][x] = 0;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0)
            {
                if (b_arr[ny][nx] != 0)
                {
                    if (check(nx, ny, b_arr[ny][nx] - 1, 1) == false)
                    {
                        p_arr[y][x] = p_tmp;
                        return false;
                    }
                }

                if (p_arr[ny][nx] != 0)
                {
                    if (check(nx, ny, p_arr[ny][nx] - 1, 1) == false)
                    {
                        p_arr[y][x] = p_tmp;
                        return false;
                    }
                }
            }
        }
        return true;
    }
    else if (a == 0 && b == 1) // ��� ��ġ
    {
        if (y == 0 || b_arr[y][x - 1] == 2 || p_arr[y - 1][x] == 1)
            return true;
        else
            return false;
    }
    else if (a == 1 && b == 0) // �� ����
    {
        int b_tmp = b_arr[y][x];

        b_arr[y][x] = 0;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0)
            {
                if (b_arr[ny][nx] != 0)
                {
                    if (check(nx, ny, b_arr[ny][nx] - 1, 1) == false)
                    {
                        b_arr[y][x] = b_tmp;
                        return false;
                    }
                }

                if (p_arr[ny][nx] != 0)
                {
                    if (check(nx, ny, p_arr[ny][nx] - 1, 1) == false)
                    {
                        b_arr[y][x] = b_tmp;
                        return false;
                    }
                }
            }
        }
        return true;
    }
    else if (a == 1 && b == 1) // �� ��ġ
    {
        if (p_arr[y - 1][x] == 1 || p_arr[y - 1][x + 1] == 1 || (b_arr[y][x - 1] == 2 && b_arr[y][x + 1] == 2))
            return true;
        else
            return false;
    }
}

void build(int x, int y, int a, int b)
{
    if (check(x, y, a, b) == true)
    {
        if (b == 0)
        {
            
        }
        else if(a == 0)
        {
            p_arr[y][x] += a + 1;
        }
        else if (a == 1)
        {
            b_arr[y][x] += a + 1;
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
    ans = solution(5, { {2, 1, 0, 1} });
    //ans = solution(5, { {1, 0, 0, 1}, {2, 0, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 1}, {2, 1, 0, 1}, {1, 2, 1, 1}, {1, 1, 0, 0}, {2, 1, 0, 0} });
    ans = solution(5, { {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} });
    ans = solution(5, { {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} });
}