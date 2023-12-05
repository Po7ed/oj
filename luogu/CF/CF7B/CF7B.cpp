#include <iostream>
using namespace std;
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int id[n+1];
	fill(id,id+(n+1),0);
	int x,cnt=1;
	string opt;
	for(int i=0;i<m;i++)
	{
		cin>>opt;
		if(opt=="alloc")
		{
			scanf("%d",&x);//,x
			if(x<=0||x>n)
			{
				puts("NULL");
				goto bre;
			}
			int len=0,beg=0;
			for(int j=1;j<=n;j++)
			{
				if(id[j]==0&&len==0)
				{
					len++;
					beg=j;
				}
				else if(id[j]==0)
				{
					len++;
				}
				else
				{
					len=0;
				}
				if(len>=x)
				{
					for(int k=beg;k<=j;k++)
					{
						id[k]=cnt;
					}
					printf("%d\n",cnt++);
					goto bre;
				}
			}
			puts("NULL");
			// bre:;
		}
		else if(opt=="erase")
		{
			scanf("%d",&x);
			if(x<1||x>=cnt)
			{
				puts("ILLEGAL_ERASE_ARGUMENT");
				goto bre;
			}
			for(int j=1;j<=n;j++)
			{
				if(id[j]==x)
				{
					for(int k=j;k<=n&&id[k]==x;k++)
					{
						id[k]=0;
					}
					goto bre;
				}
			}
			puts("ILLEGAL_ERASE_ARGUMENT");
			// bre2:;
		}
		else if(opt=="print")//for debug
		{
			for(int j=1;j<=n;j++)
			{
				printf("%d ",id[j]);
			}
			puts("");
		}
		else if(opt=="defragment")
		{
			for(int j=1,k=1;j<=n&&k<=n;)//yard
			{
				while(j<=n&&id[j])//j0
				{
					j++;
				}
				while(k<=n&&!id[k])//k1
				{
					k++;
				}
				if(j<=n&&k<=n&&j<k)
				{
					swap(id[j++],id[k++]);
				}
				if(j>k)
				{
					// j=k-1;
					k++;
					// k=j;
				}
			}
		}
		bre:;
		/* for(int j=1;j<=n;j++)
			{
				printf("%d ",id[j]);
			}
			puts(""); */
	}
	return 0;
}
