#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

deque<int> q;

int weight_check()
{
    int sum = 0;

    for (int i = 0; i < q.size(); i++)
        sum += q[i];

    return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cnt = 0;

    q.clear();

    for (int i = 0; i < bridge_length; i++)
        q.push_back(0);

    for (;;)
    {
        answer++;

        if (q.size() > 0)
        {
            q.pop_front();
        }

        if (cnt < truck_weights.size() && weight_check() + truck_weights[cnt] <= weight)
        {
            q.push_back(truck_weights[cnt++]);
        }
        else
            q.push_back(0);

        if (cnt > 0 && weight_check() == 0)
            break;
    }

    return answer;
}

int main(void)
{
    cout << solution(2, 10, { 7, 4, 5, 6 }) << endl;
    cout << solution(100, 100, { 10 }) << endl;
    cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl;
}