//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(string s) {
//    vector<int> answer;
//    int zcnt = 0;
//    int cnt = 0;
//
//    for (;;)
//    {
//        string tmp = "";
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (s[i] == '1')
//            {
//                tmp.push_back(s[i]);
//            }
//            else
//            {
//                zcnt++;
//            }
//        }
//
//        int num = tmp.size();
//
//        s = "";
//
//        cnt++;
//        for (;;)
//        {
//            int res = num % 2;
//
//            s = to_string(res) + s;
//
//            num = num / 2;
//            if (num == 0)
//                break;
//        }
//
//        if (s.size() == 1)
//            break;
//    }
//
//    return { cnt, zcnt };
//}
//
//int main(void)
//{
//    vector<int> ans;
//
//    ans = solution("110010101001");
//    ans = solution("01110");
//    ans = solution("1111111");
//}