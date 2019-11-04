//Print the given tree LevelWise

#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    node * left;
    node * right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

node * createTree()
{
    cout<<"Enter data and -1 to exit"<<endl;
    int data;
    cin>>data;
    node * root = NULL;
    queue<node*>q;
    if(data!=-1){
        root = new node(data);
        q.push(root);
    }
    while(!q.empty()){
        node * curr = q.front();
        q.pop();
        cout<<"Enter data for left of "<<curr->data<<endl;
        cin>>data;
        if(data!=-1){
            node * left = new node(data);
            curr->left = left;
            q.push(left);
        }

        cout<<"Enter data for right of "<<curr->data<<endl;
        cin>>data;
        if(data!=-1){
            node * right = new node(data);
            curr->right = right;
            q.push(right);
        }
    }
    return root;
}
void preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void inorder(node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void postorder(node * root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}


int maxNode(node * root){
    if(!root){
        return INT_MIN;
    }
    int left = maxNode(root->left);
    int right = maxNode(root->right);
    return max(root->data,max(right,left));
}

int height(node * root){
    if(!root){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1;
}

void printAtDiffLevel(node * root){
    queue<node *>q1;
    queue<node *>q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            node * top = q1.front();
            cout<<top->data<<" ";
            q1.pop();
            if(top->left){
                q2.push(top->left);
            }
            if(top->right){
                q2.push(top->right);
            }
        }
        cout<<endl;
        while(!q2.empty()){
            node * top = q2.front();
            cout<<top->data<<" ";
            q2.pop();
            if(top->left){
                q1.push(top->left);
            }
            if(top->right){
                q1.push(top->right);
            }
        }
        cout<<endl;
    }
}

bool find(node * root,int data){
    if(!root){
        return false;
    }
    if(root->data==data){
        return true;
    }
    bool left = find(root->left,data);
    bool right = find(root->right,data);
    return left||right;
}

//Test for input : 8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main(){

node * root= createTree();
cout<<"LevelWise Printing : "<<endl;
printAtDiffLevel(root);
cout<<"preorder Traversal :";
preorder(root);
}
