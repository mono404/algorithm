#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node {
    int y;
    int x;
    int val;
    Node* parent = NULL;
    Node* left = NULL;
    Node* right = NULL;
}Node;

Node parent;
vector<int> pre, post;

bool cmp(Node& a, Node& b)
{
    if (a.y == b.y)
        return a.x < b.x;
    else
        return a.y > b.y;
}

void insert(Node node)
{
    Node* p_node = &parent;
    Node* child = new Node();
    child->y = node.y;
    child->x = node.x;
    child->val = node.val;

    while (1)
    {
        if (node.x > p_node->x)
        {
            if (p_node->right == NULL)
            {
                p_node->right = child;
                break;
            }
            else
            {
                p_node = p_node->right;
            }
        }
        else
        {
            if (p_node->left == NULL)
            {
                p_node->left = child;
                break;
            }
            else
            {
                p_node = p_node->left;
            }
        }
    }
}

void preorder(Node* node)
{
    pre.push_back(node->val);
    if(node->left != NULL)
        preorder(node->left);
    if(node->right != NULL)
        preorder(node->right);
}

void postorder(Node* node)
{
    if (node->left != NULL)
        postorder(node->left);
    if (node->right != NULL)
        postorder(node->right);
    post.push_back(node->val);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> v;

    for (int i = 0; i < nodeinfo.size(); i++)
        v.push_back({ nodeinfo[i][1], nodeinfo[i][0], i + 1 });
    
    sort(v.begin(), v.end(), cmp);

    parent = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        insert(v[i]);
    }

    preorder(&parent);
    postorder(&parent);

    return { pre, post };
}

int main(void)
{
    vector<vector<int>> ans;
    ans = solution({{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}} );
}