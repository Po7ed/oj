#include <iostream>
using namespace std;
int n,k;
int cnt,m=1,sum;
int dis[6];
int e;
void dfs(int step)
{
	if(step==k)
	{
		if(sum==n)
			cnt++;
		// printf("%d %d %d %d %d %d\n",dis[0],dis[1],dis[2],dis[3],dis[4],dis[5]);
		return;
	}
	int cpym=m;
	for(int i=m;i<=n-sum;i++)
	{
		if(sum+i<=n)
		{
			sum+=i;
			m=i;
			dis[e++]=i;
			dfs(step+1);
			m=cpym;
			e--;
			sum-=i;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&k);
	dfs(0);
	printf("%d",cnt);
	return 0;
}