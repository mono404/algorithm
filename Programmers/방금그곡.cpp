#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> splitstr;
string tmp;

bool cmp(vector<string>& a, vector<string>& b)
{
    int duration_a = ((stoi(a[2]) - stoi(a[0])) * 60) + (stoi(a[3]) - stoi(a[1]));
    int duration_b = ((stoi(b[2]) - stoi(b[0])) * 60) + (stoi(b[3]) - stoi(b[1]));

    return duration_a > duration_b;
}

vector<string> split(string musicinfo)
{
    tmp = "";
    vector<string> out;
    for (int i = 0; i < musicinfo.size(); i++)
    {
        if (!(musicinfo[i] == ',' || musicinfo[i] == ':'))
        {
            //tmp.push_back(musicinfo[i]);
            tmp += musicinfo[i];
        }
        else
        {
            out.push_back(tmp);
            tmp = "";
        }
    }

    string tmp1 = "";
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] != '#')
        {
            //tmp1.push_back(tmp[i]);
            tmp1 += tmp[i];
        }
        else
        {
            if (tmp1.size() > 0)
            {
                tmp1.pop_back();
                tmp1.push_back(tolower(tmp[i - 1]));
            }
        }
    }
    tmp = tmp1;

    int duration = ((stoi(out[2]) - stoi(out[0])) * 60) + (stoi(out[3]) - stoi(out[1]));
    int i = 0;
    for (;;)
    {
        if (tmp.size() >= duration)
            break;
        tmp += tmp;
    }


    tmp = tmp.substr(0, duration);

    if (tmp.size() > 0)
    {
        out.push_back(tmp);
    }

    return out;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    splitstr.clear();

    tmp = "";
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] != '#')
        {
            //tmp.push_back(m[i]);
            tmp += m[i];
        }
        else
        {
            tmp.pop_back();
            //tmp.push_back(tolower(m[i - 1]));
            tmp += tolower(m[i - 1]);

        }
    }
    m = tmp;

    for (int i = 0; i < musicinfos.size(); i++)
    {
        splitstr.push_back(split(musicinfos[i]));
    }

    sort(splitstr.begin(), splitstr.end(), cmp);

    for (int i = 0; i < splitstr.size(); i++)
    {
        if (splitstr[i].size() > 5 && m.size() > 0)
        {
            int lsize = splitstr[i][5].size() - m.size() + 1;
            for (int j = 0; j < lsize; j++)
            {
                if (m == splitstr[i][5].substr(j, m.size()))
                {
                    return splitstr[i][4];
                }
            }
        }
    }

    return "(None)";
}

int main(void)
{
    string m;
    vector<string> musicinfos;

    m = "ABC";
    musicinfos = { "03:00,03:00,FOO," };
    cout << solution(m, musicinfos) << "\n";

    m = "C#B#F#";
    musicinfos = { "03:00,03:06,FOO,CBFC#B#F#", "04:00,04:08,BAR,CC#BCC#BCC#B" };
    cout << solution(m, musicinfos) << "\n";

    m = "ABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTU";
    musicinfos = { "12:00,12:14,HELLO,ABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTUABCDEFGHIZKLMNOPQRSTU", "13:00,13:05,WORLD,ABCDEF" };
    cout << solution(m, musicinfos) << "\n";

    m = "ABCDEFG";
    musicinfos = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    cout << solution(m, musicinfos) << "\n";

    m = "CC#BCC#BCC#BCC#B";
    musicinfos = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };
    cout << solution(m, musicinfos) << "\n";

    m = "ABC";
    musicinfos = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    cout << solution(m, musicinfos) << "\n";
}