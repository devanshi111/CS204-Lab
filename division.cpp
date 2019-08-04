#include<bits/stdc++.h>
using namespace std;

string diff(string str1, string str2)
{

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int c = 0;

    for (int i=0; i<n2; i++)
    {

        int sub = ((str1[i]-'0')-(str2[i]-'0')-c);

        if (sub < 0)
        {
            sub = sub + 10;
            c = 1;
        }
        else
            c = 0;

        str.push_back(sub + '0');
    }

    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - c);

        if (sub < 0)
        {
            sub = sub + 10;
            c = 1;
        }
        else
            c = 0;

        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());
  	string ans;
  	int a=0;
  	for(int i=0;i<str.length();++i)
  	{
  		if(str[i]!='0')
  			a=1;
  		if(a==1)
  			ans.push_back(str[i]);
        if(i==str.length()-1&&a==0&&str[i]=='0')
            ans.push_back('0');
  	}
    return ans;
}


bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1; i++)
    if (str1[i] < str2[i])
        return true;
    else if (str1[i] > str2[i])
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
		string a, b;
		cin>>a>>b;

		int n=a.length();
		int m=b.length();
		if(n<m)
		{
			cout<<0<<endl;
			cout<<a<<endl;
		}
		else
		{
			string r;
			string q;
			int pos;
			for(pos=0;pos<m;++pos)r.push_back(a[pos]);
			if(isSmaller(r, b)){r.push_back(a[pos]);pos++;}

			while(pos<=n)
			{
				int q1=0;
				while(!isSmaller(r, b)){r=diff(r, b);q1++;}
				q.push_back(q1+'0');
				if(pos<n)
				{r.push_back(a[pos]);}
				pos++;
			}
			cout<<q<<endl;
			cout<<r<<endl;
		}
	}
	return 0;
}
