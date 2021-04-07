#include<iostream>

using namespace std;

int t;
int c; // 01 : 1 / 100 : 2 / 0 : 3 / 1 : 4
int l;
string s1 = "01";
string s2 = "100";
string s3 = "0";
string s4 = "1";
int back;
bool check;

void find()
{
	check = true;
	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (!str.compare(i, 2, s1) && (back == 0 || back == 2))
		{
			i++;
			back = 0;
		}
		else if (!str.compare(i, 3, s2) && (back == 0 || back == 2))
		{
			i += 2;
			back = 1;
		}
		else if (!str.compare(i, 1, s3) && back == 1)
		{
			back = 1;
		}
		else if (!str.compare(i, 1, s4) && (back == 1 || back == 2))
		{
			back = 2;
		}
		else
		{
			check = false;
			break;
		}
	}

	if (check == true && back != 1)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}

int main(void)
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		find();
	}
}