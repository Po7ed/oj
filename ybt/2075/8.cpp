#include <iostream>
#include <stdio.h>
using namespace std;

struct value
{
	int val;
	int index;
};

int main()
{
	int n=0,q=0;
	cin>>n>>q;
	value a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].index=i;
	}
	for(int i=0;i<q;i++)
	{
		int op=0;
		scanf("%d",&op);
		if(op==1)
		{
			int x=0,v=0;
			scanf("%d %d",&x,&v);
			a[x].val=v;
		}
		else
		{
			int x=0;
			scanf("%d",&x);
			value ta[n+1];
			for(int i=1;i<=n;i++)
			{
				ta[i].val=a[i].val;
				ta[i].index=a[i].index;
			}
			for(int i=1;i<=n;i++)
				for(int j=i;j>=2;j--)
					if(ta[j].val<ta[j-1].val)
						swap(ta[j],ta[j-1]);
			//cout<<endl;
			for(int i=1;i<=n;i++)
			{
				//cout<<ta[i].index<<" "<<ta[i].val<<endl;
				//printf("%d",i);
				if(ta[i].index==x)
					printf("%d\n",i);
			}
			//cout<<endl;
		}
	}
	return 0;
}