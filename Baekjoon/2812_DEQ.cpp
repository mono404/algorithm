#include<iostream>
#include<algorithm>
#include<stack>
#include<deque>
#include<string>

using namespace std;

int n, k, cnt, m, l = 1;
string num;
string res;
string ans;
deque<int> dq;

int main(void)
{
	cin >> n;
	cin >> k;

	cin >> num;

	//dq.push_back(num[0] - '0');

	//for (int i = 1; i < num.size(); i++)
	//{
	//	if (cnt < k)
	//	{
	//		if (dq.back() > num[i] - '0')
	//		{
	//			cnt++;
	//		}
	//		else if (dq.back() == num[i] - '0')
	//		{
	//			dq.push_back(num[i] - '0');
	//		}
	//		else
	//		{
	//			dq.pop_back();
	//			cnt++;
	//			dq.push_back(num[i] - '0');
	//		}
	//	}
	//	else
	//	{
	//		dq.push_back(num[i] - '0');
	//	}
	//}

	for (int i = 0; i < num.size(); i++)
	{
			if (dq.size() == 0)
				dq.push_back(num[i] - '0');
			else
			{
				int qsize = dq.size();
				for (int j = 0; j < qsize; j++)
				{
					if (num[i] - '0' > dq.back())
					{
						dq.pop_back();
						cnt++;
						if (cnt >= k)
							break;
					}
					else
					{
						break;
					}
				}
				dq.push_back(num[i] - '0');
			}
	}

	int qsize = dq.size();
	for (int i = 0; i < n - k; i++)
	{
		cout << dq.front();
		dq.pop_front();
	}
	cout << "\n";
}