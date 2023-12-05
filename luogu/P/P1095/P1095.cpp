#include <iostream>
using namespace std;
int main()
{
	int m,s,t;
	scanf("%d %d %d",&m,&s,&t);
	int sr=0,sj=0;
	for(int i=1;i<=t;i++)
	{
		if(m>=10)
		{
			sj+=60;
			m-=10;
		}
		else
		{
			m+=4;
		}
		sr+=17;
		sr=max(sr,sj);
		if(sr>s)
		{
			printf("Yes\n%d",i);
			return 0;
		}
	}
	printf("No\n%d",sr);
	return 0;
}