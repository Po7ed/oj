#include <iostream>
#include <vector>

// typedef long long ll;
constexpr int N=2145;
int a[N][N],n,m,b[N];
int pre[N],nxt[N];

int main()
{
	scanf("%d %d",&n,&m);
	char c;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		scanf(" %c",&c);
		a[i][j]=(c=='F');
	}
	std::vector<int> v;
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		v={0};
		b[0]=-2;
		b[m+1]=-1;
		for(int j=1;j<=m;j++)(a[i][j])?(b[j]++):(b[j]=0);
		for(int j=1;j<=m+1;j++)
		{
			while(b[v.back()]>=b[j])nxt[v.back()]=j,v.pop_back();
			pre[j]=v.back();
			v.push_back(j);
		}
		for(int j=1;j<=m;j++)
		{
			ans=std::max(ans,(nxt[j]-pre[j]-1)*b[j]);
		}
	}
	printf("%d",ans*3);
	return 0;
}