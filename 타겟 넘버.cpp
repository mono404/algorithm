#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> nums;
int Target, ans;

void DFS(int sum, int depth)
{
	if (depth == nums.size())
	{
		if (sum == Target)
			ans++;

		return;
	}

	DFS(sum + nums[depth], depth + 1);
	DFS(sum - nums[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	nums = numbers;
	Target = target;
	ans = 0;

	DFS(0, 0);

	answer = ans;

	return answer;
}

int main(void)
{
	cout << solution({ 1, 1, 1, 1, 1 }, 3) << endl;
}