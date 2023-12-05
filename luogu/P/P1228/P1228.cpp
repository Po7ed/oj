#include <iostream>
using namespace std;

void solve(int u,int d,int l,int r,int x,int y)
{
	if(u==d&&l==r)
	{
		return;
	}
	int m=(l+r)>>1,e=(u+d)>>1;
	if(x<=e)
	{
		if(y<=m)
		{
			printf("%d %d 1\n",e+1,m+1);
			solve(u,e,l,m,x,y);
			solve(u,e,m+1,r,e,m+1);
			solve(e+1,d,l,m,e+1,m);
			solve(e+1,d,m+1,r,e+1,m+1);
		}
		else
		{
			printf("%d %d 2\n",e+1,m);
			solve(u,e,l,m,e,m);
			solve(u,e,m+1,r,x,y);
			solve(e+1,d,l,m,e+1,m);
			solve(e+1,d,m+1,r,e+1,m+1);
		}
	}
	else
	{
		if(y<=m)
		{
			printf("%d %d 3\n",e,m+1);
			solve(u,e,l,m,e,m);
			solve(u,e,m+1,r,e,m+1);
			solve(e+1,d,l,m,x,y);
			solve(e+1,d,m+1,r,e+1,m+1);
			
		}
		else
		{
			printf("%d %d 4\n",e,m);
			solve(u,e,l,m,e,m);
			solve(u,e,m+1,r,e,m+1);
			solve(e+1,d,l,m,e+1,m);
			solve(e+1,d,m+1,r,x,y);
		}
		
	}
}

int main()
{
	int n,x,y;
	scanf("%d\n%d %d",&n,&x,&y);
	n=1<<n;
	solve(1,n,1,n,x,y);
	return 0;
}