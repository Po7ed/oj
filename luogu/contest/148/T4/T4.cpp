#include <iostream>
#include <bit>
using namespace std;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n+1];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	int ans=0x3f3f3f3f,cnt/* ,fa */;
	#define is ((i>>j)&1)
	for(int i=0;i<(1<<n);i++)
	{
		if(__popcount(i)>=k)
		{
			cnt=0;
			for(int j=0;j<n;j++)//...543210
			{
				if(is)
				{
					cnt+=(a[j]*a[j]);
				}
				else
				{
					int l,r,mb,ll=0,rr=0,d;
					for(l=j;1;l=(l+n-1)%n)
					{
						if((i>>l)&1)
						{
							break;
						}
						ll++;
					}
					for(r=j;1;r=(r+n+1)%n)
					{
						if((i>>r)&1)
						{
							break;
						}
						rr++;
					}
					/* if(l==-1)
					{
						mb=r;
					}
					else if(r==n)
					{
						mb=l;
					} */
					mb=(a[l]>a[r]?l:r);
					if(a[l]>a[r])
					{
						mb=l;
						d=ll;
					}
					else
					{
						mb=r;
						d=rr;
					}

					cnt+=(d*a[mb]);
				}
			}
			// ans=min(ans,cnt);
			if(ans>cnt)
			{
				ans=cnt;
				// fa=i;
			}
		}
	}
	printf("%d",ans);
	return 0;
}