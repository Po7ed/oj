#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int n,m,x,y;
	for(int i=0;i<t;i++)
	{
		scanf("%d %d %d %d",&n,&m,&x,&y);
		if(x!=1&&y!=1&&x!=n&&y!=m)
		{
			puts("4");
		}
		else if(x==1&&y==1||x==1&&y==m||x==n&&y==1||x==n&&y==m)
		{
			puts("2");
		}
		else if(x==1||x==n||y==1||y==m)
		{
			puts("3");
		}
	}
	return 0;
}