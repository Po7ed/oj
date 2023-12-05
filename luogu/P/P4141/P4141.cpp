#include <iostream>
using namespace std;
int w[2114],dpa[2114][2114],dpo[2114][2114];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",w+i);
	}
	dpo[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		dpa[i][0]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<w[i];j++)
		{
			dpa[i][j]=dpa[i-1][j];
			printf("a%d %d %d\n",i,j,dpa[i][j]);
		}
		for(int j=w[i];j<=m;j++)
		{
			dpa[i][j]=dpa[i-1][j]+dpa[i-1][j-w[i]];
			printf("a%d %d %d\n",i,j,dpa[i][j]);
			dpo[i][j]=dpa[i-1][j-w[i]];
			printf("o%d %d %d\n",i,j,dpo[i][j]);
		}
		// system("pause>nul");
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d",(dpa[i][j]-dpo[i][j])%10);
			// printf("%d %d ",dpa[i][j],dpo[i][j]);
		}
		puts("");
	}
	return 0;
}