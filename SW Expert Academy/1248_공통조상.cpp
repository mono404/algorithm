/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

typedef struct Node {
	int index;
	int parent;
	int child[2];
} Node;

vector<Node> tree;
int v, e, n1, n2;

void insertNode(int parent, int child)
{
	if (tree[parent].child[0] == 0)
		tree[parent].child[0] = child;
	else
		tree[parent].child[1] = child;

	tree[child].parent = parent;
}

int findParent(int n1, int n2)
{
	vector<int> n1_p, n2_p;
	unordered_map<int, int> m;

	int res;
	int n1_c = n1;
	int n2_c = n2;

	for (;;)
	{
		n1_p.push_back(tree[n1_c].parent);
		m[tree[n1_c].parent]++;
		n1_c = tree[n1_c].parent;

		if (n1_c == 1)
			break;
	}

	for (;;)
	{
		if (m[tree[n2_c].parent] != 0)
		{
			res = tree[n2_c].parent;
			break;
		}

		n2_c = tree[n2_c].parent;
	}

	return res;
}

int getChildSize(int index)
{
	int res = 0;

	if (tree[index].child[0] != 0)
	{
		res++;
		res += getChildSize(tree[index].child[0]);
	}

	if (tree[index].child[1] != 0)
	{
		res++;
		res += getChildSize(tree[index].child[1]);
	}

	return res;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		cin >> v >> e >> n1 >> n2;
		tree.clear();

		for (int i = 0; i <= v; i++)
		{
			Node node = { i, 0, {0, 0} };
			tree.push_back(node);
		}

		for (int i = 0; i < e; i++)
		{
			int parent, child;

			cin >> parent >> child;

			insertNode(parent, child);
		}

		int same_parent = findParent(n1, n2);
		int childSize = getChildSize(same_parent) + 1;

		cout << "#" << test_case << " " << same_parent << " " << childSize << "\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}