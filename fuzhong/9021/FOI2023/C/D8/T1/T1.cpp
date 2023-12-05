#include <iostream>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n)
		{
			break;
		}
		int b[n+2];
		fill(b,b+(n+2),0);
		int x,y;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
			b[x]++;
			b[y+1]--;
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			s+=b[i];
			printf("%d ",s);
		}
		puts("");
	}
	return 0;
}