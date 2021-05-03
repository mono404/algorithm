#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int cnt;

void erase(int& m, int& n, vector<string>& board)
{
    int tmp[31][31];
    memset(tmp, 0, sizeof(tmp));

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            char lu = board[i][j];
            char ld = board[i + 1][j];
            char ru = board[i][j + 1];
            char rd = board[i + 1][j + 1];
            if (lu == ld && ld == ru && ru == rd && lu != '0')
            {
                tmp[i][j] = 1;
                tmp[i + 1][j] = 1;
                tmp[i][j + 1] = 1;
                tmp[i + 1][j + 1] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j] == 1)
            {
                board[i][j] = '0';
                cnt++;
            }
        }
    }
}
char arr[31][31];
void down(int& m, int& n, vector<string>& board)
{
    memset(arr, 0, sizeof(arr));
    vector<string> tmp;
    string tmp1;

    for (int i = 0; i < n; i++)
    {
        tmp1 = "";
        for (int j = m - 1; j >= 0; j--)
        {
            if (board[j][i] != '0')
                tmp1 += board[j][i];
                //tmp1.push_back(board[j][i]);
        }
        for (;;)
        {
            if (tmp1.size() >= max(m, n))
                break;
            tmp1 += '0';
            //tmp1.push_back('0');
        }
        tmp.push_back(tmp1);
        //cout << tmp1 << "\n";
    }
    

    for (int i = 0; i < tmp.size(); i++)
    {
        for (int j = 0; j < tmp[i].size(); j++)
        {
            arr[tmp[i].size() - j - 1][i] = tmp[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = arr[tmp.size() - m + i][tmp[0].size() - n + j];
        }
    }


    //cout << endl;
    //for (int i = 0; i < m; i++)
    //{
    //    for (int j = 0; j < n; j++)
    //    {
    //        cout << board[i][j];
    //    }
    //    cout << "\n";
    //}
    //int a = 0;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    cnt = 0;

    while (1)
    {
        cnt = 0;
        erase(m, n, board);
        down(m, n, board);
        answer += cnt;
        if (cnt == 0)
            break;
    }

    return answer;
}

int main(void)
{
    vector<string> board;

    board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
    cout << solution(4, 5, board) << "\n";

    board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    cout << solution(6, 6, board) << "\n";
}