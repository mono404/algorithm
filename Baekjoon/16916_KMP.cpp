#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s, p;
vector<int> f;

vector<int> failure_function(const string& S)
{
    vector<int> f(S.size(), 0);

    int m = 0;
    int begin = 1;
    while(begin + m < S.size())
    {
        if (S[begin + m] == S[m])
        {
            m++;
            f[begin + m - 1] = m;
        }
        else
        {
            if (m == 0)
                begin++;
            else
            {
                begin += (m - f[m - 1]);
                m = f[m - 1];
            }
        }
    }

    return f;
}

int kmp(const string& a, const string& b)
{
    vector<int> f = failure_function(b);
    vector<int> r(a.size() - b.size() + 1, 0);

    int m = 0;
    int begin = 0;

    while (begin <= a.size() - b.size())
    {
        if (m < b.size() && a[begin + m] == b[m])
        {
            m++;
            
            if (m == b.size())
                return 1;
        }
        else
        {
            if (m == 0)
                begin++;
            else
            {
                begin += (m - f[m - 1]);
                m = f[m - 1];
            }
        }
    }

    return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> p;
    int ans = kmp(s, p);

    cout << ans << "\n";

	return 0;
}