#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int n,m;
	// vector<int> v;
	set<int> s;
	int o,x,a;
	for(int i=0;i<t;i++)
	{
		s.clear();
		a=-1;
		scanf("%d %d",&n,&m);
		for(int j=1;j<=m;j++)
		{
			scanf("%d %d",&o,&x);
			if(o==1)
			{
				if(a==x)
				{
					printf("%d\n",j);
					for(int k=j+1;k<=m;k++)
					{
						scanf("%d %d",&o,&x);
					}
					goto bre;
				}
				s.insert(x);
			}
			else
			{
				if(a!=x&&a!=-1)
				{
					printf("%d\n",j);
					for(int k=j+1;k<=m;k++)
					{
						scanf("%d %d",&o,&x);
					}
					goto bre;
				}
				a=x;
				if(s.find(a)!=s.end())
				{
					printf("%d\n",j);
					for(int k=j+1;k<=m;k++)
					{
						scanf("%d %d",&o,&x);
					}
					goto bre;
				}
			}
			if(s.size()==n)
			{
				printf("%d\n",j);
				for(int k=j+1;k<=m;k++)
				{
					scanf("%d %d",&o,&x);
				}
				goto bre;
			}
		}
		puts("-1");
		bre:;
	}
	return 0;
}
/* 3

3 3
1 2
1 2
1 2

3 3
2 2
1 2
1 2

4 4
1 4
2 4
1 4
1 4

1
4 4
1 4
2 4
1 4
1 4 */