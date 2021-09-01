#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	bool release_check[100];
	vector<int> remain;

	for (int i = 0; i < 100; i++)
		release_check[i] = false;

	for (int i = 0; i < progresses.size(); i++)
	{
		double a = progresses[i];
		double b = speeds[i];
		double release_day = (100 - a) / b;

		remain.push_back(ceil(release_day));
	}

	int forework = remain[0];
	int cnt = 1;

	for (int i = 1; i < remain.size(); i++)
	{
		if (forework < remain[i])
		{
			answer.push_back(cnt);
			forework = remain[i];
			cnt = 1;
		}
		else
		{
			cnt++;
		}
	}
	answer.push_back(cnt);
	return answer;
}

int main(void)
{
	vector<int> out;
	out = solution({ 93, 30, 55 }, { 1, 30, 5 });
	out = solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 });

	return 0;
}
