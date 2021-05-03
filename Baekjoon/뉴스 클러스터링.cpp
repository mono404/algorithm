#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> s1, s2;

    int str1_size = str1.size();
    for (int i = 0; i < str1_size; i++)
        str1[i] = tolower(str1[i]);

    int str2_size = str2.size();
    for (int i = 0; i < str2_size; i++)
        str2[i] = tolower(str2[i]);

    //for (auto iter = str1.begin(); iter != str1.end();)
    //{
    //    if (!(*iter >= 'a' && *iter <= 'z'))
    //        iter = str1.erase(iter);
    //    else
    //        iter++;
    //}

    //for (auto iter = str2.begin(); iter != str2.end();)
    //{
    //    if (!(*iter >= 'a' && *iter <= 'z'))
    //        iter = str2.erase(iter);
    //    else
    //        iter++;
    //}

    for (int i = 0; i < str1_size - 1; i++)
    {
        string tmp = str1.substr(i, 2);
        if(tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z')
            s1.insert(tmp);
    }

    for (int i = 0; i < str2_size - 1; i++)
    {
        string tmp = str2.substr(i, 2);
        if (tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z')
            s2.insert(tmp);
    }

    vector<string> union_set(s1.size() + s2.size());
    auto it = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), union_set.begin());
    union_set.erase(it, union_set.end());

    vector<string> inter_set(s1.size() + s2.size());
    it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inter_set.begin());
    inter_set.erase(it, inter_set.end());

    float inter_size = inter_set.size();
    float union_size = union_set.size();

    if (inter_size == 0 || union_size == 0)
        answer = 65536;
    else
        answer = (inter_size / union_size) * 65536;

    return answer;
}

int main(void)
{
    string str1, str2;

    str1 = "FRANCE";
    str2 = "french";
    cout << solution(str1, str2) << "\n";

    str1 = "handshake";
    str2 = "shake hands";
    cout << solution(str1, str2) << "\n";

    str1 = "aa1+aa2";
    str2 = "AAAA12";
    cout << solution(str1, str2) << "\n";

    str1 = "E=M*C^2";
    str2 = "e=m*c^2";
    cout << solution(str1, str2) << "\n";
}