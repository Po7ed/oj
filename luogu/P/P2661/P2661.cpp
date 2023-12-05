#include <iostream>
#include <bitset>
using namespace std;

int f[214514]/* ,d[214514] */,vis[214514];
// int beg;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",f+i);
		// d[f[i]]++;
	}
	int ans=0x3f3f3f3f;
	bool cir=true;
	int x,cnt=1,tc;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			x=i;
			tc=cnt;
			cir=false;
			// beg=i;
			/* while(1)
			{
				if(!vis[x])
				{
					vis[x]=cnt++;
					x=f[x];
				}
				else
				{
					break;
				}
			} */
			while(!vis[x])
			{
				vis[x]=cnt++;
				x=f[x];
				if(vis[x]&&vis[x]<tc)
				{
					goto con;
				}
			}
			ans=min(ans,cnt-vis[x]);
			con:;
		}
	}
	if(cir)
	{
		printf("%d",n);
	}
	else
	{
		printf("%d",ans);
	}
	return 0;
}