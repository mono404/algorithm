//#include<iostream>
//#include<queue>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//
//int n, m, cnt;
//int arr[101][101];
//int d[101][101];
//int visit[101][101];
//int cheese[101];
//queue<pair<int, int>> q;
//
//void BFS()
//{
//	memset(visit, 0, sizeof(visit));
//	memset(d, 0, sizeof(d));
//	q.push(make_pair(0, 0));
//	visit[0][0] = 1;
//
//	while (!q.empty())
//	{
//		int cy = q.front().first;
//		int cx = q.front().second;
//
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = cy + dy[i];
//			int nx = cx + dx[i];
//
//			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
//			{
//				if (arr[ny][nx] == 0)
//				{
//					if (visit[ny][nx] == 1)
//						continue;
//
//					q.push(make_pair(ny, nx));
//					visit[ny][nx] = 1;
//				}
//				else
//				{
//					cheese[cnt]++;
//					d[ny][nx]++;
//				}
//			}
//		}
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (d[i][j] >= 2)
//				arr[i][j] = 0;
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> n;
//	cin >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//
//	
//	while (1)
//	{
//		BFS();
//
//		if (cheese[cnt] == 0)
//			break;
//
//		cnt++;
//	}
//
//	cout << cnt << endl;
//}