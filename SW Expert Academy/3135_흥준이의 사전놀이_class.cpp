#pragma warning(disable: 4996)

#include <stdio.h>
#include <iostream>
using namespace std;

extern void init(void);

extern void insert(int buffer_size, char* buf);

extern int query(int buffer_size, char* buf);

int main(void) {
	//freopen("input.txt", "r", stdin);
	int TestCase;
	for (scanf("%d", &TestCase); TestCase--;) {
		int Query_N;
		scanf("%d", &Query_N);

		init();

		static int tc = 0;
		printf("#%d", ++tc);

		for (int i = 1; i <= Query_N; i++) {
			int type; scanf("%d", &type);

			if (type == 1) {
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				insert(buffer_size, buf);
			}
			else {
				char buf[15] = { 0, };
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
		fflush(stdout);
	}
}

class Trie {
private:
	bool finish;
	int child;
	Trie* next[26];
public:
	Trie();
	~Trie();
	void insert(const char* key);
	int find(const char* key);
};

Trie::Trie() {
	for (int i = 0; i < 26; i++)
	{
		next[i] = 0;
	}
}

Trie::~Trie() {
	for (int i = 0; i < 26; i++)
	{
		if (next[i])
			delete next[i];
	}
}

void Trie::insert(const char* key) {
	child++;

	if (*key == '\0')
		finish = true;
	else
	{
		int curr = *key - 'a';

		if (next[curr] == 0)
			next[curr] = new Trie();

		next[curr]->insert(key + 1);
	}
}

int Trie::find(const char* key) {
	if (*key == '\0')
		return child;

	int curr = *key - 'a';

	if (next[curr] == 0)
		return 0;

	return next[curr]->find(key + 1);
}

Trie* root;

void init(void) {
	root = new Trie();
}

void insert(int buffer_size, char* buf) {
	root->insert(buf);
}

int query(int buffer_size, char* buf) {
	return root->find(buf);
}