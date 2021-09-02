#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct cond {
	char a;
	char b;
	char oper;
	int dis;
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	int answer = 0;
	vector<cond> conds;

	for (int i = 0; i < n; i++)
	{
		conds.push_back({ data[i][0], data[i][2], data[i][3], data[i][4] - '0' });
	}

	string friends = "ACFJMNRT";

	do {
		bool flag = true;
		for (int i = 0; i < conds.size(); i++)
		{
			int distance = friends.find(conds[i].a) - friends.find(conds[i].b);

			if (conds[i].oper == '=' && abs(distance) != conds[i].dis + 1)
			{
				flag = false;
				break;
			}
			else if (conds[i].oper == '>' && abs(distance) <= conds[i].dis + 1)
			{
				flag = false;
				break;
			}
			else if (conds[i].oper == '<' && abs(distance) >= conds[i].dis + 1)
			{
				flag = false;
				break;
			}
		}

		if (flag == true)
		{
			//cout << friends << endl;
			answer++;
		}
	} while (next_permutation(friends.begin(), friends.end()));

	return answer;
}

int main(void)
{
	cout << solution(2, { "N~F=0", "R~T>2" }) << endl;
	cout << solution(2, { "M~C<2", "C~M>1" }) << endl;
}