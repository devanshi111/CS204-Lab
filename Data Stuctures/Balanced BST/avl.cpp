// From the given array construct a balanced BST and print the inorder traversal

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node* left;
	struct node* right;
	int h;
};

struct node* newNode(int k)
{
	struct node* n=new node();
	n->key=k;
	n->right=NULL;
	n->left=NULL;
	n->h=1;
	return n;
}

int height(struct node* n)
{
	if(n==NULL)
		return 0;
	return n->h;
}

struct node* rr(struct node* y)
{
	node* x=y->left;
	node* z=x->right;

	x->right=y;
	y->left=z;

	y->h=max(height(y->left), height(y->right))+1;
	x->h=max(height(x->left), height(x->right))+1;

	return x;
}

struct node* lr(struct node* x)
{
	node* y=x->right;
	node* z=y->left;

	y->left=x;
	x->right=z;
	x->h=max(height(x->left), height(x->right))+1;
	y->h=max(height(y->left), height(y->right))+1;

	return y;
}

int balance(struct node* n)
{
	if(n==NULL)return 0;
	return height(n->left)-height(n->right);
}

struct node* insert(struct node* root, int key)
{
	if(root==NULL)
		return newNode(key);
	if(key<root->key)
		root->left=insert(root->left, key);
	else if(key>root->key)
		root->right=insert(root->right, key);
	else
		return root;
	root->h=1+max(height(root->left), height(root->right));
	int bh=balance(root);

	if (bh>1 && key < (root->left)->key)  
        return rr(root); 

    if (bh < -1 && key > (root->right)->key)  
        return lr(root); 
    if (bh > 1 && key > (root->left)->key)  
    {  
        root->left = lr(root->left);  
        return rr(root);  
    }  
    if (bh < -1 && key < (root->right)->key)  
    {  
        root->right = rr(root->right);  
        return lr(root);  
    }  
    return root;
}

struct node * minNode(node* root)  
{  
    node* current = root;  
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  



struct node* deleteNode(node* root, int key)  
{  
      
    
    if (root == NULL)  
        return root;  
  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
 
    else if( key > root->key )  
        root->right = deleteNode(root->right, key); 
    else
    {  
  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
           
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            } 
            else 
            *root = *temp;
            free(temp);  
        }  
        else
        {
            node* temp = minNode(root->right);  
  
            root->key = temp->key;  

            root->right = deleteNode(root->right,  
                                     temp->key);  
        } 
        if (root == NULL)  
            return root;  
  
    
    root->h = 1 + max(height(root->left),  
                           height(root->right));  
  
    int bh = balance(root);  
    
    
    if (bh>1 && key < (root->left)->key)  
        return rr(root); 

    if (bh < -1 && key > (root->right)->key)  
        return lr(root); 
    if (bh > 1 && key > (root->left)->key)  
    {  
        root->left = lr(root->left);  
        return rr(root);  
    }  
    if (bh < -1 && key < (root->right)->key)  
    {  
        root->right = rr(root->right);  
        return lr(root);  
    }  
    return root; 
    }
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}	
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i)cin>>arr[i];
	struct node* root=NULL;
	for(int i=0;i<n;++i)
	{
		root=insert(root, arr[i]);
	}
	inorder(root);
	return 0;
}
