#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int m,n,t;
	scanf("%d %d %d",&n,&t,&m);
	int w[t+1][n+1],v[t+1][n+1];
	memset(w,0,sizeof(w));
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++)
	{
		for(int tt=1;tt<=t;tt++)
		{
			scanf("%d",&w[tt][i]);
			if(tt!=1)
				v[tt-1][i]=w[tt][i]-w[tt-1][i];
			// else
				// v[]
		}
	}
	for(int tt=1;tt<t;tt++)
	{
		int f[m+1];
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(j-w[tt][i]>=0)
					f[j]=max(f[j],v[tt][i]+f[j-w[tt][i]]);
			}
		}
		m+=f[m];
	}
	printf("%d",m);
	return 0;
}