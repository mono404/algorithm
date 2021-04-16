#include <string>
#include <vector>
#include<stack>
#include<iostream>

using namespace std;

int check(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.size() == 0)
            {
                return -1;
            }
            else if (s.top() == '(' && str[i] == ')')
            {
                s.pop();
            }
            else
            {
                return -1;
            }
        }
    }
    return 1;
}

string seperate(string p)
{
    string u, v, tmp;
    int o = 0, c = 0;

    if (p.size() == 0)
        return "";

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            o++;
        else if (p[i] == ')')
            c++;

        if (o == c)
        {
            u = p.substr(0, i + 1);
            //v = p.substr(i + 1, p.size());
            break;
        }
    }

    return u;
}

string solution(string p) {
    string answer = "";
    string u, v, tmp, res;

    if (check(p) == 1)
        return p;
    
    u = seperate(p);
    v = p.substr(u.length(), p.size());

    if (check(u) == 1)
    {
        v = solution(v);
        answer = u + v;


        //tmp = u;
        //u = seperate(v);
        //v = v.substr(u.length(), v.size());

        //v = solution(v);

        //for (int i = 1; i < u.size() - 1; i++)
        //{
        //    if (u[i] == '(')
        //    {
        //        res += ')';
        //    }
        //    else
        //    {
        //        res += '(';
        //    }
        //}

        //answer = tmp + '(' + res + ')' + v;
    }
    else
    {
        v = solution(v);

        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == '(')
            {
                res += ')';
            }
            else
            {
                res += '(';
            }
        }

        answer = '(' + res + ')' + v;
    }
    //cout << "answer : " << answer << "\n";
    //cout << "tmp : " << tmp <<"u : " << u << " v : " << v << endl;

    return answer;
}

int main(void)
{
    string str;

    str = "(()())()";
    cout << "ans : " << solution(str) << "\n";

    str = ")(";
    cout << "ans : " << solution(str) << "\n";

    //str = ")((())";
    //cout << "ans : " << solution(str) << "\n";

    //str = "()";
    //cout << "ans : " << solution(str) << "\n";

    str = "()))((()";
    cout << "ans : " << solution(str) << "\n";

    //str = "()))((()()";
    //cout << "ans : " << solution(str) << "\n";

}