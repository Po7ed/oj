#include <iostream>
using namespace std;

// char b;
const int X=5141;
int sum[X][X];
// char e;

int main()
{
	// printf("%llu\n",(&e-&b)/(1<<20));
	int n,m;
	scanf("%d %d",&n,&m);
	// m=(m-1)/2;
	int x,y,v,mx=-1,my=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&v);
		sum[++x][++y]=v;
		mx=max(mx,x);
		my=max(my,y);
	}
	for(int i=1;i<X;i++)
	{
		for(int j=1;j<X;j++)
		{
			sum[i][j]+=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]);
		}
	}
	int ans=0;
	for(int i=m;i<X;i++)
	{
		for(int j=m;j<=X;j++)
		{
			ans=max(ans,sum[i][j]-sum[i-m][j]-sum[i][j-m]+sum[i-m][j-m]);
		}
	}
	printf("%d",ans);
	return 0;
}