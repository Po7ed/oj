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

//int a[8001][2];

bool cmp(value x,value y)
{
	return x.val<y.val||(x.val==y.val&&x.index<y.index);
//	return x[0]<y[0]||(x[0]==y[0]&&x[1]<y[1]);
}

int main()
{
	int n=0,q=0;
	cin>>n>>q;
	value a[n+1];
//	int a[n+1][2]={{0}};
//	map<int,int> m;
	int d[n+1];
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].index=i;
//		scanf("%d",&a[i][0]);
//		a[i][1]=i;
	}


	stable_sort(a+1,a+n+1,cmp);	
//	stable_sort(a.begin()+1,a.end()+1);

	for(int i=1;i<=n;i++)
	{
		d[a[i].index]=i;
//		m[a[i].index]=i;
//		m[a[i][1]]=i;
	}

	for(int c=0;c<q;c++)
	{
		int op=0;
		scanf("%d",&op);
		if(op==1)
		{
			int x=0,v=0;
			scanf("%d %d",&x,&v);

		//	for(int i=1;i<=n;i++)
		//		if(a[i].index==x)
		//		{
				
		//			if(a[i].val>v)
			if(a[d[x]].val>v)
		//	if(a[m[x]][0]>v)
					{
						a[d[x]].val=v;
		//				a[m[x]][0]=v;
		//				a[i].val=v;
		//				for(int j=i;j>=2;j--)
						for(int j=d[x];j>=2;j--)
							if(a[j].val<a[j-1].val||(a[j].val==a[j-1].val&&a[j].index<a[j-1].index))
		//					if(a[j][0]<a[j-1][0]||(a[j][0]==a[j-1][0]&&a[j][1]<a[j-1][1]))
								{swap(a[j],a[j-1]);
								d[a[j].index]++;//变更赋值,调整对应关系
								d[a[j-1].index]--;
		//						m[a[j][1]]++;
		//						m[a[j-1][1]]--;
								}
							else break;
		//				break;
					}
		//			if(a[i].val<v)
			if(a[d[x]].val<v)
		//	if(a[m[x]][0]<v)
					{
						a[d[x]].val=v;
		//				a[m[x]][0]=v;
		//				a[i].val=v;
		//				for(int j=i;j<=n-1;j++)
						for(int j=d[x];j<=n-1;j++)
							if(a[j].val>a[j+1].val||(a[j].val==a[j+1].val&&a[j].index>a[j+1].index))
		//					if(a[j][0]>a[j+1][0]||(a[j][0]==a[j+1][0]&&a[j][1]>a[j+1][1]))
								{swap(a[j],a[j+1]);
								d[a[j].index]--;//变更赋值,调整对应关系
								d[a[j+1].index]++;
//								m[a[j][1]]--;
//								m[a[j+1][1]]++;
								}
							else break;
		//				break;
					}

//			for(int i=1;i<=n;i++)//全部顺序赋值，对应74 75 94 95 行，变更赋值
//			{
//				d[a[i].index]=i;
//			}	
		}
		if(op==2)
		{
			int x=0;
			scanf("%d",&x);
			printf("%d\n",d[x]);
		}
	}
	return 0;
}