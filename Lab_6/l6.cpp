#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	long long int q;
	cin>>q;
	vector <long long int> vraw;
	vector <long long int> v1;
	vector <long long int> v2;
	vector <long long int> :: iterator it;
	vector <long long int> in1;
	vector <long long int> in2;
	vector <long long int> in3;
	while(q--)
	{
		int a;
		cin>>a;
		in1.push_back(a);
		if(a==1)
		{
			int b, c;
			cin>>b>>c;
			in2.push_back(b);
			in3.push_back(c);
		}
		else if(a==2)
			{in2.push_back(0);in3.push_back(0);}
	}
	for(int i=0;i<in1.size();++i)
	{
		if(in1[i]==1)vraw.push_back(in2[i]);
	}
	sort(vraw.begin(), vraw.end());
	v1.push_back(vraw[0]);
	for(int i=1;i<vraw.size();++i)
	{
		if(vraw[i]!=vraw[i-1])v1.push_back(vraw[i]);
	}
	for(int i=0;i<v1.size();++i){v2.push_back(0);}
	int max=0, id=0;
	for(int i=0;i<in1.size();++i)
	{
		if(in1[i]==1)
		{
			int k=in2[i];
			it=lower_bound(v1.begin(), v1.end(), k);
			v2[it-v1.begin()]+=in3[i];
			if(v2[it-v1.begin()]>max)
			{
				max=v2[it-v1.begin()];
				id=*it;			}
		}
		else if(in1[i]==2)
		{
			if(id==0)cout<<"No data available"<<endl;
			else cout<<id<<endl;
		}
	}
	return 0;
}
