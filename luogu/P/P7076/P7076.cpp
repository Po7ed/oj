#include <iostream>
#include <bitset>
using namespace std;

typedef unsigned long long ull;

const int N=1145141,K=70;
ull a[N];
int n,m,c,k;

bitset<K> exi;

int main()
{
	scanf("%d %d %d %d",&n,&m,&c,&k);
	ull sum=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%llu",a+i);
	}
	int p,q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&p,&q);
		exi[p]=true;
	}
	int cnt;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		while(a[i])
		{
			if(a[i]&1)
			{
				exi[cnt]=false;
			}
			cnt++;
			a[i]>>=1;
		}
	}
	ull tmp=1ull;
	bool f=false;
	for(int i=0;i<k;i++)
	{
		if(!exi[i])
		{
			tmp<<=1ull;
			f=true;
		}
	}
	if(f&&tmp==0&&n==0)
	{
		puts("18446744073709551616");
		return 0;
	}
	printf("%llu",tmp-1ull*n);
	return 0;
}