#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int time = 0;
    bool hit = false;
    unordered_map<string, int> m;
    deque<pair<string, int>> v;

    for (int i = 0; i < cities.size(); i++)
    {
        hit = false;

        for (int j = 0; j < cities[i].size(); j++)
            cities[i][j] = tolower(cities[i][j]);

        //for (auto it = v.begin(); it != v.end();)
        //{
        //    if (it->first == cities[i])
        //    {
        //        hit = true;
        //        it = v.erase(it);
        //        v.push_back({ cities[i], cacheSize });
        //    }
        //    else
        //    {
        //        it++;
        //    }
        //}

        auto it = v.begin();
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].first == cities[i])
            {
                hit = true;
                it = v.erase(it);
                v.push_back({ cities[i], cacheSize });
                answer += 1;
                break;
            }
            else
                it++;
        }

        if (hit == false)
        {
            answer += 5;
            v.push_back({ cities[i], cacheSize });
        }

        if (v.size() > cacheSize)
            v.pop_front();
    }
    
    return answer;
}

int main(void)
{
    vector<string> cities;

    //cities = { "Jeju", "Pangyo", "Seoul", "Pangyo", "Pangyo", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
    //cout << solution(3, cities) << "\n";

    cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
    cout << solution(3, cities) << "\n";

    cities = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
    cout << solution(3, cities) << "\n";

    cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
    cout << solution(2, cities) << "\n";

    cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
    cout << solution(5, cities) << "\n";

    cities = { "Jeju", "Pangyo", "NewYork", "newyork" };
    cout << solution(2, cities) << "\n";

    cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
    cout << solution(2, cities) << "\n";
}