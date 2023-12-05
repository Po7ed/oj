#include <iostream>
using namespace std;
int T,k,n,m;

int C[2114][2114],s[2114][2114];
inline void init()
{
	for(int i=0;i<=2000;i++)
	{
		C[i][0]=1;
	}
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(int)(!C[i][j]);
		}
		for(int j=i+1;j<=2000;j++)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
}

int main()
{
	scanf("%d %d",&T,&k);
	init();
	while(T--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",s[n][m]);
	}
	/* for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d,%d ",C[i][j],s[i][j]);
		}
		puts("");
	} */
	return 0;
}