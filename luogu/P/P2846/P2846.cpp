#include <iostream>
#include <bitset>
using namespace std;

int n,m;
bitset<114514> a;

int main()
{
	scanf("%d %d",&n,&m);
	int opt,x,y,res;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&opt,&x,&y);
		if(opt)
		{
			res=0;
			for(int j=x;j<=y;j++)
			{
				if(a[j])
				{
					res++;
				}
			}
			printf("%d\n",res);
		}
		else
		{
			for(int j=x;j<=y;j++)
			{
				a.flip(j);
			}
		}
	}
	return 0;
}