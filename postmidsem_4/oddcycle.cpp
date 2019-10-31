#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector <vector<int>> v,int src ,int * colour)
{
	bool flag =1;
	
	for(int i=0;i<v[src].size();i++)
	{
		if(colour[v[src][i]]==0)
		{
			colour[v[src][i]]=0-colour[src];
			flag=flag&bipartite(v,i ,colour);
		}
		else if((colour[v[src][i]]==1&&colour[src]==1)||(colour[v[src][i]]==-1&&colour[src]==-1))
		{
			return 0;
		}
	}
		
		return flag;
}

int main()
{

	long long int n, m;
	cin>>n>>m;
	vector <vector<int>> adj(n+m);
	int t=0;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(c%2==1)
		{
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
		}
		else
		{
			adj[n+t].push_back(a-1);
			adj[n+t].push_back(b-1);
			adj[a-1].push_back(n+t);
			adj[b-1].push_back(n+t);
			t++;
		}
	}

	int colour[n]={0};
	bool ans=1;
	for(int i=0;i<n+t;i++)
	{
		if(colour[i]==0)
		{
			colour[i]=1;
		    ans=bipartite(adj,i,colour);

		}
		if(ans==0)break;
	}

	if(ans) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
