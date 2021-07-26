#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Node
{
    int num;
    bool isRemove = false;
    Node* prev;
    Node* next;
    friend class List;
};

class List
{
private:
    int size = 0;
    Node* head;
    Node* tail;
    Node* cursur;
    stack<Node*> trash;
public:
    List(int n, int k);
    ~List();
    bool isEmpty();
    void add_front(const int& num);
    void add_back(const int &num);
    void remove_front();
    void remove_back();

    void recover();
    void down_cursur(int n);
    void up_cursur(int n);

    string result();

    void erase_cursur();

    void print();
    void check_cursur();
protected:
    void add(Node* v, const int& num);
    void remove(Node* v);

};

List::List(int n, int k)
{
    head = new Node;
    head->num = -1;
    tail = new Node;
    tail->num = 9999999;

    head->next = tail;
    tail->prev = head;

    for (int i = 0; i < n; i++)
        add_back(i);

    cursur = head->next;
    down_cursur(k);
}

List::~List()
{
    while (!isEmpty())
        remove_front();

    delete head;
    delete tail;
}

bool List::isEmpty() {
    return (head->next == tail);
}

void List::add_front(const int& num)
{
    add(head, num);
}

void List::add_back(const int& num)
{
    add(tail->prev, num);
}

void List::add(Node* v, const int& num)
{
    Node* u = new Node;
    u->num = num;
    u->next = v->next;
    u->prev = v;

    v->next->prev = u;
    v->next = u;
}

void List::remove_front()
{
    remove(head->next);
}

void List::remove_back()
{
    remove(tail->next);
}

void List::remove(Node* v)
{
    Node* u = v->prev;
    Node* w = v->next;

    u->next = w;
    w->prev = u;

    delete v;
}

void List::recover()
{
    Node* v = trash.top();
    Node* u = v->prev;
    Node* w = v->next;
    trash.pop();

    while (u->isRemove != false)
        u = u->prev;

    u->next = v;
    v->prev = u;

    while (w->isRemove != false)
        w = w->prev;

    v->next = w;
    w->prev = v;

    v->isRemove = false;
}

void List::down_cursur(int n)
{
    for (int i = 0; i < n; i++)
        cursur = cursur->next;
}

void List::up_cursur(int n)
{
    for (int i = 0; i < n; i++)
        cursur = cursur->prev;
}

string List::result()
{
    Node* v = head->next;
    string res;
    res.resize(1000001, 'X');
    int cnt = 0;

    while (v->num != 9999999)
    {
        res[v->num] = 'O';
        v = v->next;
    }

    return res;
}

void List::erase_cursur()
{
    Node* v = cursur->prev;
    Node* w = cursur->next;

    v->next = w;
    w->prev = v;

    trash.push(cursur);
    cursur->isRemove = true;

    if (w->num == 9999999)
        cursur = v;
    else
        cursur = w;
}

void List::print()
{
    Node* v = head->next;
    while (v->num != 9999999) {
        //cout << v->num << " ";
        cout << v->num << " : ";
        switch (v->num)
        {
        case 0:
            cout << "무지\n";
            break;
        case 1:
            cout << "콘\n";
            break;
        case 2:
            cout << "어피치\n";
            break;
        case 3:
            cout << "제이지\n";
            break;
        case 4:
            cout << "프로도\n";
            break;
        case 5:
            cout << "네오\n";
            break;
        case 6:
            cout << "튜브\n";
            break;
        case 7:
            cout << "라이언\n";
            break;
        }
        v = v->next;
    }
    cout << endl;
}

void List::check_cursur()
{
    cout << "currnt cursur position : ";
    switch (cursur->num)
        {
        case 0:
            cout << "무지\n";
            break;
        case 1:
            cout << "콘\n";
            break;
        case 2:
            cout << "어피치\n";
            break;
        case 3:
            cout << "제이지\n";
            break;
        case 4:
            cout << "프로도\n";
            break;
        case 5:
            cout << "네오\n";
            break;
        case 6:
            cout << "튜브\n";
            break;
        case 7:
            cout << "라이언\n";
            break;
        }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<Node> s;
    List* list = new List(n, k);
    //list->print();
    //list->check_cursur();
    for (int i = 0; i < cmd.size(); i++)
    {

        if (cmd[i][0] == 'U')
            list->up_cursur(stoi(cmd[i].substr(2)));
        else if (cmd[i][0] == 'D')
            list->down_cursur(stoi(cmd[i].substr(2)));
        else if (cmd[i][0] == 'C')
            list->erase_cursur();
        else if (cmd[i][0] == 'Z')
            list->recover();

        //list->print();
        //list->check_cursur();
    }

    answer = list->result().substr(0, n);

    return answer;
}

int main(void)
{
    cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" }) << "\n";
    cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" }) << "\n";
    cout << solution(8, 7, { "C","Z","C","Z","C","Z","C","Z","C","Z","C",  }) << "\n";
}


