#include <iostream>
#include <vector>
#include <map>
using namespace std;

int read()
{
	int sgn=0,ret=0;
	char ch=getchar();
	while(ch!=EOF&&!isdigit(ch))
	{
		sgn|=(ch=='-');
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ret=ret*10+(ch-48);
		ch=getchar();
	}
	return (sgn?-ret:ret);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],l[n+1],r[n+1];
	vector<int> v;
	int x=-1;
	for(int i=1;i<=n;i++)
	{
		// scanf("%d",&a[i]);
		a[i]=read();
		x=max(x,a[i]);
	}
	int ans=0;
	// for(int i=0;i<x;i++)
	// {
		// v.clear();
		map<pair<int,int>,bool> vis;
		for(int j=2;j<=n;j++)
		{
			while(!v.empty()&&a[v.back()]<=a[j])
			{
				v.pop_back();
			}
			if(v.empty())
				l[j]=-1;
			else
				l[j]=v.back();
			v.push_back(j);
		}
		v.clear();
		for(int j=n-1;j>0;j--)
		{
			while(!v.empty()&&a[v.back()]<=a[j])
			{
				v.pop_back();
			}
			if(v.empty())
				r[j]=-1;
			else
				r[j]=v.back();
			v.push_back(j);
		}
		for(int j=2;j<n;j++)
		{
			if(l[j]==-1||r[j]==-1)
			{
				continue;
			}
			if(!vis.count({l[j],r[j]}))
			{
				ans+=(r[j]-l[j]-1)*(min(a[l[j]],a[r[j]])-a[j]);
				vis[{l[j],r[j]}]=true;
			}
			// j=r[j];
		}
		/* for(int j=1;j<=n;j++)
		{
			a[j]=max(0,ans-1);
		} */
	// }
	printf("%d",ans);
	return 0;
}
/* 
7
0 2 1 0 1 2 0
 1   1 
 11 11 
 */