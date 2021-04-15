#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    string tmp;
    int u = 1;
    int cnt = 1;
    int i, j;


    for (int k = 1; k < (s.size() / 2) + 2; k++)
    {
        tmp.clear();
        for (i = 0; i < s.length(); i++)
        {
            cnt = 1;
            //if(s.length() == 1)
            for (j = i + k; j < s.length(); j += k)
            {
                if (s.compare(i, k, s, j, k) == 0)
                    cnt++;
                else
                    break;
            }

            if (cnt == 1)
            {
                tmp += s.substr(i, k);
                i = i + k - 1;
            }
            else
            {
                tmp += to_string(cnt);
                tmp += s.substr(i, k);
                i = j - 1;
            }
        }
        int m = tmp.size();
        answer = min(m, answer);
        cout << tmp << "\n";
    }

    return answer;
}

int main(void)
{
    string str;

    str = "aabbaccc";
    cout << solution(str) << "\n";

    str = "ababcdcdababcdcd";
    cout << solution(str) << "\n";

    str = "abcabcdede";
    cout << solution(str) << "\n";

    str = "abcabcabcabcdededededede";
    cout << solution(str) << "\n";

    str = "xababcdcdababcdcd";
    cout << solution(str) << "\n";

    cout << "-a-" << "\n";
    str = "abbbcccabcdede";
    cout << solution(str) << "\n";

    cout << "-aaaaa-" << "\n";
    str = "aabbbccdddee";
    cout << solution(str) << "\n";

    cout << "-aaaaaaaaaabbbbbbbbbb-" << "\n";
    str = "aaaaaaaaaabbbbbbbbbb";
    cout << solution(str) << "\n";
}

int solution1(string s) {

    string tmp;
    int ans = s.size();
    int u = 1;
    int cnt = 1;
    int i, j;

    for (i = 0; i < s.length(); i++)
    {
        cnt = 1;
        for (j = i + 2; j < s.length(); j += 2)
        {

            if (s.compare(i, 2, s, j, 2) == 0)
                cnt++;
            else
                break;
        }

        if (cnt == 1)
        {
            // 1개
            //tmp.push_back(s[i]);
            // 2개
            tmp += s.substr(i, 2);
            //tmp.push_back(s[i]);
            //tmp.push_back(s[i + 1]);
            i = i + 1;

            //tmp.push_back(s[i + 1]);
            //tmp += s.substr(i, 2);
        }
        else
        {
            tmp.push_back(cnt + '0');
            // 1개
            //tmp.push_back(s[i]);
            // 2개
            tmp += s.substr(i, 2);
            //tmp.push_back(s[i]);
            //tmp.push_back(s[i + 1]);

            i = j - 1;
        }
    }
    
    int m = tmp.size();

    cout << tmp << "\n";
    int answer = min(m, ans);
    return answer;
}