//#include<iostream>
//#include<stack>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//int n, cnt;
//bool q = false, err = false;
//
//int main(void)
//{
//	for (;;)
//	{
//		vector<string> sv;
//		vector<long long> nv;
//		vector<long long> temp;
//
//		for (;;)
//		{
//			string str;
//			cin >> str;
//
//			sv.push_back(str);
//
//			if (!str.compare("NUM"))
//			{
//				int a;
//				cin >> a;
//				//if (a > 1e9 || a < 0)
//				//{
//				//	q = true;
//				//	break;
//				//}
//				temp.push_back(a);
//			}
//			else if (!str.compare("END"))
//			{
//				break;
//			}
//			else if (!str.compare("QUIT"))
//			{
//				q = true;
//				break;
//			}
//		}
//
//		if (q == true)
//			break;
//
//		cin >> n;
//
//		for (int i = 0; i < n; i++)
//		{
//			stack<long long> s;
//			cnt = 0;
//			err = false;
//			long long a, t1, t2, t3;
//			cin >> a;
//
//			if (a > 1e9)
//			{
//				err = true;
//				break;
//			}
//			else
//			{
//
//				s.push(a);
//
//				for (int j = 0; j < sv.size() - 1; j++)
//				{
//					if (!sv[j].compare("NUM"))
//					{
//						t1 = temp[cnt++];
//
//						if (t1 > 1e9)
//						{
//							err = true;
//							break;
//						}
//
//						s.push(t1);
//					}
//					else if (!sv[j].compare("POP"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						s.pop();
//					}
//					else if (!sv[j].compare("INV"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t1 = s.top();
//						s.pop();
//						t1 = t1 * -1;
//						s.push(t1);
//					}
//					else if (!sv[j].compare("DUP"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t1 = s.top();
//						s.push(t1);
//					}
//					else if (!sv[j].compare("SWP"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t1 = s.top();
//						s.pop();
//
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t2 = s.top();
//						s.pop();
//
//						s.push(t1);
//						s.push(t2);
//					}
//					else if (!sv[j].compare("ADD"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t1 = s.top();
//						s.pop();
//
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t2 = s.top();
//						s.pop();
//
//						t3 = t1 + t2;
//
//						if (llabs(t3) > 1e9)
//						{
//							err = true;
//							break;
//						}
//
//						s.push(t3);
//					}
//					else if (!sv[j].compare("SUB"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t1 = s.top();
//						s.pop();
//
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t2 = s.top();
//						s.pop();
//
//						t3 = t2 - t1;
//
//						if (llabs(t3) > 1e9)
//						{
//							err = true;
//							break;
//						}
//
//						s.push(t3);
//					}
//					else if (!sv[j].compare("MUL"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t1 = s.top();
//						s.pop();
//
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t2 = s.top();
//						s.pop();
//
//						t3 = t2 * t1;
//
//						if (llabs(t3) > 1e9)
//						{
//							err = true;
//							break;
//						}
//
//						s.push(t3);
//					}
//					else if (!sv[j].compare("DIV"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t1 = s.top();
//						s.pop();
//
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t2 = s.top();
//						s.pop();
//
//						if (t1 == 0)
//						{
//							err = true;
//							break;
//						}
//
//						if (t2 > 0 && t1 > 0)
//							t3 = llabs(t2) / llabs(t1);
//						else if (t2 < 0 && t1 > 0)
//							t3 = (llabs(t2) / llabs(t1)) * -1;
//						else if (t2 > 0 && t1 < 0)
//							t3 = (llabs(t2) / llabs(t1)) * -1;
//						else if (t2 < 0 && t1 < 0)
//							t3 = (llabs(t2) / llabs(t1));
//						else
//						{
//							err = true;
//							break;
//						}
//
//						if (llabs(t3) > 1e9)
//						{
//							err = true;
//							break;
//						}
//
//						s.push(t3);
//					}
//					else if (!sv[j].compare("MOD"))
//					{
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t1 = s.top();
//						s.pop();
//
//						if (s.size() == 0)
//						{
//							err = true;
//							break;
//						}
//						t2 = s.top();
//						s.pop();
//
//						if (t1 == 0)
//						{
//							err = true;
//							break;
//						}
//
//						if (t2 < 0)
//							t3 = (llabs(t2) % llabs(t1)) * -1;
//						else
//							t3 = llabs(t2) % llabs(t1);
//
//						if (llabs(t3) > 1e9)
//						{
//							err = true;
//							break;
//						}
//
//						s.push(t3);
//					}
//				}
//			}
//
//			if (s.size() != 1)
//				err = true;
//
//			if(err == false)
//				cout << s.top() << endl;
//			else
//				cout << "ERROR" << endl;
//
//		}
//	}
//}