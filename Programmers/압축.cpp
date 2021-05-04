#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dic;

    for (string str = "A"; str <= "Z"; str[0]++)
        dic[str] = str[0] - 'A' + 1;
    
    int cnt = 1;

    for (int i = 0; i < msg.size(); i++)
    {
        for (int j = 1; j < msg.size() - i + 1; j++)
        {
            string str = msg.substr(i, j);

            if (dic[str] == 0)
            {
                string tmp = str.substr(0, j - 1);
                answer.push_back(dic[tmp]);
                dic[str] = dic.size();
                i += tmp.size() - 1;
                break;
            }

            if (dic[str] != 0 && j == msg.size() - i)
            {
                answer.push_back(dic[str]);
                i += str.size() - 1;
            }
        }
    }


    return answer;
}

int main(void)
{
    vector<int> ans;
    ans = solution("KAKAO");

    ans = solution("TOBEORNOTTOBEORTOBEORNOT");

    ans = solution("ABABABABABABABAB");
}