#include<bits/stdc++.h>
using namespace std;

map <string, int> mp;

map <string, int> :: iterator itm;

vector <string> :: iterator itv;

int valid=0;

int ch=0;

int prec(string c)
{
    if(c == "^")
    return 3;
    else if(c == "*" || c == "/")
    return 2;
    else if(c == "+" || c == "-")
    return 1;
    else
    return -1;
}

bool isNum(string s)
{
	if(s[0]<='9'&&s[0]>='0')return true;
	return false;
}

bool isVar(string s)
{

	if((s[0]<='z'&&s[0]>='a')||(s[0]>='A'&&s[0]<='Z'))return true;
	return false;
}

vector <string> post(vector <string> v)
{
    vector <string> ans;
    stack <string> st;
    st.push("N");
    int l=v.size();

    for(int i=0;i<l;++i)
    {
        if(isNum(v[i])||isVar(v[i]))ans.push_back(v[i]);

        else if(v[i]=="(")st.push("(");

        else if(v[i]==")")
        {
            while(st.top() != "N" && st.top() != "(" )
            {
                string c = st.top();
                st.pop();
                ans.push_back(c);
            }
            if(st.top() == "(")
            {
                string c = st.top();
                st.pop();
            }
        }
        else if (v[i]=="+"||v[i]=="-"||v[i]=="*"||v[i]=="/"||v[i]=="^")
        {
            while(st.top() != "N" && prec(v[i]) <= prec(st.top()))
            {
                if(prec(v[i])==3&&prec(st.top())==3)break;
                string c = st.top();
                st.pop();
                ans.push_back(c);
            }
            st.push(v[i]);
        }
    }
    while(st.top() != "N")
    {
        string c = st.top();
        st.pop();
        ans.push_back(c);
    }

    return ans;
}

struct et
{
    string value;
    et* left, *right;
};

bool isOperator(string c)
{
    if (c == "+" || c == "-" ||
            c == "*" || c == "/" ||
            c == "^")
        return true;
    return false;
}

et* newNode(string v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

int toInt(string s)
{
    int num=0;
    for(int i=0;i<s.length();++i)
        num=num*10+(s[i]-'0');
    return num;
}



int varValue(string s)
{
	ch=0;
	itm=mp.find(s);
	if(itm!=mp.end())return itm->second;
	valid++;ch++;
	return 0;
}

et* constructTree(vector <string> v)
{
    stack<et *> st;
    et *t, *t1, *t2;

    for (int i=0; i<v.size(); i++)
    {
    	if(isVar(v[i])){v[i]=to_string(varValue(v[i]));}

        if (!isOperator(v[i]))
        {
            t = newNode(v[i]);
            st.push(t);
        }
        else
        {
            t = newNode(v[i]);


            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();


            t->right = t1;
            t->left = t2;


            st.push(t);
        }
    }

    t = st.top();
    st.pop();

    return t;
}

int eval(et* root)
{

    if (!root)
        return 0;


    if (!root->left && !root->right)
        return toInt(root->value);


    int l_val = eval(root->left);


    int r_val = eval(root->right);


    if (root->value=="+")
        return l_val+r_val;

    if (root->value=="-")
        return l_val-r_val;

    if (root->value=="*")
        return l_val*r_val;

    if (root->value=="/")
        return int(l_val/r_val);
    if (root->value=="^")
        return int(pow(l_val, r_val));
    //return 0;
}


int main()
{
    int q;
    cin>>q;
    while(q--)
    {
    int n;
    cin>>n;
    while(n--)
    {
    string in;
    cin>>in;
    vector <string> v;
    string t;
    //int valid=0;
    for(int i=0;i<in.length();++i)
    {
        if(in[i]-'0'<=9&&in[i]-'0'>=0)t.push_back(in[i]);
        else if((in[i]>='a'&&in[i]<='z')||(in[i]>='A'&&in[i]<='Z'))
        {
        	t.push_back(in[i]);
        }
        else
        {
           // if(in[i]!='('&&in[i]!=')'&&in[i]!='+'&&in[i]!='-'&&in[i]!='*'&&in[i]!='/'&&in[i]!='^'){valid++;break;}
            if(t=="0"){v.push_back("00");}
            else
            {v.push_back(t);}
            t="";
            if(in[i]=='-'&&in[i-1]=='('){v.push_back("00");}
            t.push_back(in[i]);
            v.push_back(t);
            t="";
        }
    } 
    v.push_back(t);
    //if(valid!=0){cout<<"INVALID OUTPUT"<<endl;}
    //else
    //{
    //v.push_back(t);
    itv = find(v.begin(), v.end(), "=");
    if(itv != v.end())
    {
    	vector <string> v1;
    	itv++;
    	for(;itv<v.end();itv++){v1.push_back(*itv);}
    	int flag=0;
    	for(int i=0;i<v1.size();++i)
    	{
    		if(isVar(v1[i])){int a=varValue(v1[i]);if(ch!=0){flag++;ch=0;}}
    	}
    	if(flag!=0){if(valid!=0){valid=0;}cout<<"CANNOT BE EVALUATED"<<endl;continue;}
    	v1=post(v1);
    	et* root = constructTree(v1);
    	int val=eval(root);
    	itm=mp.find(v[0]);
    	if(itm!=mp.end()){itm->second=val;}
    	else{mp.insert(pair<string, int>(v[0], val));}
    }
    else
    {
    int flag=0;
    for(int i=0;i<v.size();++i)
    	{
    		if(isVar(v[i])){int a=varValue(v[i]);if(ch!=0){flag++;ch=0;}}
    	}
    if(flag!=0){if(valid!=0){valid=0;}cout<<"CANNOT BE EVALUATED"<<endl;continue;}
    v=post(v);
	et* root= constructTree(v);
    if(valid!=0){cout<<"CANNOT BE EVALUATED"<<endl;valid=0;}

    else{cout<<eval(root)<<endl;}
	}
	//for(int i=0;i<v.size();++i)cout<<v[i]<<" ";
    }
    mp.clear();
    }
    return 0;
}
