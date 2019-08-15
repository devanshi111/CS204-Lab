#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x, y;
	struct node* ptr;
};

struct node* start;

struct node* newNode(int x1, int y1)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->x=x1;
	temp->y=y1;
	temp->ptr=NULL;
	return temp;
}

int AddFirst(int x1, int y1)
{
	if (start==NULL){start=newNode(x1, y1);return 0;}
	struct node* temp=newNode(x1, y1);
	temp->ptr=start;
	start=temp;
	return 0;
}

int DelFirst()
{
	if(start==NULL){cout<<-1<<endl;return 0;}
	struct node* temp=start;
	start=temp->ptr;
	free(temp);
	return 0;
}

int Del(int x1, int y1)
{
	if(start==NULL){cout<<-1<<endl;return 0;}
	
	if(start->x==x1&&start->y==y1)
	{
		struct node* temp=start;
		start=temp->ptr;
		free(temp);
	}
	struct node* temp=start->ptr;
	struct node* prev=start;
	while(temp!=NULL)
	{
		if(temp->x==x1&&temp->y==y1)
		{
			prev->ptr=temp->ptr;
			free(temp);
			return 0;
		}
		prev=temp;
		temp=temp->ptr;
	}
	if(temp==NULL){cout<<-1<<endl;return 0;}
	//return 0;
}

void Search(float d)
{
	struct node* temp=start;
	int c=0;
	while(temp!=NULL)
	{
		int dist=(temp->x)*(temp->x)+(temp->y)*(temp->y);
		if(dist<=d*d){c++;}
		temp=temp->ptr;
	}
	if(c==0)cout<<-1<<endl;
	else {cout<<c<<endl;}
}

bool Search_pt(int x1, int y1)
{
	struct node* temp=start;
	while(temp!=NULL)
	{
		if(temp->x==x1&&temp->y==y1)return true;temp=temp->ptr;
	}
	return false;
}

int length()
{
	int c=0;
	struct node* temp=start;
	while(temp!=NULL)
	{
		temp=temp->ptr;
		c++;
	}
	return c;
}

int main()
{
	start=NULL;
	long long int q;
	cin>>q;
	while(q--)
	{
		int a, b, c;
		cin>>a;
		if(a==1)
		{
			cin>>b>>c;
			AddFirst(b, c);
		}
		else if(a==2)
		{
			DelFirst();
		}
		else if(a==3)
		{
			cin>>b>>c;
			Del(b, c);
		}
		else if(a==4)
		{
			float f;
			cin>>f;
			Search(f);
			
		}
		else if(a==5)	
		{
			cin>>b>>c;
			if(Search_pt(b,c))cout<<"True";
			else{cout<<"False";}
			cout<<endl;
		}
		else if(a==6)
			{cout<<length()<<endl;}

	}
	return 0;
}
