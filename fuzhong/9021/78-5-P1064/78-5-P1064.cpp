#include <iostream>
#include <vector>
using namespace std;

struct zj
{
	int id,a,b;
};


inline int max5(int a,int b,int c,int d,int e)
{
	return max(a,max(max(b,c),max(d,e)));
}

int main()
{
	int W,m;
	scanf("%d %d",&W,&m);
	int w[m+1],v[m+1],q[m+1],z[m+1];
	fill(z,z+m+1,-1);
	vector<zj> a;
	a.push_back({0,-1,-1});
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&w[i],&v[i],&q[i]);
		v[i]*=w[i];
		if(q[i]==0)
		{
			z[i]=a.size();
			a.push_back({i,-1,-1});
		}
		else
		{
			(a[z[q[i]]].a==-1?a[z[q[i]]].a:a[z[q[i]]].b)=i;
		}
	}
	int n=a.size()-1;
	int dp[n+1][W+1]/* ,id,aa,bb */;
	#define id a[i].id
	#define aa a[i].a
	#define bb a[i].b
	#define d dp[i-1][j]
	for(int i=1;i<=n;i++)
	{
		// id=a[i].id;
		// aa=a[i].a;
		// bb=a[i].b;
		for(int j=1;j<=W;j++)
		{
			dp[i][j]=max5
			(
				d,
				(j-w[id]>=0?dp[i-1][j-w[id]]+v[id]:d),
				(aa!=-1&&j-w[id]-w[aa]>=0?dp[i-1][j-w[id]-w[aa]]+v[id]+v[aa]:d),
				(bb!=-1&&j-w[id]-w[bb]>=0?dp[i-1][j-w[id]-w[bb]]+v[id]+v[bb]:d),
				(bb!=-1&&j-w[id]-w[aa]-w[bb]>=0?dp[i-1][j-w[id]-w[aa]-w[bb]]+v[id]+v[aa]+v[bb]:d)
			);
		}
	}
	printf("%d",dp[n][W]);
	return 0;
}