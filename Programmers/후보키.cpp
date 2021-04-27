#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;




int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<vector<int>> ans_rel[25];

    for (int cnt = 1; cnt <= relation[0].size(); cnt++)
    {
        vector<int> pick;
        for (int i = 0; i < relation[0].size(); i++)
        {
            if (i < relation[0].size() - cnt)
                pick.push_back(0);
            else
                pick.push_back(1);
        }

        do {
            bool pass = false;
            
            for (int k = 1; k <= cnt; k++)
            {
                for (int i = 0; i < ans_rel[k].size(); i++)
                {
                    vector<int> aa = ans_rel[k][i];
                    vector<int> cc = pick;
                    int cnt_rel = 0;
                    for (int j = 0; j < ans_rel[k][i].size(); j++)
                    {
                        if (ans_rel[k][i][j] == 1 && pick[j] == 1)
                        {
                            cnt_rel++;
                        }
                    }

                    if (cnt_rel == k)
                    {
                        pass = true;
                    }
                }
            }

            if (pass == false)
            {
                vector<string> v;
                map<vector<string>, int> m;
                bool check = true;
                int i, j;

                for (i = 0; i < relation.size(); i++)
                {
                    v.clear();

                    for (j = 0; j < relation[i].size(); j++)
                    {
                        if (pick[j] == 1)
                            v.push_back(relation[i][j]);
                    }

                    m[v]++;

                    if (m[v] > 1)
                    {
                        check = false;
                        break;
                    }
                }

                if (check == true)
                {
                    ans_rel[cnt].push_back(pick);
                }
            }

        } while (next_permutation(pick.begin(), pick.end()));
    }

    for (int i = 1; i < 9; i++)
    {
        answer += ans_rel[i].size();
    }

    return answer;
}

int main(void)
{
    //cout << solution({{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}}) << endl;
    
    vector<vector<string>> input = {
        {"4", "4", "���", "2020-07-03 ���� 12:00:00", "love"}
        , {"5", "4", "����, ����, �� �����", "2020-07-03 ���� 12:00:00", "like"}
        , {"6", "4", "���,�뵵��", "2020-07-03 ���� 12:00:00", "apple"}
        , {"7", "4", "����,�⵵�ϴ�,���� ��û�ϴ�", "2020-07-03 ���� 12:00:00", "pray"}
        , {"8", "4", "����,�⵵�ϴ�,���� ��û�ϴ�", "2020-06-27 ���� 12:00:00", "pray"}
        , {"9", "4", "�ȳ�", "2020-07-03 ���� 12:00:00", "hi"}
        , {"10", "3", "����, ����", "2020-06-29 ���� 12:00:00", "like"}
        , {"11", "2", "���� ���ڸ� ���´�", "2020-06-27 ���� 12:00:00", "I take off my hat"} };

    cout << solution(input) << endl;

}