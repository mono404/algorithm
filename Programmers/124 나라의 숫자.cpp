#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";

    int res, tmp;

    for (;;)
    {
        res = n % 3;
        n = n / 3;

        if (res == 0)
        {
            answer = "4" + answer;
            n--;
        }
        else if (res == 1)
            answer = "1" + answer;
        else if (res == 2)
            answer = "2" + answer;

        if (n <= 0)
            break;
    }

    return answer;
}

int main(void)
{
    //cout << solution(1) << endl;
    //cout << solution(2) << endl;
    //cout << solution(3) << endl;
    //cout << solution(4) << endl;

    for (int i = 1; i <= 16; i++)
    {
        cout << i << "\t" << solution(i) << "\n";
    }
}