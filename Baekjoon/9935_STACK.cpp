#include<iostream>
#include<deque>

using namespace std;

deque<char> s;
string input, bomb;

void check()
{
	string tmp = "";

	for (int i = 0; i < bomb.size(); i++)
	{
		//tmp.push_back(s[s.size() - 1 - i]);
		tmp = s[s.size() - 1 - i] + tmp;
	}

	if (tmp == bomb)
	{
		for (int i = 0; i < bomb.size(); i++)
		{
			s.pop_back();
		}
	}
}

void boom()
{
	for (int i = 0; i < input.size(); i++)
	{
		s.push_back(input[i]);
		if(s.size() >= bomb.size() && input[i] == bomb[bomb.size() - 1])
			check();
	}
}

int main(void)
{
	cin >> input >> bomb;

	boom();

	string ans(s.begin(), s.end());

	if (ans == "")
		cout << "FRULA\n";
	else
		cout << ans << "\n";
}