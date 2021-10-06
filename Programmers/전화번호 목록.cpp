#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(const string& a, const string& b)
{
	return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map<string, vector<string>> m;

	sort(phone_book.begin(), phone_book.end(), cmp);

	int Min = phone_book[0].size();

	for (int i = 0; i < phone_book.size(); i++)
	{

		bool flag = false;

		for (int j = Min; j < phone_book[i].size(); j++)
		{
			if (m.find(phone_book[i].substr(0, j)) != m.end())
			{
				m[phone_book[i].substr(0, j)].push_back(phone_book[i]);
				flag = true;
				answer = false;
				break;
			}
		}

		if(flag == false)
			m[phone_book[i]].push_back(phone_book[i]);
	}

	return answer;
}

int main(void)
{
	cout << solution({ "119", "97674223", "1195524421" }) << endl;
	cout << solution({ "123","456","789" }) << endl;
	cout << solution({ "12","123","1235","567","88" }) << endl;
}