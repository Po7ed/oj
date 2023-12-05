#include <iostream>
using namespace std;

int old[114514];
int m,n,k;

inline bool check(int x)
{
	int tk=k,tmp;
	for(int i=1;i<n;i++)
	{
		tmp=(old[i+1]-old[i]-1)/x;
		tk-=tmp;
		if(tk<0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d %d %d",&m,&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",old+i);
	}
	int l=1,r=m,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%d",ans);
	return 0;
}