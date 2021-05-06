//#include <string>
//#include <vector>
//#include <iostream>
//#include <deque>
//#include <stack>
//
//using namespace std;
//
//int solution(string s) {
//    int answer = 0;
//    deque<char> dq;
//    
//    bool check = true;
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        dq.push_back(s[i]);
//    }
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        stack<char> stack;
//
//        for (int j = 0; j < dq.size(); j++)
//        {
//            if (dq[j] == '(' || dq[j] == '[' || dq[j] == '{')
//            {
//                stack.push(dq[j]);
//            }
//            else
//            {
//                if (stack.empty())
//                {
//                    check = false;
//                    break;
//                }
//
//                if (dq[j] == ')' && stack.top() == '(')
//                    stack.pop();
//                else if (dq[j] == ']' && stack.top() == '[')
//                    stack.pop();
//                else if (dq[j] == '}' && stack.top() == '{')
//                    stack.pop();
//
//            }
//        }
//
//        if (!stack.empty())
//            check = false;
//
//        if (check == true)
//            answer++;
//
//        char tmp = dq.front();
//        dq.pop_front();
//        dq.push_back(tmp);
//        check = true;
//    }
//
//    return answer;
//}
//
//int main(void)
//{
//    cout << solution("[](){}") << "\n";
//    cout << solution("}]()[{") << "\n";
//    cout << solution("[)(]") << "\n";
//    cout << solution("}}}") << "\n";
//}