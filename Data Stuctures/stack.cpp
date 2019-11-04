// Check if a sequence of brackets is valid or not. Characters other than round brackets are not permitted.

#include<bits/stdc++.h>
using namespace std;

struct snode
{
	int val;
	snode *next;
};

snode* newNode(int v)
{
	snode* n=new snode();
	n->val=v;
	n->next=NULL;
	return n;
}

bool isEmpty(snode* root)
{
	if(root==NULL)return 1;
	return 0;
}

void push(snode** root, int v)
{
	snode* n=newNode(v);
	n->next=*root;
	*root=n;
}

int pop(snode** root)
{
	if(isEmpty(*root))
		return INT_MIN;
	snode* temp=*root;
	*root=(*root)->next;
	int r=temp->val;
	free(temp);
	return r;
}

int peek(snode* root)
{
	if(isEmpty(root))return INT_MIN;
	return root->val;
}

int main()
{
	string s;
	cin>>s;
	snode* root=NULL;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='(')
		{
			push(&root, 1);
		}
		else if(s[i]==')')
		{
			if(isEmpty(root))
				{cout<<"Invalid"<<endl;return 0;}
			if(peek(root)==1){pop(&root);}
		}
		else
			{cout<<"Restricted Input"<<endl;return 0;}
	}
	if(isEmpty(root))
		{cout<<"Valid"<<endl;}
	else 
		cout<<"Invalid"<<endl;
	return 0;

}
