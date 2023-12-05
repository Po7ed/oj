#include <iostream>
using namespace std;
int main()
{
	int max=8,maxind=0;
	for(int i=1;i<=7;i++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		if(n+m>max) 
		{
			max=n+m;
			maxind=i;
		}
	}
	printf("%d",maxind);
	return 0;
}