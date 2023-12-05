#include <iostream>
#include <bitset>
using namespace std;

int f[214514],d[214514],vis[214514];
int beg;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",f+i);
		d[f[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!d[i])
		{
			beg=i;
			break;
		}
	}
	if(!beg)
	{
		printf("%d",n);
	}
	else
	{
		int x=beg,cnt=1;
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
		}
		printf("%d",cnt-vis[x]);
	}
	return 0;
}