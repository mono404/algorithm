#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	deque<pair<int, int>> dq;

	for (int i = 0; i < priorities.size(); i++)
	{
		dq.push_back({ i, priorities[i] });
	}

	while (!dq.empty())
	{
		bool flag = false;
		pair<int, int> pick = dq.front();
		dq.pop_front();

		for (int i = 0; i < dq.size(); i++)
		{
			if (pick.second < dq[i].second)
			{
				dq.push_back(pick);
				flag = true;
				break;
			}
		}

		if (flag == true)
			continue;

		answer++;

		if (flag == false && pick.first == location)
		{
			break;
		}
	}

	return answer;
}

int main(void)
{
	cout << solution({ 2, 1, 3, 2 }, 2) << endl;
	cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << endl;
}