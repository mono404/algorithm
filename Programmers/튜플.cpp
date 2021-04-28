#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a.size() < b.size();
}

vector<vector<int>> split(string s)
{
    vector<vector<int>> out;
    vector<int> v;
    bool check = false;
    string tmp = "";
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            check = true;
            continue;
        }
        else if (s[i] == '}')
        {
            check = false;
            v.push_back(stoi(tmp));
            tmp = "";
            out.push_back(v);
            v.clear();
        }

        if (check == true)
        {
            if (s[i] == ',')
            {
                v.push_back(stoi(tmp));
                tmp = "";
            }
            else
                tmp.push_back(s[i]);
        }
    }

    return out;
}

vector<int> solution(string s) {
    vector<int> answer;

    unordered_set<int> S;
    vector<vector<int>> input = split(s);

    sort(input.begin(), input.end(), cmp);

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            S.insert(input[i][j]);
        }
    }

    for (auto it = S.begin(); it != S.end(); it++)
    {
        answer.push_back(*it);
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << endl;
    return answer;
}

int main(void)
{
    vector<int> answer;
    answer = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    answer = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    answer = solution("{{20,111},{111}}");
    answer = solution("{{123}}");
    answer = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
}