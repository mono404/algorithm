#include <string>
#include <vector>
#include <iostream>

using namespace std;

string step1(string& new_id)
{
	for (int i = 0; i < new_id.size(); i++)
		new_id[i] = tolower(new_id[i]);

	return new_id;
}

string step2(string& new_id)
{
	for (int i = 0; i < new_id.size(); i++)
	{
		if (new_id[i] >= 'a' && new_id[i] <= 'z')
			continue;
		else if (new_id[i] >= '0' && new_id[i] <= '9')
			continue;
		else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
			continue;
		else
		{
			new_id.erase(i, 1);
			i--;
		}
	}

	return new_id;
}

string step3(string& new_id)
{
	while (new_id.find("..") != string::npos)
	{
		new_id.erase(new_id.find(".."), 1);
	}

	return new_id;
}

string step4(string& new_id)
{
	if (new_id[0] == '.' && new_id.size() == 1)
	{
		return "";
	}

	if (new_id[0] == '.')
	{
		new_id.erase(0, 1);
	}
	
	if (new_id[new_id.size() - 1] == '.')
	{
		new_id.erase(new_id.size() - 1, 1);
	}

	return new_id;
}

string step5(string& new_id)
{
	if (new_id.size() == 0)
		new_id = "a";

	return new_id;
}

string step6(string& new_id)
{
	if (new_id.size() >= 16)
	{
		new_id.erase(15);
	}

	if (new_id[new_id.size() - 1] == '.')
	{
		new_id.erase(new_id.size() - 1, 1);
	}

	return new_id;
}

string step7(string& new_id)
{
	while (new_id.size() < 3)
	{
		new_id += new_id[new_id.size() - 1];
	}

	return new_id;
}

string solution(string new_id) {
	string answer = "";

	answer = step1(new_id);
	answer = step2(answer);
	answer = step3(answer);
	answer = step4(answer);
	answer = step5(answer);
	answer = step6(answer);
	answer = step7(answer);

	return answer;
}

int main(void)
{
	//cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
	//cout << solution("z-+.^.") << endl;
	cout << solution("=.=") << endl;
	cout << solution("123_.def") << endl;
	cout << solution("abcdefghijklmn.p") << endl;
}