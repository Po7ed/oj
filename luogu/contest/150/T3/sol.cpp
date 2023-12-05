#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

struct node
{
	int id,d;
};

bool cmp(node a,node b)
{
	return (a.d==b.d?a.id<b.id:a.d<b.d);
}

int main()
{
	// ********** input ********** //
	int n;
	scanf("%d",&n);
	int u,v;
	vector<int> e[n+1];
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int d[n+1],now,pre;
	d[0]=0;
	e[0]={1};
	vector<pair<int,int>> dfs={make_pair(0,-1)};
	int s=0;
	while(!dfs.empty())
	{
		now=dfs.back().first;
		pre=dfs.back().second;
		dfs.pop_back();
		if(now)
		{
			d[now]=d[pre]+1;
		}
		s+=d[now];
		for(int to:e[now])
		{
			if(to!=pre)
			{
				dfs.push_back({to,now});
			}
		}
	}
	if(s&1)
	{
		// while(1)
		puts("-1");
		return 0;
	}
	node p[n+1];
	// itoa(p+1,p+(n+1),1);
	for(int i=1;i<=n;i++)
	{
		p[i].id=i;
		p[i].d=d[i];
	}
	sort(p+1,p+n+1,cmp);
	bool w[n+1];
	// fill()
	int a,b,sum=0;
	for(int i=(int)(!(n&1));i<=n;i+=2)
	{
		#define a p[i].d
		#define b p[i+1].d
		#define ia p[i].id
		#define ib p[i+1].id
		if(a==b)
		{
			w[ia]=true;
			w[ib]=false;
		}
		else
		{
			if(a<b)
			{
				swap(a,b);
			}
			if(sum)
			{
				w[ia]=true;
				w[ib]=false;
				sum--;
			}
			else
			{
				w[ia]=false;
				w[ib]=true;
				sum++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%c ","01"[(int)w[i]]);
	}
	return 0;
}