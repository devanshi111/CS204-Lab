#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
typedef pair<int, int> pi;  

void prim(vector<pair<ll,ll> > adj[], ll n)
{
    ll weight[n];
    ll parent[n];
    int visited[n] = {0};
    for(ll i=0;i<n;i++)
    {
        weight[i] = INT_MAX;
        parent[i] = -1;
    }

    parent[0] = 0;
    weight[0] = 0;

    priority_queue< pi, vector <pi> , greater<pi> > pq; 
    pq.push(make_pair(0,0));
    
    while(!pq.empty())
    {
        ll cv = pq.top().second;
        ll cvw = pq.top().first;
        pq.pop();
        visited[cv] = 1;
        for(ll i=0;i<adj[cv].size();i++)
        {
            ll ng = adj[cv][i].first;
            ll ngw = adj[cv][i].second;
            if(!visited[ng] && weight[ng]>ngw)
            {
                weight[ng] = ngw;
                pq.push(make_pair(ngw,ng));
                parent[ng] = cv;
            }
        }
    }
    int minc=0;
    for(ll i=1;i<n;i++)
    {
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        minc+=weight[i];
    }
    cout<<w[i]<<endl;
    
    
}
 
int main()
{
    
    ll v,e;
    cin>>v>>e;
    vector<pair<ll,ll> > adj[v];
    for(ll i=0;i<e;i++)
    {
        ll x,y,w;
        cin>>w>>x>>y;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }
    
    prim(adj,v);
    
    return 0;
}
