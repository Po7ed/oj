#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct edge
{
	int ind;
	int v;
};

struct cmp
{
	bool operator()(edge x,edge y)
	{
		return x.v<y.v;
	}
};

int main()
{
	int m,n,k,l,d;//m->l;n->c
	scanf("%d %d %d %d %d",&m,&n,&k,&l,&d);
	int xi,xj,yi,yj;
	// stp a[d];
	int lv[m+1],cv[n+1];
	memset(lv,0,sizeof(lv));
	memset(cv,0,sizeof(cv));
	for(int i=0;i<d;i++)
	{
		scanf("%d %d %d %d",&xi,&xj,&yi,&yj);
		if(xi==yi&&xj==yj-1)
		{
			cv[xj]++;
		}
		if(xi==yi&&xj==yj+1)
		{
			cv[yj]++;
		}
		if(xj==yj&&xi==yi-1)
		{
			lv[xi]++;
		}
		if(xj==yj&&xi==yi+1)
		{
			lv[yi]++;
		}
	}
	priority_queue<edge,vector<edge>,cmp> pql,pqc;
	for(int i=1;i<m;i++)
	{
		pql.push({i,lv[i]});
	}
	for(int i=1;i<n;i++)
	{
		pqc.push({i,cv[i]});
	}
	priority_queue<int,vector<int>,greater<>> pqi={};
	for(int i=0;i<k;i++)
	{
		edge t=pql.top();
		pql.pop();
		pqi.push(t.ind);
	}
	for(int i=0;i<k;i++)
	{
		int t=pqi.top();
		pqi.pop();
		if(i==k-1)
			printf("%d\n",t);
		else
			printf("%d ",t);
	}
	pqi={};
	for(int i=0;i<l;i++)
	{
		edge t=pqc.top();
		pqc.pop();
		pqi.push(t.ind);
	}
	for(int i=0;i<l;i++)
	{
		int t=pqi.top();
		pqi.pop();
		if(i==l-1)
			printf("%d",t);
		else
			printf("%d ",t);
	}
	return 0;
}