#include <iostream>
#include <vector>
using std::max;
using std::min;
constexpr int N=2145;
int n,m;
int a[N][N];
int ans1=-1,ans2=-1;
int b[N],pre[N],nxt[N];

void calc()
{
	std::vector<int> v;
	std::fill(b,b+N,0);
	for(int i=1;i<=n;i++)
	{
		v={0};
		b[0]=-2;b[m+1]=-1;
		for(int j=1;j<=m;j++)(!a[i][j])?(b[j]++):(b[j]=0);
		for(int j=1;j<=m+1;j++)
		{
			while(b[v.back()]>=b[j])nxt[v.back()]=j,v.pop_back();
			pre[j]=v.back();
			v.push_back(j);
		}
		for(int j=1,t;j<=m;j++)
		{
			t=std::min(nxt[j]-pre[j]-1,b[j]);
			ans1=std::max(ans1,t*t);
			ans2=std::max(ans2,(nxt[j]-pre[j]-1)*b[j]);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		scanf("%d",a[i]+j);
		if((i+j)&1)a[i][j]=!a[i][j];
	}
	calc();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=!a[i][j];
	calc();
	printf("%d\n%d",ans1,ans2);
	return 0;
}