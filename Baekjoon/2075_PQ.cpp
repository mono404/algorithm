#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int a, int  b) {
		return a > b;
	}
};

//priority_queue<int, vector<int>, greater<int>> q;
priority_queue <int, vector<int>, cmp> pq;
int n;

int main(void)
{
	cin >> n;

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cin >> arr[j][i];
	//	}
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		if (arr[i][n - 1] > arr[j][n - 1])
	//		{
	//			int tmp[1501];
	//			memcpy(tmp, arr[i], sizeof(tmp));
	//			memcpy(arr[i], arr[j], sizeof(tmp));
	//			memcpy(arr[j], tmp, sizeof(tmp));
	//		}
	//	}
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			pq.push(a);


		}
		while (pq.size() > n)
		{
			pq.pop();
		}

	}

	cout << pq.top() << "\n";

	return 0;
}