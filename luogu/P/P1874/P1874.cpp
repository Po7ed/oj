#include <iostream>
using namespace std;

int n,l;
string s;

int sum,cnt;

void dfs(int dep=0)
{
	// printf("dep:%d sum:%d cnt:%d\n",dep,sum,cnt);
	if(dep>=l)
	{
		// puts("end");
		if(sum==n)
		{
			printf("%d",cnt-1);
			exit(0);
		}
		return;
	}
	if(sum>n)
	{
		return;
	}
	cnt++;
	int p;
	for(int i=min(l,dep+6);i>=dep;i--)
	{
		// cout<<s.substr(dep,i-dep+1)<<"\n";
		p=stoi(s.substr(dep,i-dep+1));
		sum+=p;
		dfs(i+1);
		sum-=p;
	}

	cnt--;
	return;
}

int main()
{
	cin>>s;
	l=s.length();
	scanf("%d",&n);
	if(!n)
	{
		if(stoi(s)==0)
		{
			puts("0");
		}
		else
		{
			puts("-1");
		}
		return 0;
	}
	dfs();
	puts("-1");
	return 0;
}