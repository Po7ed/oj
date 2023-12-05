#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> sim(string s)
{
	vector<char> r;
	for(char c:s)
	{
		if(c=='<')
		{
			if(!r.empty())
				r.pop_back();
		}
		else
			r.push_back(c);
	}
	return r;
}

int main()
{
	int ans=0,time;
	vector<vector<char>> fw,dz;
	string s;
	getline(cin,s);
	while(s!="EOF")//fw
	{
		fw.push_back(sim(s));
		getline(cin,s);
	}
	getline(cin,s);
	while(s!="EOF")//dz
	{
		dz.push_back(sim(s));
		getline(cin,s);
	}
	cin>>time;
	int l=fw.size(),ll;
	for(int i=0;i<l;i++)
	{
		ll=min(fw[i].size(),dz[i].size());
		for(int j=0;j<ll;j++)
		{
			if(fw[i][j]==dz[i][j])
			{
				ans++;
			}
		}
	}
	printf("%d",ans*60/time);
}