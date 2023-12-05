#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	map<string,int> p,q;
	// string w=" ";
	string s;
	int a;
	vector<string> name;
	vector<pair<string,int>> c;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>a;
		c.push_back({s,a});
		if(p.count(s)==0)
		{
			p[s]=0;
			name.push_back(s);
		}
		p[s]+=a;
	}
	int m=-1,l=name.size();
	for(int i=0;i<l;i++)
	{
		m=max(m,p[name[i]]);
	}
	for(int i=0;i<n;i++)
	{
		q[c[i].first]+=c[i].second;
		if(q[c[i].first]>=m&&p[c[i].first]==m)
		{
			cout<<c[i].first<<endl;
			return 0;
		}
	}
	// cout<<w<<endl;
	return 0;
}