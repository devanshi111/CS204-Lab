#include<bits/stdc++.h>
using namespace std;

int comp(string a, string b)
{
	string ab=a.append(b);
	string ba=b.append(a);
	if(ab.compare(ba)>0)return 1;
	return 0;
}

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		vector <string> in;
		int t;
		cin>>t;
		for(int i=0;i<t;++i)
		{
			string s;
			cin>>s;
			in.push_back(s);
		}
		sort(in.begin(), in.end(), comp);
		for(int i=0;i<in.size();++i)cout<<in[i];
		cout<<endl;
	}
	return 0;
}
