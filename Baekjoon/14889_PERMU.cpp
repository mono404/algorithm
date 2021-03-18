//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//void calc(vector<int> v);
//
//int n, res = 999;
//int arr[22][22];
//int order[8];
//
//int main(void)
//{
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//
//	vector<int> v;
//
//	for (int i = 0; i < n / 2; i++)
//	{
//		v.push_back(0);
//		v.push_back(1);
//	}
//
//	sort(v.begin(), v.end());
//
//	do {
//		
//		calc(v);
//		
//	} while (next_permutation(v.begin(), v.end()));
//
//	cout << res << endl;
//}
//
//void calc(vector<int> v)
//{
//	int start_sum = 0;
//	int link_sum = 0;
//	int diff;
//	vector<int> start;
//	vector<int> link;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (v[i] == 0)
//			start.push_back(i);
//		else
//			link.push_back(i);
//	}
//
//	for (int i = 0; i < n / 2; i++)
//	{
//		for (int j = 0; j < n / 2; j++)
//		{
//			if (i == j)
//				continue;
//
//			start_sum += arr[start[i]][start[j]];
//			link_sum += arr[link[i]][link[j]];
//		}
//	}
//	diff = abs(start_sum - link_sum);
//
//	if (res > diff)
//		res = diff;
//}