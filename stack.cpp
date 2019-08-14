#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		stack <char> s;
		string in;
		cin>>in;
		int f=0;
		for(int i=0;i<in.length();++i)
		{
			if(in[i]=='(')s.push('(');
			else if(in[i]=='{')s.push('{');
			else if(in[i]=='<')s.push('<');
			else if(in[i]=='[')s.push('[');
			else if(in[i]=='|')
			{
				if(!s.empty()&&s.top()=='|')s.pop();
				else s.push('|');
			}
			else if(in[i]==')')
			{
				if(!s.empty()&&s.top()=='(')s.pop();
				else {f++;break;}
			}
			else if(in[i]=='}')
			{
				if(!s.empty()&&s.top()=='{')s.pop();
				else {f++;break;}
			}
			else if(in[i]=='>')
			{
				if(!s.empty()&&s.top()=='<')s.pop();
				else {f++;break;}
			}
			else if(in[i]==']')
			{
				if(!s.empty()&&s.top()=='[')s.pop();
				else {f++;break;}
			}
			else {f++;break;}
		}
		if(!s.empty())f++;
		if(f==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
