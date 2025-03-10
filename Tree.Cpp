#include <bits/stdc++.h>
using namespace std;

// create Tree Node
struct Node
{
    int data;
    vector<Node *> children;
    Node(int data)
    {
        this->data = data;
    };
};

// create BST Node
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void Tree_traversal_BFS(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(head);
    int Level = 0;
    while (!q.empty())
    {
        queue<Node *> temp;
        int size = q.size();
        cout << "Level " << Level << " : ";
        for (int i = 0; i < size; i++)
        {
            cout << q.front()->data << " ";
            for (auto child : q.front()->children)
            {
                temp.push(child);
            }
            q.pop();
        }
        cout << endl;
        q = temp;
        Level++;
    }
}

void Tree_traversal_DFS(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    for (auto child : head->children)
    {
        Tree_traversal_DFS(child);
    }
    return;
}

void insert(BSTNode *&head, int x) // truyền bằng tham chiếu
{
    if (head == NULL)
    {
        head = new BSTNode(x);
        return;
    }
    if (x < head->data)
    {
        insert(head->left, x);
    }
    else
    {
        insert(head->right, x);
    }
}

void BST_traversal(BSTNode *head)
{
    if (head == NULL)
        return;
    BST_traversal(head->left);
    cout << head->data << " ";
    BST_traversal(head->right);
    return;
}

void Kth_smallest(BSTNode *head, int k)
{
    if (head == NULL)
        return;
    static int count = 0;
    Kth_smallest(head->left, k);
    count++;
    if (count == k)
    {
        cout << head->data << " ";
        return;
    }
    Kth_smallest(head->right, k);
}

BSTNode *Lowest_Common_Ancestor(BSTNode *&head, int smallnum, int bignum)
{
    if (head == NULL)
        return head;
    else
    {
        if (head->data == smallnum || head->data == bignum)
        {
            return head;
        }
        else if (head->data > smallnum && head->data < bignum)
        {
            return head;
        }
        else if (head->data > bignum)
            return Lowest_Common_Ancestor(head->left, smallnum, bignum);
        else if (head->data < smallnum)
            return Lowest_Common_Ancestor(head->right, smallnum, bignum);
    }
    return head;
}

int distance_between_two_nodes(BSTNode *&head, int small, int big)
{
    if (head == NULL)
        return 0;
    if (small == big)
        return 0;
    if (head->data == big)
    {
        int count = 0;
        BSTNode *temp = head;
        while (temp->data != small)
        {
            if (small < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
            count++;
        }
        return count;
    }
    if (head->data == small)
    {
        int count = 0;
        BSTNode *temp = head;
        while (temp->data != big)
        {
            if (big < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
            count++;
        }
        return count;
    }
    if (head->data > big)
        return distance_between_two_nodes(head->left, small, big);
    if (head->data < small)
        return distance_between_two_nodes(head->right, small, big);
    if (head->data > small && head->data < big)
        return 2 + distance_between_two_nodes(head->left, small, head->left->data) + distance_between_two_nodes(head->right, head->right->data, big);
    return 0;
}

void root_to_node_path(BSTNode *&head, int num)
{
    if (head == NULL)
        return;
    if (head->data == num)
    {
        cout << head->data << " ";
        return;
    }
    cout << head->data << " ";
    if (head->data > num)
    {
        root_to_node_path(head->left, num);
    }
    else
    {
        root_to_node_path(head->right, num);
    }
    return;
}

void node_to_node_path(BSTNode *&head, int small, int big)
{
    BSTNode *LCA = Lowest_Common_Ancestor(head, small, big);
    return;
}
int main()
{
    Node *head = new Node(1);
    Node *child1 = new Node(2);
    Node *child2 = new Node(3);
    Node *child3 = new Node(4);
    Node *child4 = new Node(5);
    Node *child5 = new Node(6);
    Node *child6 = new Node(7);
    Node *child7 = new Node(8);
    Node *child8 = new Node(9);
    Node *child9 = new Node(10);
    Node *child10 = new Node(11);

    head->children.push_back(child1);
    head->children.push_back(child2);
    head->children.push_back(child3);
    child1->children.push_back(child4);
    child1->children.push_back(child5);
    child2->children.push_back(child6);
    child4->children.push_back(child7);
    child4->children.push_back(child8);
    child5->children.push_back(child9);
    child6->children.push_back(child10);

    // Tree_traversal_BFS(head);
    // cout << endl;
    // Tree_traversal_DFS(head);

    BSTNode *root = new BSTNode(5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    insert(root, 9);
    insert(root, 1);
    insert(root, 10);

    // BST_traversal(root);
    // cout << endl;
    // Kth_smallest(root, 2);
    // Lowest_Common_Ancestor(root, 6, 10);
    // cout << distance_between_two_nodes(root, 4, 5);
    // root_to_node_path(root, 2);
    node_to_node_path(root, 1, 10);
    return 0;
}
