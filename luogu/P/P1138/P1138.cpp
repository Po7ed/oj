#include <iostream>
using namespace std;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int t,a[30000];
	fill(a,a+30000,0);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		a[t]++;
	}
	int cnt=0;
	for(int i=1;i<30000;i++)
	{
		if(a[i])
			cnt++;
		if(cnt==k)
		{
			printf("%d",i);
			return 0;
		}
	}
	puts("NO RESULT");
	return 0;
}