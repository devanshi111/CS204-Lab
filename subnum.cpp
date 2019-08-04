#include<bits/stdc++.h>
using namespace std;

bool isSmaller(vector <char> v1, vector <char> v2)
{
    int n1 = v1.size(), n2 = v2.size();

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1; i++)
    if (v1[i]-'0' < v2[i]-'0')
        return true;
    else if (v1[i]-'0' > v2[i]-'0')
        return false;

    return false;
}

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

	if(isSmaller(a, b))swap(a, b);
	int n=a.size(), m=b.size();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	vector <char> d;
	int c = 0;
    for (int i=0;i<m;i++)
    {
        int sub=((a[i]-'0')-(b[i]-'0')-c);

        if (sub<0)
        {
            sub+=10;
            c=1;
        }
        else
            c=0;

        d.push_back(sub+'0');
    }


    for (int i=m;i<n;++i)
    {
        int sub=((a[i]-'0')-c);


        if (sub<0)
        {
            sub+=10;
            c=1;
        }
        else
            c=0;

        d.push_back(sub + '0');
    }


    reverse(d.begin(), d.end());
    for(int i=0;i<d.size();++i){cout<<d[i];}
    cout<<endl;
	}
    return 0;
}
