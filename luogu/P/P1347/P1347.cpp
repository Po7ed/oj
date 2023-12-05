#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

int deg[27],td[27],dep[27];
vector<int> e[27];
char ord[27];
bitset<27> vis;
int have;
queue<int> q;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("\n%c<%c",&a,&b);
		e[a-'A'].push_back(b-'A');
		deg[b-'A']++;
		if(!vis[a-'A'])
		{
			have++;
		}
		if(!vis[b-'A'])
		{
			have++;
		}
		vis[a-'A']=vis[b-'A']=true;
		/* if(have<n)
		{
			continue;
		} */
		int cnt=0;// how many node in(ed) queue
		for(int j=0;j<=26;j++)
		{
			td[j]=deg[j];
			if(!td[j]&&vis[j])
			{
				q.push(j);
				dep[j]=1;
			}
		}
		int u,mx=-1;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			ord[cnt++]=u+'A';
			for(int v:e[u])
			{
				td[v]--;
				if(!td[v])
				{
					q.push(v);
					dep[v]=dep[u]+1;
					mx=max(mx,dep[v]);
				}
			}
		}
		if(have>cnt)
		{
			printf("Inconsistency found after %d relations.",i);
			return 0;
		}
		if(mx==n)
		{
			printf("Sorted sequence determined after %d relations: %s.",i,ord);
			return 0;
		}
	}
	puts("Sorted sequence cannot be determined.");
	return 0;
}