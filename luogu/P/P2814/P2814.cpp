#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string,string> f;

string Find(string x)
{
	return (f.count(x)?f[x]=Find(f[x]):x);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char c/* =getchar() */;
	cin>>c;
	string fa,s;
	while(c!='$')
	{
		cin>>s;
		if(c=='#') 
		{
			fa=s;
		}
		else if(c=='+')
		{
			f[Find(s)]=Find(fa);
		}
		else
		{
			cout<<s<<" "<<Find(s)<<"\n";
		}
		cin>>c;
		// getchar();
		// c=getchar();
		// cout<<"*"<<c<<"\n";
	}
	return 0;
}