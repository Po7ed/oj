#include <iostream>
using namespace std;
int main()
{
	int n,k;
	scanf("%d\n%d",&n,&k);
	int s[n+1],t;
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		s[i]=s[i-1]+t;
	}
	int m=-1;
	for(int i=1;i<=n-k;i++)
	{
		m=max(m,s[i+k]-s[i-1]);
	}
	printf("%d",m);
	return 0;
}