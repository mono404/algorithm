#include<iostream>
#include<vector>

using namespace std;

int n, cnt;
int arr[101][101];
vector<pair<int, int>> paper;

int main(void)
{
	memset(arr, 0, sizeof(arr));

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;

		paper.push_back(make_pair(a, b));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = paper[i].first; j < paper[i].first + 10; j++)
		{
			for (int k = paper[i].second; k < paper[i].second + 10; k++)
			{
				if (arr[j][k] == 0)
					cnt++;
				arr[j][k] = 1;
			}
		}
	}

	cout << cnt << endl;

	//for (int i = 0; i < 27; i++)
	//{
	//	for (int j = 0; j < 27; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}