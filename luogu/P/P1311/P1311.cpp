#include <iostream>
// #include <vector>
using namespace std;

typedef long long ll;

ll ans[51],oked[51],wating[51];

int main()
{
	int n,k,p;
	scanf("%d %d %d",&n,&k,&p);
	int a,b;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		if(b<=p)
		{
			for(int j=0;j<k;j++)
			{
				oked[j]+=wating[j];
				wating[j]=0;
			}
			ans[a]+=oked[a];
			oked[a]++;
		}
		else
		{
			wating[a]++;
			ans[a]+=oked[a];
		}
	}
	ll cnt=0;
	for(int i=0;i<k;i++)
	{
		cnt+=ans[i];
	}
	printf("%lld",cnt);
}
/* 
5 2 3
0 5
1 3
0 2
1 4
1 5
 */