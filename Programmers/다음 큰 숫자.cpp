#include <string>
#include <vector>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = n;
    string arr;

    for (;;)
    {
        if (a == 1)
        {
            arr = '1' + arr;
            break;
        }
        else if (a % 2 == 0)
        {
            arr = '0' + arr;
            a = a / 2;
        }
        else
        {
            arr = '1' + arr;
            a = a / 2;
        }
    }
    string tmp = arr;
    if (next_permutation(arr.begin(), arr.end()) == false)
    {
        arr = tmp;
        tmp.clear();
        for (int i = 1; i < arr.size(); i++)
            tmp += arr[i];

        sort(tmp.begin(), tmp.end());

        arr = "10" + tmp;
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] == '1')
            answer += pow(2, arr.size() - i - 1);
    }

    return answer;
}

int main(void)
{
    cout << solution(78) << endl;

    cout << solution(15) << endl;
}