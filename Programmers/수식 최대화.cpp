#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void operation(vector<string>& e, string oper)
{
    long long res = 0;
    for (auto it = e.begin(); it != e.end();)
    {
        if (*it == oper)
        {
            it--;
            long long a = stoi(*it);
            it = e.erase(it);
            string b = *it;
            it = e.erase(it);
            long long c = stoi(*it);
            it = e.erase(it);

            if (b == "+")
                res = a + c;
            else if (b == "-")
                res = a - c;
            else if (b == "*")
                res = a * c;

            it = e.insert(it, to_string(res));
        }
        else
            it++;
    }
}

vector<string> split(string e)
{
    string tmp = "";
    vector<string> out;

    for (int i = 0; i < e.size(); i++)
    {
        if (e[i] == '+' || e[i] == '-' || e[i] == '*')
        {
            out.push_back(tmp);
            tmp = e[i];
            out.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp.push_back(e[i]);
        }
    }
    out.push_back(tmp);

    return out;
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> splitstr = split(expression);
    vector<string> tmp = splitstr;

    vector<string> pick;

    pick.push_back("+");
    pick.push_back("-");
    pick.push_back("*");

    sort(pick.begin(), pick.end());

    do {
        splitstr = tmp;
        for (int i = 0; i < pick.size(); i++)
            operation(splitstr, pick[i]);

        answer = max(answer, llabs(stoi(splitstr[0])));

    } while (next_permutation(pick.begin(), pick.end()));

    return answer;
}

int main(void)
{
    cout << solution("100-200*300-500+20") << "\n";
    cout << solution("50*6-3*2") << "\n";
}