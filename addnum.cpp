#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int main()
{
	int t;
	cin>>t;
	cin>>ws;
	while(t--)
	{
	vector <char> a;
	vector <char> b;
	char inp;
	while(1)
	{
		inp=getchar();
		if(inp==' '||inp=='\n'){break;}
		a.pb(inp);
	}

	while(1)
	{
		inp=getchar();
		if(inp==' '||inp=='\n'){break;}
		b.pb(inp);
	}

	vector<char> a1;
	vector <char> b1;
	int n=a.size();
	int m=b.size();
	if(n>m)
	{
		for(int i=0;i<n-m;++i)b1.pb('0');
		for(int i=n-m;i<n;++i)b1.pb(b[i-n+m]);
		for(int i=0;i<n;++i)a1.pb(a[i]);
	}

	else if(m>n)
	{
		for(int i=0;i<m-n;++i)a1.pb('0');
		for(int i=m-n;i<m;++i)a1.pb(a[i-m+n]);
		for(int i=0;i<m;++i)b1.pb(b[i]);
	}

	else
		{
		    for(int i=0;i<n;++i)a1.pb(a[i]);
		    for(int i=0;i<m;++i)b1.pb(b[i]);
		}

	vector <char> d;
	int c=0;
	for(int i=max(m, n)-1;i>=0;--i)
	{
		int sum=a1[i]-'0'+b1[i]-'0'+c;
		if(sum>=10)
			{sum-=10;c=1;}
		else
			c=0;
		d.pb(sum+'0');

	}
	if(c>0)
		d.pb(c+'0');
	for(int i=d.size()-1;i>=0;--i)cout<<d[i];
	cout<<endl;

	}
	return 0;
}
