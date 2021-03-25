//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//void DFS(int s);
//
//int n, c, cnt;
//vector<vector<int>> p(101);
//int visit[101];
//
//int main(void)
//{
//	cin >> n;
//	cin >> c;
//
//	for (int i = 0; i < c; i++)
//	{
//		int a, b;
//
//		cin >> a;
//		cin >> b;
//
//		p[a].push_back(b);
//		p[b].push_back(a);
//	}
//
//	DFS(1);
//
//	cout << cnt << endl;
//
//	return 0;
//}
//
//void DFS(int s)
//{
//	if (visit[s] == 1)
//	{
//		return;
//	}
//
//	visit[s] = 1;
//	for (int i = 0; i < p[s].size(); i++)
//	{
//		if (visit[p[s][i]] == 0)
//		{
//			cnt++;
//			DFS(p[s][i]);
//		}
//	}
//}