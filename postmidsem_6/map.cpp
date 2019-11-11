#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		map <string, int> mp;
		int a=0;
		for(int i=0;i<s.length();++i)
		{
			string s1="";
			string s2;
			if(a==1)break;
			for(int j=i;j<s.length();++j)
			{
				s1.push_back(s[j]);
				s2=s1;
				mp.insert({s1, 0});
				reverse(s2.begin(), s2.end());
				if(s2!=s1 && mp.find(s2)!=mp.end())
				{a=1;cout<<"YES"<<endl;break;}
			}
			
		}
		if(a==0)cout<<"NO"<<endl;

	}
	return 0;
}
