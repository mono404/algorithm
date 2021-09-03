#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq = priority_queue<int, vector<int>, greater<int>>(scoville.begin(), scoville.end());

	while (1)
	{
		if (pq.top() > K)
			break;

		answer++;

		if (pq.size() < 2)
			return -1;

		int first = pq.top();
		pq.pop();

		int second = pq.top();
		pq.pop();

		pq.push(first + second * 2);
	}

	return answer;
}

int main(void)
{
	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7) << endl;
}