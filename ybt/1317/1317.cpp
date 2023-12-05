#include <iostream>
#include <string.h>
using namespace std;

int n,r;
int f[22];
void dfs(int dec,int step)
{
	f[step]=dec;
	if(step==r)
	{
		for(int i=1;i<=r;i++)
			printf("  %d",f[i]);
		puts("");
		f[step]=0;
		return;
	}
	else
	{
		for(int i=dec+1;i<=n;i++)
		{
			dfs(i,step+1);
		}
		f[step]=0;
	}
	return;
}

int main()
{
	scanf("%d %d",&n,&r);
	memset(f,0,sizeof(f));
	dfs(0,0);
	return 0;
}