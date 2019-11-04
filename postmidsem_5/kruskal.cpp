#include<bits/stdc++.h>
using namespace std;

int comp=1000000007;

bool rev(const pair <long long, pair<int, int> > &a,  const pair <long long, pair<int, int> > &b) 
{ 
       return (a.first > b.first); 
} 


long long int setRep(long long int * id, long long int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(long long int x, long long int y, long long int* id)
{
    long long int p = setRep(id, x);
    long long int q = setRep(id, y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<long long int, long long int> > p[], long long int e, long long int* id)
{
    long long int x, y;
    long long cost, minCost = 1;
    for(long long int i = 0;i < e;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if(setRep(id, x) != setRep(id, y))
        {
            minCost = ((cost*minCost)%comp)%comp;
            union1(x, y, id);
        }    
    }
    return minCost;
}

int main()
{
    long long int n, e;
    long long w, cost, minCost;
    
    cin >> n >> e;
    long long int x, y;
    long long int id[n];
    pair <long long, pair<long long int, long long int> > p[e];
    for(long long int i=0;i<n;++i)id[i]=i;
    for(long long int i = 0;i < e;++i)
    {
        cin >> x >> y >> w;
        p[i] = make_pair(w, make_pair(x-1, y-1));
    }
    
    sort(p, p + e, rev);
    minCost = kruskal(p, e, id);
    cout << minCost << endl;
    return 0;
}
