#include<bits/stdc++.h>
using namespace std;

class node
{
	int data;
	node* next;
};

class queue
{
	node, *front, *rear;
};

node* newNode(int d)
{
	node* temp= new node();
	temp->data=d;
	temp->next=NULL;
	return temp;
}

queue* retQueue()
{
	queue* q=new queue();
	q->front=NULL;
	q->rear=NULL;
	return q;
}

void enqueue(queue* q, int k)
{
	node* temp=newNode(k);
	if(q->rear==NULL)
		{q->front=q->rear=temp;return;}
	(q->rear)->next=temp;
	q->rear=temp;
}

int dequeue(queue* q)
{
	if(q->front==NULL)return NULL;
	node* temp=q->front;
	q->front=temp->next;
	int d=temp->data;
	free(temp);
	if(q->front==NULL)
		q->rear=NULL;
	return d;
}

