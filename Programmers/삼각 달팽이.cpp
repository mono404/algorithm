//#include <string>
//#include <vector>
//#include <cstring>
//#include <iostream>
//
//using namespace std;
//
//int dy[] = { 1, 0, -1 };
//int dx[] = { 0, 1, -1 };
//
//int level[1002][1002];
//int cnt = 1;
//
//void recur(int y, int x, int dir, int k, int n)
//{
//    int ny = y;
//    int nx = x;
//
//    for (int i = 0; i < k; i++)
//    {
//        level[ny][nx] = cnt++;
//
//        ny = ny + dy[dir];
//        nx = nx + dx[dir];
//
//        
//
//        if (cnt > (n * (n + 1)) / 2)
//            return;
//    }
//
//    ny = ny - dy[dir];
//    nx = nx - dx[dir];
//
//    ny = ny + dy[(dir + 1) % 3];
//    nx = nx + dx[(dir + 1) % 3];
//
//    recur(ny, nx, (dir + 1) % 3, k - 1, n);
//}
//
//vector<int> solution(int n) {
//    memset(level, 0, sizeof(level));
//    vector<int> answer;
//    cnt = 1;
//    int k = 1;
//    bool check = false;
//
//    recur(0, 0, 0, n, n);
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < k; j++)
//        {
//            answer.push_back(level[i][j]);
//        }
//        k++;
//    }
//
//    return answer;
//}
//
//int main(void)
//{
//    vector<int> ans;
//    //ans = solution(7);
//    ans = solution(4);
//    ans = solution(5);
//    ans = solution(6);
//}