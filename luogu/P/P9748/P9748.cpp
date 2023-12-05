#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=1,ans=0;
	while(n)
	{
		if(n%3==1&&!ans)
		{
			ans=cnt;
		}
		n-=(n%3?n/3+1:n/3);
		cnt++;
		// printf("%d\n",n);
	}
	printf("%d %d",cnt-1,ans);
	return 0;
}
