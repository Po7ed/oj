#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

vector<char> e[128];
int deg[128];
int cnt;

vector<char> ans;
// bitset<128> vis;
int beg[128];
void dfs(char now,char pre='\0')
{
	// for(char son:e[now])
	for(int i=beg[now];i<deg[now];i=max(i+1,beg[now]))
	{
		if(e[now][i]!=pre)
		{
			beg[now]++;
			dfs(e[now][i],now);
		}
	}
	ans.push_back(now);
}

int main()
{
	int n;
	scanf("%d",&n);
	char u,v;
	for(int i=1;i<=n;i++)
	{
		u=getchar();
		while(!isalpha(u))
		{
			u=getchar();
		}
		v=getchar();
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	char beg1='\0',beg2='\0';
	for(char i=0;i<127;i++)
	{
		if(deg[i])
		{
			sort(e[i].begin(),e[i].end());
		}
		if(deg[i]&1)
		{
			cnt++;
			if(beg1=='\0')
			{
				beg1=i;
			}
		}
		else if(deg[i]&&beg2=='\0')
		{
			beg2=i;
		}
	}
	if(cnt==0||cnt==2)
	{
		dfs(cnt?beg1:beg2);
		while(!ans.empty())
		{
			printf("%c",ans.back());
			ans.pop_back();
		}
	}
	else
	{
		puts("No Solution");
	}
	return 0;
}