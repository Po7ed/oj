#include <iostream>
#include <bitset>
using namespace std;
int a[1145140];
int vis[2114];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int l=1,r=1,cnt=1,al=-0x3f3f3f3f,ar=0x3f3f3f3f;
	vis[a[1]]=1;
	while(r<=n&&l<=r)
	{
		while(r<=n&&cnt!=m)
		{
			r++;
			cnt+=(vis[a[r]]?0:1);
			vis[a[r]]++;
			// printf("r++:%d\n",r);
				// printf("cnt:%d\n",cnt);
		}
		if(r<=n)
		{
			if(ar-al>r-l)
			{
				al=l;
				ar=r;
				// printf("a,cnt:%d\n",cnt);
			}
		}
		else
		{
			break;
		}
		// printf("%d %d\n",l,r);
		vis[a[l]]--;
		if(!vis[a[l]])
		{
			cnt--;
		}
		l++;
		// printf("l++:%d\n",l);
	}
	printf("%d %d",al,ar);
	return 0;
}