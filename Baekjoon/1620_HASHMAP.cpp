#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int N, M;
unordered_map<int, string> m1;
unordered_map<string, int> m2;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;

		m1[i] = str;
		m2[str] = i;
	}

	for (int i = 0; i < M; i++)
	{
		string q;
		cin >> q;

		if (q[0] > '0' && q[0] <= '9')
			cout << m1.find(stoi(q))->second << "\n";
		else
			cout << m2.find(q)->second << "\n";
	}
}