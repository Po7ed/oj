#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> m;
string s;
int dfs(int dep=0)
{
	bool p=false;
	if(m.count(s))
	{
		return m[s];
	}
	if(s.find("LOL")!=string::npos)
	{
		return m[s]=-1;
	}
	if(s.find("*")==string::npos)
	{
		return m[s]=0;
	}
	for(char &c:s)
	{
		if(c=='*')
		{
			c='L';
			int t=dfs((dep+1)&1);
			c='*';
			if(t==-1)
			{
				return m[s]=1;
			}
			if(t==0)
			{
				p=true;
			}
			c='O';
			t=dfs((dep+1)&1);
			c='*';
			if(t==-1)
			{
				return m[s]=1;
			}
			if(t==0)
			{
				p=true;
			}
		}
	}
	if(p)
	{
		return m[s]=0;
	}
	else
	{
		return m[s]=-1;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s.length()<3)
		{
			puts("0");
			continue;
		}
		printf("%d\n",dfs());
	}
	return 0;
}