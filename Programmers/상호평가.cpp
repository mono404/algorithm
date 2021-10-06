#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
	string answer = "";

	for (int i = 0; i < scores.size(); i++)
	{
		double sum = 0, cnt = 0, self = scores[i][i];
		int Max = 0, Min = 101;

		for (int j = 0; j < scores[i].size(); j++)
		{
			sum += scores[j][i];
			cnt++;

			if (i != j)
			{
				Max = max(Max, scores[j][i]);
				Min = min(Min, scores[j][i]);
			}
		}

		if (self > Max || self < Min)
		{
			sum -= self;
			cnt--;
		}

		double evg = sum / cnt;

		if (evg >= 90)
			answer += "A";
		else if (evg >= 80)
			answer += "B";
		else if (evg >= 70)
			answer += "C";
		else if (evg >= 50)
			answer += "D";
		else
			answer += "F";
	}

	return answer;
}

int main(void)
{
	cout << solution({{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}} ) << endl;
	cout << solution({{50, 90}, {50, 87}} ) << endl;
	cout << solution({{70, 49, 90}, {68, 50, 38}, {73, 31, 100}} ) << endl;
}