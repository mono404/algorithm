#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef struct User {
    string uid = "";
    string nick_name = "";
    vector<string> user_log;
}User;

unordered_map<string ,User> user_map;

vector<string> split(string str)
{
    vector<string> strv;
    string tmp = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            strv.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp.push_back(str[i]);
        }
    }
    if (tmp.size() > 0)
        strv.push_back(tmp);

    return strv;
}

void input(int num, vector<string> log)
{

}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> log;

    for (int k = 0; k < record.size(); k++)
    {
        log.clear();
        log = split(record[k]);
        
        string state = log[0];
        string uid = log[1];
        string name = "";
        if(state != "Leave")
            name = log[2];

        if (state == "Enter")
        {
            if (user_map[uid].nick_name != name)
                user_map[uid].nick_name = name;

            user_map[uid].user_log.push_back(state);
        }
        else if(state == "Leave")
        {
            user_map[uid].user_log.push_back(state);
        }
        else if (state == "Change")
        {
            user_map[uid].nick_name = name;
            user_map[uid].user_log.push_back(state);
        }
    }

    for (int i = 0; i < record.size(); i++)
    {
        log.clear();
        log = split(record[i]);

        string state = log[0];
        string uid = log[1];

        if (state == "Enter")
        {
            cout << user_map[uid].nick_name << "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.\n";
        }
        else if (state == "Leave")
        {
            cout << user_map[uid].nick_name << "´ÔÀÌ ³ª°¬½À´Ï´Ù.\n";
        }
        else if (state == "Change")
        {
            continue;
        }
    }

    return answer;
}
int main(void)
{
    vector<string> ans1 = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });

}