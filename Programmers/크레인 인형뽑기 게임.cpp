#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int n, cnt;
stack<int> s;

void pick(int idx, vector<vector<int>> &board)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][idx] != 0)
        {
            if (s.size() > 0 && s.top() == board[i][idx])
            {
                s.pop();
                cnt += 2;
            }
            else
                s.push(board[i][idx]);

            board[i][idx] = 0;
            break;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    cnt = 0;
    n = board.size();
    s = stack<int>();

    for (int i = 0; i < moves.size(); i++)
    {
        pick(moves[i] - 1, board);
    }

    int answer = cnt;
    return answer;
}

int main(void)
{
    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
    cout << solution(board, moves) << "\n";
}