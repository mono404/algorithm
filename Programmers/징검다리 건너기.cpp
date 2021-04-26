//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
//int solution(vector<int> stones, int k) {
//    int answer = 0;
//    int max_value = *max_element(stones.begin(), stones.end());
//    int min_value = 1;
//    int stones_size = stones.size();
//
//    while (min_value <= max_value)
//    {
//        int mid = (max_value + min_value) / 2;
//        int cnt = 0;
//
//        for (int i = 0; i < stones_size; i++)
//        {
//            if (stones[i] - mid <= 0)
//                cnt++;
//            else
//                cnt = 0;
//
//            if (cnt >= k)
//                break;
//        }
//
//        if (cnt >= k)
//            max_value = mid - 1;
//        else
//            min_value = mid + 1;
//
//        mid = (max_value + min_value) / 2;
//    }
//
//    return min_value;
//}
//
//int main(void)
//{
//    cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3) << endl;
//}