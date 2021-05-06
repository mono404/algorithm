#include <string>
#include <vector>

using namespace std;

int zcnt, ocnt;

void divide(vector<vector<int>> arr, int y, int x, int n)
{
    int zero = 0;
    int one = 0;
    bool check = true;

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (arr[i][j] == 0)
            {
                zero++;
                if (one > 0)
                {
                    check = false;
                    break;
                }
            }
            else if (arr[i][j] == 1)
            {
                one++;
                if (zero > 0)
                {
                    check = false;
                    break;
                }
            }
        }
        if (check = false)
            break;
    }

    if (zero == n * n)
    {
        zcnt++;
        return;
    }
    else if (one == n * n)
    {
        ocnt++;
        return;
    }


    divide(arr, y, x, n / 2);
    divide(arr, y, x + (n / 2), n / 2);
    divide(arr, y + (n / 2), x, n / 2);
    divide(arr, y + (n / 2), x + (n / 2), n / 2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    zcnt = 0, ocnt = 0;
    int n = arr.size();

    divide(arr, 0, 0, n);

    return { zcnt, ocnt };
}

int main(void)
{
    vector<int> ans;

    ans = solution({ {1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1} });
    ans = solution({ {1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1}, {0, 1, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 1, 1} });

}