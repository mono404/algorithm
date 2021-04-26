#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

int T, n;
deque<int> q;
string input;
string arr;
string temp;
bool Rcheck = false;

void input_deque(string str)
{
	temp="";
	for (int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			temp.push_back(str[i]);
		else
		{
			q.push_back(stoi(temp));
			temp="";
		}
	}
	if (temp.length() > 0)
		q.push_back(stoi(temp));
}

int operate(char oper)
{
	if (oper == 'R')
	{
		if (Rcheck == true)
			Rcheck = false;
		else
			Rcheck = true;
	}
	else
	{
		if (Rcheck == true)
		{
			if (q.size() > 0)
				q.pop_back();
			else
				return -1;
		}
		else
		{
			if (q.size() > 0)
				q.pop_front();
			else
				return -1;
		}
	}
	return 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bool check;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		Rcheck = false;
		check = true;
		q.clear();

		cin >> input >> n >> arr;

		input_deque(arr);

		for (int i = 0; i < input.size(); i++)
		{
			if (operate(input[i]) < 0)
				check = false;
		}

		if (check == true)
		{
			cout << "[";
			if (q.size() > 0)
			{
				if (Rcheck == true)
				{
					for (int i = q.size() - 1; i > 0; i--)
						cout << q[i] << ",";
					cout << q[0];
				}
				else
				{
					for (int i = 0; i < q.size() - 1; i++)
						cout << q[i] << ",";
					cout << q[q.size() - 1];
				}
			}
			cout << "]\n";
		}
		else
			cout << "error" << "\n";
	}
}