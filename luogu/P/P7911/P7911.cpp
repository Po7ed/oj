#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

string g;
string get()
{
	cin>>g;
	int a,b,c,d,e;
	char d1,d2,d3,c4;
	sscanf(g.c_str(),"%d%c%d%c%d%c%d%c%d",&a,&d1,&b,&d2,&c,&d3,&d,&c4,&e);
	if(d1!='.'||d2!='.'||d3!='.'||c4!=':'||
	a<0||b<0||c<0||d<0||e<0||a>255||b>255||c>255||d>255||e>65535)
	{
		return "x";
	}
	stringstream ss;
	ss<<a<<'.'<<b<<'.'<<c<<'.'<<d<<':'<<e;
	string t=ss.str();
	if(t!=g)
	{
		return "x";
	}
	return t;
}

map<string,int> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	string type,ip;
	for(int i=1;i<=n;i++)
	{
		cin>>type;
		ip=get();
		if(ip=="x")
		{
			cout<<"ERR"<<"\n";
			continue;
		}
		if(type[0]=='S')
		{
			if(m[ip])
			{
				cout<<"FAIL"<<"\n";
			}
			else
			{
				m[ip]=i;
				cout<<"OK"<<"\n";
			}
		}
		else
		{
			if(m[ip])
			{
				cout<<m[ip]<<"\n";
			}
			else
			{
				cout<<"FAIL"<<"\n";
			}
		}
	}
	return 0;
}