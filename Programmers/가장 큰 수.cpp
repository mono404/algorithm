#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const int& a, const int& b)
{
	string aa = to_string(a);
	string bb = to_string(b);

	if (aa.length() != bb.length())
	{
		string aaa = aa + bb;
		string bbb = bb + aa;

		return stoi(aaa) > stoi(bbb);
	}
	else
	{
		return a > b;
	}
	
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), cmp);

	for (int i = 0; i < numbers.size(); i++)
	{
		answer += to_string(numbers[i]);
	}

	if (stoi(answer) == 0)
		answer = "0";

	return answer;
}

int main(void)
{
	cout << solution({ 0, 0, 0, 0 }) << endl;
	cout << solution({ 6, 10, 2, 0 }) << endl;
	cout << solution({ 3, 30, 34, 5, 9 }) << endl;
}