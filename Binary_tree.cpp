#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BinaryTree()
{
    int data;
    cout << "Enter the data:" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    Node*root = new Node(data);
    cout << "Enter data for inserting left node:" << data << endl;
    root->left = BinaryTree();
    cout << "Enter data for inserting right node:" << data << endl;
    root->right = BinaryTree();
    return root;
}

void levelOrderTraversal(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = BinaryTree();
    
    cout<<"printing banary tree:"<<endl;
    levelOrderTraversal(root);
    return 0;
}