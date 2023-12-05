#include <iostream>
using namespace std;

const int A=514114;

int mul[A][20];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int l,r,mr=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&l,&r);
		mul[l][0]=max(mul[l][0],r);
		mr=max(mr,r);
	}
	for(int i=1;i<=mr;i++)
	{
		mul[i][0]=max(mul[i][0],mul[i-1][0]);
	}
	for(int j=1;j<20;j++)
	{
		for(int i=0;i<=mr;i++)
		{
			mul[i][j]=mul[mul[i][j-1]][j-1];
		}
	}
	int ans,cur;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&l,&r);
		ans=0;
		cur=l;
		for(int j=19;j>=0;j--)
		{
			if(mul[cur][j]&&mul[cur][j]<r)
			{
				ans+=(1<<j);
				cur=mul[cur][j];
			}
		}
		if(mul[cur][0]<r)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",ans+1);
		}
	}
	return 0;
}