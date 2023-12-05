#include <iostream>
#include <algorithm>
using namespace std;

int dis[51411];
int len,n,m;

int bsans(int l=0,int r=len)// [l,r]
{
	// printf("%d %d\n",l,r);
	if(r<l)
	{
		return -1;
	}
	int mid=((l+r)>>1),cur=0/* ,nxt */,cnt=0;
	// printf("mid:%d\n",mid);
	/* while(cur<n)
	{
		nxt=lower_bound(dis,dis+(n+1),dis[cur]+mid)-dis;
		// printf("nxt:%d\n",nxt);
		if(nxt>n)
		{
			// puts("too big");
			return bsans(l,mid-1);
		}
		else
		{
			cur=nxt;
			cnt++;
		}
	} */
	for(int i=1;i<=n;i++)
	{
		if(dis[i]-dis[cur]>=mid)
		{
			cur=i;
		}
		else
		{
			cnt++;
		}
	}
	// printf("cur:%d\n",cur);
	if(cnt>m||cur<n-1)
	{
		// puts("too big");
		return bsans(l,mid-1);
	}
	// ok:
	if(l==r)
	{
		return l;
	}
	// puts("too small");
	int ret;
	if(l==mid)
	{
		ret=bsans(r,r);
	}
	else
	{
		ret=bsans(mid,r);
	}
	if(ret==-1)
	{
		return mid;
	}
	else
	{
		return ret;
	}
	return -1;
}

int main()
{
	// freopen("P2855_2.in","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%d %d %d",&len,&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",dis+i);
	}
	sort(dis+1,dis+(n+1));
	dis[++n]=len;
	dis[0]=0;
	// for(int i=1;i<=n;i++)
	// printf("%d ",dis[i]);
	printf("%d",bsans());
	return 0;
}