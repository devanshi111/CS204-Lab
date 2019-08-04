#include<bits/stdc++.h>
using namespace std;

string addstr(string str1, string str2)
{

    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";
  	int n1 = str1.length(), n2 = str2.length();
  	reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
  	int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
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
  	string ans="";
  	int a=0;
  	for(int i=0;i<str.length();++i)
  	{
  		if(str[i]!='0')
  			a=1;
  		if(a==1)
  			ans.push_back(str[i]);
       // if(i==str.length()-1&&a==0&&str[i]=='0')
         //   ans.push_back('0');
  	}
    if(ans=="")ans="0";
    return ans;
}

string rem(string a, string b)
{
		int n=a.length();
        int m=b.length();
        if(n<m)
        {
            return a;
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
                //cout<<q1<<" ";
                q.push_back(q1+'0');
                if(pos<n)
                {r.push_back(a[pos]);}
                int j=0;
                for(;j<r.length();j++)if(r[j]!='0')break;
                if(j==r.length())r="0";
                pos++;
            }
            return r;
		}
}

int main()
{
	int t;
	cin>>t;
	cin>>ws;
	while(t--)
	{
		string a;
		cin>>a;
		int n=a.length();
		if(n==1&&a=="1"){cout<<"Not a Prime"<<endl;}
        else if(n==1&&a=="2"){cout<<"Prime"<<endl;}
		else
		{
			string b="2";bool ip=true;
			while(b.length()<=(n/2+1)&&isSmaller(b, a))
			{
				string r=rem(a, b);
				if(r=="0"){cout<<"Not a Prime"<<endl;ip=false;break;}
				b=addstr(b, "1");

			}
			if(ip==true)cout<<"Prime"<<endl;
		}

	}
	return 0;
}
