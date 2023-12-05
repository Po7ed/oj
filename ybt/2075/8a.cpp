#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

// struct value
// {
// 	int val;
// 	int index;
// };

bool cmp(int x[2],int y[2])
{
	return x[0]<y[0]||(x[0]==y[0]&&x[1]<y[1]);
}

int main()
{
	int n=0,q=0;
	cin>>n>>q;
	int a[n+1][2];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		a[i][1]=i;
	}
	stable_sort(*(a+1),*(a+n+1),cmp);
	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i][0]<<" "<<flush;
	// cout<<endl<<endl;
	for(int c=0;c<q;c++)
	{
		int op=0;
		scanf("%d",&op);
		if(op==1)
		{
			int x=0,v=0;
			scanf("%d %d",&x,&v);
			// if(a[x][0]>v)
			// 	for(int i=x;i<=n;i--)
			for(int i=1;i<=n;i++)
				if(a[i][1]==x)
				{
					//cout<<"find:"<<i<<","<<a[i][1]<<endl;
					if(a[i][0]>v)
					{
						// cout<<"big"<<endl;
						a[i][0]=v;
						for(int j=i;j>=2;j--)
							if(a[j][0]<a[j-1][0]||(a[j][0]==a[j-1][0]&&a[j][1]<a[j-1][1]))
								{swap(a[j],a[j-1]);/*cout<<"swap:"<<a[j][0]<<"and"<<a[j-1][0]<<endl;*/}
							else break;
						break;
					}
					if(a[i][0]<v)
					{
						// cout<<"small"<<endl;
						// cout<<a[i][0]<<" "<<v<<endl;
						a[i][0]=v;
						for(int j=i;j<=n-1;j++)
							if(a[j][0]>a[j+1][0]||(a[j][0]==a[j+1][0]&&a[j][1]>a[j+1][1]))
								{swap(a[j],a[j+1]);/*cout<<"swap:"<<a[j][0]<<"and"<<a[j+1][0]<<endl;*/}
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
				if(a[i][1]==x)
				{
					printf("%d\n",i);
					//break;
				}
			}
		}
	}
	return 0;
}