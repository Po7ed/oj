#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
	int k,n;
	unsigned long long ans=0;
	scanf("%d %d",&k,&n);
	queue<unsigned long long> q;
	while(n)
	{
		q.push(n&1);
		n>>=1;
	}
	int i=0;
	while(!q.empty())
	{
		ans+=(q.front()*pow(k,i));
		q.pop();
		i++;
	}
	printf("%lld",ans);
	return 0;
}