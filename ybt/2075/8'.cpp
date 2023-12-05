#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

struct value
{
	int val;
	int index;
};

bool cmp(value x,value y)
{
	return x.val<y.val||(x.val==y.val&&x.index<y.index);
}

int main()
{
	int n=0,q=0;
	cin>>n>>q;
	value a[n+1];
	map<int,int> m;

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].index=i;
		m[a[i].index]=a[i].val;
	}

	int lastop=0;
	int vmin=1000000001,vmax=-1;

	for(int c=0;c<q;c++)
	{
		int op=0;
		scanf("%d",&op);
		if(op==1)
		{
			int x=0,v=0;
			scanf("%d %d",&x,&v);
			if(v<vmin)vmin=v;
			if(v>vmax)vmax=v;
			if(m[x]<vmin)vmin=m[x];
			if(m[x]>vmax)vmax=m[x];

			for(int i=1;i<=n;i++)
				if(a[i].index==x)
				{
					a[i].val=v;
					m[a[i].index]=v;
					break;
				}
			//a[x].val=v;
		}
		if(op==2)
		{
			int x=0;
			scanf("%d",&x);
			// if(!c)
			// 	stable_sort(a+1,a+n+1,cmp);
			if(lastop!=2/*&&m[x]>=vmin&&m[x]<=vmax*/)
				stable_sort(a+1,a+n+1,cmp);
			// for(int i=1;i<=n;i++)
			// 	for(int j=i;j>=2;j--)
			// 		if(a[j].val<a[j-1].val||(a[j].val==a[j-1].val&&a[j].index<a[j-1].index))
			// 			swap(a[j],a[j-1]);
			for(int i=1;i<=n;i++)
			{
				if(a[i].index==x)
				{
					printf("%d\n",i);
					break;
				}
			}
			//cout<<endl;
		}
		lastop=op;
	}
	return 0;
}