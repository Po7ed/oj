#include <cstdio>
int main()
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
	for(long long ans=1145;ans>=(a>b?a:b);ans--)
	{
		bool f=false;
		for(long long x=314;x>=0;x--)
		{
			for(long long y=314;y>=0;y--)
			{
				if(x*a+y*b==ans)
				{
					f=true;
					break;
				}
			}
		}
		if(!f)
		{
			printf("%lld",ans);
			return 0;
		}
	}
	return 0;
}