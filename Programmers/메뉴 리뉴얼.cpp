#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    set<char> s;
   
    for (int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        for (int j = 0; j < orders[i].size(); j++)
        {
            s.insert(orders[i][j]);
        }
    }

    vector<char> food(s.begin(), s.end());
    sort(food.begin(), food.end());

    for (int k = 0; k < course.size(); k++)
    {
        vector<int> pick;
       
        for (int i = 0; i < s.size(); i++)
        {
            if (i < s.size() - course[k])
                pick.push_back(0);
            else
                pick.push_back(1);
        }

        string tmp = "";
        vector<string> ans_str;
        int ans_int = 0;

        do {
            tmp = "";
            
            int cnt = 0;
            for (int i = 0; i < pick.size(); i++)
            {
                if (pick[i] == 1)
                    tmp += food[i];
            }
            
            for (int i = 0; i < orders.size(); i++)
            {
                if (includes(orders[i].begin(), orders[i].end(), tmp.begin(), tmp.end()))
                {
                    cnt++;
                }
            }

            if (cnt > ans_int && cnt > 1)
            {
                ans_str.clear();
                ans_int = cnt;
                ans_str.push_back(tmp);
            }
            else if (cnt == ans_int && cnt > 1)
            {
                ans_str.push_back(tmp);
            }

        } while (next_permutation(pick.begin(), pick.end()));

        for (int i = 0; i < ans_str.size(); i++)
        {
            answer.push_back(ans_str[i]);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main(void)
{
    //vector<string> ans1 = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2, 3, 4 });
    vector<string> ans2 = solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2, 3, 5 });
    //vector<string> ans3 = solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 });
}