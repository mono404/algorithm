#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

string make_numural(int n, int t, int m)
{
    int length = t * m;
    string out = "";

    for (int i = 0;; i++)
    {
        int q = i;
        string tmp = "";
        for (;;)
        {
            int r = q % n;

            if (r < 10)
                tmp = to_string(r) + tmp;
            else
                tmp = (char)(65 + (r - 10)) + tmp;

            if (out.size() + tmp.size() > length)
            {
                out += tmp;
                break;
            }

            q = q / n;

            if (q == 0)
                break;
        }
        out += tmp;

        if (out.size() >= length)
            break;
    }

    return "x" + out;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string numural = make_numural(n, t, m);
    
    for (int i = p;; i += m)
    {
        answer.push_back(numural[i]);
        if (answer.size() == t)
            break;
    }

    return answer;
}

int main(void)
{
    cout << solution(2, 4, 2, 1) << "\n";
    cout << solution(16, 16, 2, 1) << "\n";
    cout << solution(16, 16, 2, 2) << "\n";
}