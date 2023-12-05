#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int a[5141],cnt=0;
bitset<51408ll> is;
// int b[81145],cnt2=0;
bitset<1145144*3ll> is2;

typedef long long ll;

int main()
{
	int l,r;
	scanf("%d %d",&l,&r);
	int n=sqrt(r)+1;
	a[cnt++]=2;
	for(int i=3;i<=n;i++)
	{
		if((i&1)&&!is[i])
		{
			a[cnt++]=i;
			for(int j=2;i*j<=n;j++)
			{
				is[i*j]=true;
			}
		}
	}
	for(int i=0;i<cnt;i++)
	{
		for(int j=max((double)2,ceil((double)l/a[i]));(ll)j*a[i]<=r;j++)
		{
			is2[(ll)j*a[i]-(ll)l+1]=true;
		}
	}
	int cnt=0;
	for(ll i=max(2,l);i<=r;i++)
	{
		if(!is2[i-l+1])
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}