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
	}
	stable_sort(a+1,a+n+1,cmp);

	for(int i=1;i<=n;i++)
	{
		m[a[i].index]=i;
	}

	for(int c=0;c<q;c++)
	{
		int op=0;
		scanf("%d",&op);
		if(op==1)
		{
			int x=0,v=0;
			scanf("%d %d",&x,&v);

			for(int i=1;i<=n;i++)
				if(a[i].index==x)
				{
				
					if(a[i].val>v)
					{
						a[i].val=v;
						for(int j=i;j>=2;j--)
							if(a[j].val<a[j-1].val||(a[j].val==a[j-1].val&&a[j].index<a[j-1].index))
								{swap(a[j],a[j-1]);
								m[a[j].index]++;
								m[a[j-1].index]--;
								}
							else break;
						break;
					}
					if(a[i].val<v)
					{
						a[i].val=v;
						for(int j=i;j<=n-1;j++)
							if(a[j].val>a[j+1].val||(a[j].val==a[j+1].val&&a[j].index>a[j+1].index))
								{swap(a[j],a[j+1]);
								m[a[j].index]--;
								m[a[j+1].index]++;
								}
							else break;
						break;
					}
				}
		}
		if(op==2)
		{
			int x=0;
			scanf("%d",&x);
			printf("%d\n",m[x]);
		}
	}
	return 0;
}