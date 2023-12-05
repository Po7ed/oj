#include <iostream>
#include <queue>
using namespace std;
int main()
{
	long long n,t;
	scanf("%lld %lld",&n,&t);
	queue<pair<long long,long long>> q;
	long long ans=0,d,b;
	for(long long i=0;i<n;i++)
	{
		scanf("%lld %lld",&d,&b);
		q.push({d,b});
	}
	long long m=0;
	for(long long i=1;i<=t;i++)
	{
		if(q.front().first==i)
		{
			m+=q.front().second;
			q.pop();
		}
		if(m>=1)
		{
			m--;
			ans++;
		}
	}
	printf("%lld",ans);
}