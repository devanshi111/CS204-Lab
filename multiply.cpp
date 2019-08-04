#include<bits/stdc++.h>
using namespace std;

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
		if(inp==' '||inp=='\n')break;
		a.push_back(inp);
	}
	while(1)
	{
		inp=getchar();
		if(inp==' '||inp=='\n')break;
		b.push_back(inp);
	}
	int n=a.size();
	int m=b.size();
	if(m>n)swap(a, b);

	n=a.size(), m=b.size();
	vector <int> res(n+m, 0);
	int p1=0, p2=0;
	for(int i=n-1;i>=0;--i)
	{
		int c=0;
		p1=0;
		for(int j=m-1;j>=0;--j)
		{
			int sum=(a[i]-'0')*(b[j]-'0')+res[p1+p2]+c;
			c=sum/10;
			res[p1+p2]=sum%10;
			p1++;
		}
		if(c>0)res[p1+p2]+=c;
		p2++;
	}

	int pos=res.size()-1;
	while(pos>=0&&res[pos]==0)pos--;
	if(pos<0)cout<<0;
	else
	{
		while(pos>=0)cout<<res[pos--];
	}
	cout<<endl;
	}
	return 0;
}
