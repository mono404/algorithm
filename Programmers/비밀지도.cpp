//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//    vector<string> answer;
//
//    for (int i = 0; i < n; i++)
//    {
//        string str1;
//        string str2;
//
//        int tmp1 = arr1[i];
//        int tmp2 = arr2[i];
//
//        for (;;)
//        {
//            if (tmp1 % 2 == 1)
//                str1 = "#" + str1;
//            else
//                str1 = " " + str1;
//
//
//            tmp1 /= 2;
//
//            if (tmp1 == 1)
//            {
//                str1 = "#" + str1;
//                break;
//            }
//            else if (tmp1 == 0)
//            {
//                str1 = " " + str1;
//                break;
//            }
//        }
//
//        for (;;)
//        {
//            if (tmp2 % 2 == 1)
//                str2 = "#" + str2;
//            else
//                str2 = " " + str2;
//
//            tmp2 /= 2;
//
//            if (tmp2 == 1)
//            {
//                str2 = "#" + str2;
//                break;
//            }
//            else if (tmp2 == 0)
//            {
//                str2 = " " + str2;
//                break;
//            }
//        }
//
//        for (;;)
//        {
//            if (str1.size() < n)
//                str1 = " " + str1;
//            else
//                break;
//        }
//
//        for (;;)
//        {
//            if (str2.size() < n)
//                str2 = " " + str2;
//            else
//                break;
//        }
//
//        string ans;
//
//        for (int i = 0; i < n; i++)
//        {
//            if (str1[i] == '#' || str2[i] == '#')
//                ans = ans + "#";
//            else
//                ans = ans + " ";
//        }
//
//        answer.push_back(ans);
//    }
//    return answer;
//}