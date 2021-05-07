#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int map[80][80];

vector<vector<int>> lotation(vector<vector<int>>& key)
{
    vector<vector<int>> tmp = key;

    for (int i = 0; i < key.size(); i++)
        for (int j = 0; j < key[i].size(); j++)
            tmp[j][key.size() - i - 1] = key[i][j];
    
    return tmp;
}

bool match(vector<vector<int>>& key, vector<vector<int>>& lock, int y, int x)
{
    bool check = true;
    int tmp[80][80];
    memcpy(tmp, map, sizeof(map));

    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            if (key[i][j] != tmp[i + y][j + x])
            {
                tmp[i + y][j + x] = 1;
            }
        }
    }

    for (int i = key.size() - 1; i < lock.size() + key.size() - 1; i++)
    {
        for (int j = key.size() - 1; j < lock.size() + key.size() - 1; j++)
        {
            if (tmp[i][j] == 0)
                check = false;
        }
    }

    return check;
}

bool check(vector<vector<int>>& key, vector<vector<int>>& lock)
{
    bool out = false;
    int end = lock.size() + (key.size() * 2) - 2;
    for (int i = 0; i < end; i++)
    {
        for (int j = 0; j < end; j++)
        {
            out = match(key, lock, i, j);
            if (out == true)
                break;
        }
        if (out == true)
            break;
    }


    return out;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    memset(map, 0, sizeof(map));
    
    vector<vector<int>> key_0 = key;
    vector<vector<int>> key_90 = lotation(key_0);
    vector<vector<int>> key_180 = lotation(key_90);
    vector<vector<int>> key_270 = lotation(key_180);

    vector<vector<int>> rotate_key[4];
    rotate_key[0] = key;

    for (int i = 1; i < 4; i++)
        rotate_key[i] = lotation(rotate_key[i - 1]);

    for (int i = 0; i < lock.size(); i++)
        for (int j = 0; j < lock.size(); j++)
            map[i + key.size() - 1][j + key.size() - 1] = lock[i][j];

    for (int i = 0; i < 4; i++)
    {
        answer = check(rotate_key[i], lock);
        if (answer == true)
            return answer;
    }

    return answer;
}

int main(void)
{
    cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}} , {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}} ) << "\n";
}