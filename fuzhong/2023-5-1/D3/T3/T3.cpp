#include <iostream>
using namespace std;
int main()
{
	// freopen("club.in","r",stdin);
	// freopen("club.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n+1],f[n+1],ans[n+1];
	fill(ans,ans+n+1,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	int t,vis[n+1]/* ,ans */;
	for(int i=1;i<=n;i++)
	{
		fill(vis,vis+n+1,false);
		t=i;
		// ans=0;
		while(f[t]!=t&&!vis[f[t]])
		{
			if(ans[t]&&t!=i)
			{
				ans[i]+=ans[t];
				goto output;
			}
			vis[t]=true;
			ans[i]+=a[t];
			t=f[t];
		}
		ans[i]+=a[t];
		output:
		printf("%d\n",ans[i]);
	}
	return 0;
}