#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = -1;
	stack<char> st;

	for (int i = 0; i < s.size(); i++)
	{
		if (st.empty())
			st.push(s[i]);
		else if (st.top() == s[i])
			st.pop();
		else
			st.push(s[i]);
	}

	if (st.empty())
		answer = 1;
	else
		answer = 0;
		
	return answer;
}

int main(void)
{
	cout << solution("baabaa") << endl;
	cout << solution("cdcd") << endl;
}