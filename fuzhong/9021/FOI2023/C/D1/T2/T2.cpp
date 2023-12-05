#include <iostream>
using namespace std;
// typedef long long ll;

int main()
{
	freopen("squares.in","r",stdin);
	freopen("squares.out","w",stdout);
	int n;
	scanf("%d",&n);
	int log[n+1];
	log[1]=0;
	for(int i=2;i<=n;i++)
	{
		log[i]=log[i>>1]+1;
	}
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int st[n+1][log[n]+1];
	fill(*st,*st+(n+1)*(log[n]+1),0x3f3f3f3f);
	for(int i=1;i<=n;i++)
	{
		st[i][0]=a[i];
	}
	for(int j=1;j<=log[n];j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	#define len (r-l+1)
	#define query min(st[l][log[len]],st[r-(1<<(log[len]))][log[len]])
	int s,ans=-1;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			s=query*len;
			ans=max(ans,s);
		}
	}
	printf("%d",ans);
	return 0;
}