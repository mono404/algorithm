#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Node {
	int value;
	bool isRemoved = false;
	Node* prev;
	Node* next;
	friend class List;
};

class List {
private:
	int size = 0;
	Node* head;
	Node* tail;
	Node* cursur;
	stack<Node*> trash;
public:
	List(const int& n, const int& k);
	~List();
	bool isEmpty();
	void addFront(const int& value);
	void addBack(const int& value);
	void removeFront();
	void removeBack();

	void moveCursur(const char& c, const int& n);
	void removeCursur();
	void undo();
	string makeAnswer(const int& n);
protected:
	void add(Node* v, const int& value);
	void remove(Node* v);
};

string solution(int n, int k, vector<string> cmd) {
	string answer = "";

	List* list = new List(n, k);

	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i][0] == 'D' || cmd[i][0] == 'U')
			list->moveCursur(cmd[i][0], stoi(cmd[i].substr(2)));
		else if (cmd[i][0] == 'C')
			list->removeCursur();
		else if (cmd[i][0] == 'Z')
			list->undo();
	}

	answer = list->makeAnswer(n);

	return answer;
}

//int main(void)
//{
//	cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" }) << endl;
//	cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" }) << endl;
//	cout << solution(8, 7, { "C","Z","C","Z","C","Z","C","Z","C","Z","C", }) << "\n";
//}

List::List(const int& n, const int& k)
{
	head = new Node();
	tail = new Node();
	cursur = new Node();

	head->next = tail;
	tail->prev = head;

	for (int i = 0; i < n; i++)
		addBack(i);

	cursur = head;

	for (int i = 0; i <= k; i++)
		cursur = cursur->next;
}

List::~List()
{
	while (!isEmpty())
		removeFront();

	delete head;
	delete tail;
}

bool List::isEmpty()
{
	if (head->next == tail)
		return true;

	return false;
}

void List::addFront(const int& value)
{
	add(head, value);
}

void List::addBack(const int& value)
{
	add(tail->prev, value);
}

void List::removeFront()
{
	remove(head->next);
}

void List::removeBack()
{
	remove(tail->prev);
}

void List::moveCursur(const char& c, const int& n)
{
	if (c == 'D')
	{
		for (int i = 0; i < n; i++)
			cursur = cursur->next;
	}
	else
	{
		for (int i = 0; i < n; i++)
			cursur = cursur->prev;
	}
}

void List::removeCursur()
{
	cursur->isRemoved = true;
	trash.push(cursur);

	Node* v = cursur->prev;
	Node* w = cursur->next;

	v->next = w;
	w->prev = v;

	cursur = cursur->next;
	if (cursur == tail)
		cursur = cursur->prev;
}

void List::undo()
{
	Node* v = trash.top();
	trash.pop();

	Node* w = v->prev;

	while (w->isRemoved != false)
		w = w->prev;

	Node* u = v->next;

	while (u->isRemoved != false)
		u = u->next;

	w->next = v;
	v->prev = w;

	u->prev = v;
	v->next = u;

	v->isRemoved = false;
}

string List::makeAnswer(const int& n)
{
	string answer;

	for (int i = 0; i < n; i++)
		answer += 'X';

	Node* v = head->next;

	while (v != tail)
	{
		answer[v->value] = 'O';
		v = v->next;
	}

	return answer;
}

void List::add(Node* v, const int& value)
{
	Node* w = new Node();

	w->value = value;
	w->prev = v;
	w->next = v->next;

	v->next->prev = w;
	v->next = w;
}

void List::remove(Node* v)
{
	Node* u = v->prev;
	Node* w = v->next;

	u->next = w;
	w->prev = u;

	delete v;
}