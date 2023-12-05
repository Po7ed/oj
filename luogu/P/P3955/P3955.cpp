#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int a[n+1];
	map<int,int> m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]>=1)
		{
			if(!m.count(a[i]%10)||a[m[a[i]%10]]>a[i])
			{
				m[a[i]%10]=i;
			}
			if(a[i]>=10)
			{
				if(!m.count(a[i]%100)||a[m[a[i]%100]]>a[i])
				{
					m[a[i]%100]=i;
				}
				if(a[i]>=100)
				{
					if(!m.count(a[i]%1000)||a[m[a[i]%1000]]>a[i])
					{
						m[a[i]%1000]=i;
					}
					if(a[i]>=1000)
					{
						if(!m.count(a[i]%10000)||a[m[a[i]%10000]]>a[i])
						{
							m[a[i]%10000]=i;
						}
						if(a[i]>=10000)
						{
							if(!m.count(a[i]%100000)||a[m[a[i]%100000]]>a[i])
							{
								m[a[i]%100000]=i;
							}
							if(a[i]>=100000)
							{
								if(!m.count(a[i]%1000000)||a[m[a[i]%1000000]]>a[i])
								{
									m[a[i]%1000000]=i;
								}
								if(a[i]>=1000000)
								{
									if(!m.count(a[i]%10000000)||a[m[a[i]%1000000]]>a[i])
									{
										m[a[i]%10000000]=i;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int fvv,x;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&fvv,&x);
		if(!m.count(x))
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",a[m[x]]);
		}
	}
	return 0;
}