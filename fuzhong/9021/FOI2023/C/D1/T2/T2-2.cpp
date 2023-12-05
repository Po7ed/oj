#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

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
	a[0]=0x3f3f3f3f;
	int st[n+1][log[n]+1];
	fill(*st,*st+(n+1)*(log[n]+1),0);
	for(int i=1;i<=n;i++)
	{
		st[i][0]=i;
	}
	for(int j=1;j<=log[n];j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			if(a[st[i][j-1]]>a[st[i+(1<<(j-1))][j-1]])
			{
				st[i][j]=st[i+(1<<(j-1))][j-1];
			}
			else
			{
				st[i][j]=st[i][j-1];
			}
			// st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	#define len (r-l+1)
	// #define query min(st[l][log[len]],st[r-(1<<(log[len]))][log[len]])
	int l=1,r=n,query;
	ll s,ans=-1;
	queue<pair<int,int>> q;
	q.push({1,n});
	while(!q.empty())
	{
		if(q.size()>1000)
		{
			break;
		}
		l=q.front().first;
		r=q.front().second;
		q.pop();
		if(l>r)
		{
			continue;
		}
		if(a[st[l][log[len]]]>a[st[r-(1<<(log[len]))+1][log[len]]])
		{
			query=st[r-(1<<(log[len]))+1][log[len]];
		}
		else
		{
			query=st[l][log[len]];
		}
		s=(ll)a[query]*(ll)(r-l+1);
		ans=max(ans,s);
		q.push({l,query-1});
		q.push({query+1,r});
	}
	printf("%lld",ans);
	return 0;
}