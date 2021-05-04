#include <string>
#include <deque>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int timetoint(string str)
{
    string hour = "";
    hour += str[0];
    hour += str[1];
    string min = "";
    min += str[3];
    min += str[4];

    return (stoi(hour) * 60) + stoi(min);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int shuttle[11];
    map<int, vector<string>> shuttles;
    memset(shuttle, 0, sizeof(shuttle));

    int starttime = timetoint("09:00");

    sort(timetable.begin(), timetable.end());

    for (int i = 0; i < n; i++)
    {
        shuttles[starttime + (t * i)].push_back("0");
    }

    for (int i = 0; i < timetable.size(); i++)
    {
        int p_time = timetoint(timetable[i]);
        
        for (auto it = shuttles.begin(); it != shuttles.end(); it++)
        {
            if (p_time <= it->first && it->second.size() <= m)
            {
                it->second.push_back(timetable[i]);
                break;
            }
        }
    }

    //auto it = shuttles.rbegin();

    //for (it = shuttles.rbegin(); it != shuttles.rend(); it++)
    //{
    //    if (it->second.size() < m + 1)
    //    {

    //    }
    //    else
    //    {

    //    }
    //}

    auto end = --shuttles.end();
    vector<string> v(++end->second.begin(), end->second.end());
    sort(v.begin(), v.end());
    
    int r_time = 0;
    
    if (v.size() == m)
    {

        r_time = timetoint(v[m - 1]) - 1;
    }
    else
        r_time = end->first;

    int hour = r_time / 60;
    int min = r_time % 60;

    string tmp = to_string(hour);

    if (tmp.size() == 1)
    {
        answer += "0";
        answer += to_string(hour);
    }
    else
        answer += to_string(hour);

    answer += ":";

    tmp = to_string(min);

    if (tmp.size() == 1)
    {
        answer += "0";
        answer += to_string(min);
    }
    else
        answer += to_string(min);

    return answer;
}

int main(void)
{
    cout << solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" }) << "\n";
    cout << solution(2, 10, 2, { "09:10", "09:09", "08:00" }) << "\n";
    cout << solution(2, 1, 2, { "09:00", "09:00", "09:00", "09:00" }) << "\n";
    cout << solution(1, 1, 5, { "00:01", "00:01", "00:01", "00:01", "00:01" }) << "\n";
    cout << solution(1, 1, 1, { "23:59" }) << "\n";
    cout << solution(10, 60, 45, { "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" }) << "\n";
}