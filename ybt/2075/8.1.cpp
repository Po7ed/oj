#include <iostream>
#include <stdio.h>
#include <algorithm>
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
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].index=i;
	}
	stable_sort(a+1,a+n+1,cmp);
	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i].val<<" "<<flush;
	// cout<<endl<<endl;
	for(int c=0;c<q;c++)
	{
		int op=0;
		scanf("%d",&op);
		if(op==1)
		{
			int x=0,v=0;
			scanf("%d %d",&x,&v);
			// if(a[x].val>v)
			// 	for(int i=x;i<=n;i--)
			for(int i=1;i<=n;i++)
				if(a[i].index==x)
				{
					//cout<<"find:"<<i<<","<<a[i].index<<endl;
					if(a[i].val>v)
					{
						// cout<<"big"<<endl;
						a[i].val=v;
						for(int j=i;j>=2;j--)
							if(a[j].val<a[j-1].val||(a[j].val==a[j-1].val&&a[j].index<a[j-1].index))
								{swap(a[j],a[j-1]);/*cout<<"swap:"<<a[j].val<<"and"<<a[j-1].val<<endl;*/}
							else break;
						break;
					}
					if(a[i].val<v)
					{
						// cout<<"small"<<endl;
						// cout<<a[i].val<<" "<<v<<endl;
						a[i].val=v;
						for(int j=i;j<=n-1;j++)
							if(a[j].val>a[j+1].val||(a[j].val==a[j+1].val&&a[j].index>a[j+1].index))
								{swap(a[j],a[j+1]);/*cout<<"swap:"<<a[j].val<<"and"<<a[j+1].val<<endl;*/}
							else /*cout<<"break!"<<j<<endl;*/break;
						break;
					}
				}
		}
		if(op==2)
		{
			int x=0;
			scanf("%d",&x);
			for(int i=1;i<=n;i++)
			{
				if(a[i].index==x)
				{
					printf("%d\n",i);
					//break;
				}
			}
		}
	}
	return 0;
}