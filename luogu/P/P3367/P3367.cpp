#include <iostream>
#include <string.h>
using namespace std;


int main()
{
	int n,m;//N 个元素和 M 个操作
	scanf("%d %d",&n,&m);
	int f[n+1];
	memset(f,0,sizeof(f));
	int z,x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&z,&x,&y);
		int r=x;
		while(f[r])
			r=f[r];
		int s=y;
		while(f[s])
			s=f[s];
		if(z==1)
		{
			if(r!=s)
				f[r]=s;
		}
		else
		{
			if(r!=s)
				puts("N");
			else
				puts("Y");
		}
	}
	return 0;
}
