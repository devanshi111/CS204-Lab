// From the given array construct a BST and print the inorder traversal

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node* left;
	struct node* right;
};

struct node* newNode(int d)
{
	node* n=new node();
	n->key=d;
	n->left=NULL;
	n->right=NULL;
	return n;
}

struct node* insert(struct node* root, int k)
{
	if(root==NULL)return newNode(k);
	if(k<root->key)
		root->left=insert(root->left, k);
	else if(k>root->key)
		root->right=insert(root->right, k);
	return root;
}

struct node* search(struct node* root, int k)
{
	if(root==NULL)return root;
	if(k==root->key)return root;
	else if(k<root->key)return search(root->left, k);
	else return search(root->right, k);
}

struct node* minNode(struct node* root)
{
	struct node* temp=root;
	if(root==NULL)return root;
	while(temp->left!=NULL)temp=temp->left;
	return temp;
}

struct node* deleteNode(struct node* root, int k)
{
	if(root==NULL)return root;
	if(k<root->key)
		root->left=deleteNode(root->left, k);
	else if(k>root->key)
		root->right=deleteNode(root->right, k);
	else
	{
		if(root->right==NULL)
		{
			struct node* temp=root->left;
			free(root);
			return temp;
		}

		else if(root->left==NULL)
		{
			struct node* temp=root->right;
			free(root);
			return temp;
		}
		struct node*temp=minNode(root->right);
		root->key=temp->key;
		root->right=deleteNode(root->right, temp->key);
	}
	return root;
}

struct node* maxValue(struct node* root)
{
	struct node* temp=root;
	if(root==NULL)return root;
	while(temp->right!=NULL)
		temp=temp->right;
	return temp;
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
