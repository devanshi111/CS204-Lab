#include<bits/stdc++.h>
using namespace std;

bool bip(vector<vector <int>> v, int n)
{
	bool vis[n]={0};
	queue <int> q;
	int col[n]={0};
	for (int i=0;i<n;++i)
	{
		//q.push(i);
		//q.pop();
		if(vis[i])continue;
		else
		{
			col[i]=1;
			for (int j=0;j<v[i].size();++j)
			{
				if(col[v[i][j]]==col[i])return false;
				col[v[i][j]]=0-col[i];
				q.push(v[i][j]);
			}
			vis[i]=1;
		}
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(vis[u])continue;
			else
			{
			for (int j=0;j<v[i].size();++j)
			{
				if(col[v[u][j]]==col[u])return false;
				col[v[u][j]]=0-col[u];
				q.push(v[u][j]);
			}
			vis[u]=1;
		}
		}
	}
	return true;
}

int main()
{
	int n, m;
	cin>>n>>m;
	vector <vector <int>> adj(n+m);
	//int f=0;
	for (int i=0;i<m;++i)
	{
		int a, b, c;
		cin>>a>>b>>c;
		if(c%2==1){
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
		}
		else
		{
			n++;
			adj[a-1].push_back(n-1);
			adj[b-1].push_back(n-1);
			adj[n-1].push_back(a-1);
			adj[n-1].push_back(b-1);
			//f++;
		}
	}
	if(bip(adj, n))cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
