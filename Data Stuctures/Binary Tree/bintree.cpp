//Print height of binary tree

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left, *right;

    node(int key)
    {
        this->key = key;
        this->left = this->right = NULL;
    }
    
    
};

int height(node *root)
{
    if (root == NULL)
        return 0;

    list<node*> q;
    q.push_back(root);

    node* front = NULL;
    int height = 0;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
           front = q.front();
           q.pop_front();

           if (front->left)
                q.push_back(front->left);

           if (front->right)
                q.push_back(front->right);
        }

        height++;
    }

    return height;
}

int main()
{
    node* root = NULL;
    
    root = new node(15);
    root->left = new node(10);
    root->right = new node(20);
    root->left->left = new node(8);
    root->left->right = new node(12);
    root->right->left = new node(16);
    root->right->right = new node(25);

    cout << "The height of the binary tree is " << height(root)<<endl;

    return 0;
}
