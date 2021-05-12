#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

typedef struct Node {
	int num;
	vector<Node*> child;
}Node;

int n, cnt, del_num;
Node root;
vector<Node> v;
unordered_map<int, vector<int>> m;

void del(int p_num)
{
	//for (int i = 0; i < m[p_num].size(); i++)
	//{
	//	if (m.find(m[p_num][i]) != m.end())
	//		del(m[p_num][i]);
	//}
	//m.erase(p_num);

	for (int i = 0; i < m[p_num].size(); i++)
	{
		if (m.find(m[p_num][i]) != m.end())
			del(m[p_num][i]);
	}
	m.erase(p_num);
}

void find(int p_num)
{
	for (auto it = m[p_num].begin(); it != m[p_num].end();)
	{
		if (*it == del_num)
		{
			del(*it);
			it = m[p_num].erase(it);
		}
		else
		{
			if (m.find(*it) != m.end())
				find(*it);
			it++;
		}
	}

	if (m[p_num].size() == 0)
		m.erase(p_num);
}

void count_terminal(int p_num)
{
	for (int i = 0; i < m[p_num].size(); i++)
	{
		if (m.find(m[p_num][i]) != m.end() && m[p_num][i] != del_num)
			count_terminal(m[p_num][i]);
		else
		{
			if (del_num != m[p_num][i])
				cnt++;
		}
	}


}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		m[input].push_back(i);
	}

	cin >> del_num;

	find(-1);
	count_terminal(-1);

	cout << cnt << "\n";

	return 0;
}