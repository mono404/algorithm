#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<string> a, vector<string> b)
{
    string a_head = "", b_head = "";
    int a_num = stoi(a[1]), b_num = stoi(b[1]);

    for (int i = 0; i < a[0].size(); i++)
    {
        a_head += tolower(a[0][i]);
    }

    for (int i = 0; i < b[0].size(); i++)
    {
        b_head += tolower(b[0][i]);
    }

    int cmp = a_head.compare(b_head);

    if (cmp == 0)
    {
        return a_num < b_num;
    }
    else if(cmp < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<vector<string>> split(vector<string> files)
{
    vector<vector<string>> out;
    vector<string> file;

    string head = "";
    string number = "";
    string tail = "";
    bool head_check = true, number_check = true;

    for (int j = 0; j < files.size(); j++)
    {
        head = "", number = "", tail = "", head_check = true, number_check = true;

        for (int i = 0; i < files[j].size(); i++)
        {
            if (isdigit(files[j][i]) == 0 && head_check == true)
                head += files[j][i];
            else if (isdigit(files[j][i]) != 0 && number_check == true)
            {
                head_check = false;
                number += files[j][i];
                if (number.size() > 5)
                    number_check = false;
            }
            else
            {
                number_check = false;
                tail += files[j][i];
            }
        }

        file.push_back(head);
        file.push_back(number);
        file.push_back(tail);
        out.push_back(file);
        file.clear();
    }

    return out;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> splitstr = split(files);

    stable_sort(splitstr.begin(), splitstr.end(), cmp);
    //for (int i = 0; i < splitstr.size(); i++)
    //{
    //    for (int j = 0; j < splitstr.size(); j++)
    //    {
    //        if (cmp(splitstr[i], splitstr[j]) == true)
    //        {
    //            vector<string> tmp = splitstr[i];
    //            splitstr[i] = splitstr[j];
    //            splitstr[j] = tmp;
    //        }
    //    }
    //}

    for (int i = 0; i < splitstr.size(); i++)
    {
        string tmp = "";
        for (int j = 0; j < splitstr[i].size(); j++)
        {
            tmp += splitstr[i][j];
        }
        answer.push_back(tmp);
    }
    
    return answer;
}

int main(void)
{
    vector<string> ans;
    ans = solution({ "F15", "F13", "F15.txt", "G15" });
    //ans = solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "F-14 Thunderbolt II", "F-14 Tomcat" });
    //ans = solution({ "muzi1", "muzI1", "muzi001.txt", "muzi1.TXT" });
    ans = solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
    ans = solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" });
}