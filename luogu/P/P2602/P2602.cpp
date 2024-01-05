#include <iostream>
using namespace std;

typedef long long ll;
constexpr int LN=13;
ll l,r;

ll mem[LN][LN][2][2];

int a[LN];

#define now mem[i][sum][zero][small]
ll dfs(int i,int d,int sum=0,bool zero=true,bool small=false)
{
	if(!i)return sum;
	if(~now)return now;
	now=0;
	for(int j=0;j<=9;j++)if(small||j<=a[i])
	{
		now+=dfs(i-1,d,sum+(j==d&&(j||!zero)),zero&&!j,small||j^a[i]);
	}
	return now;
}

ll calc(ll r,int d)
{
	fill(***mem,***mem+(LN*LN<<2),-1);
	int cnt=0;
	while(r)
	{
		a[++cnt]=r%10ll;
		r/=10ll;
	}
	return dfs(cnt,d);
}

int main()
{
	scanf("%lld %lld",&l,&r);
	for(int i=0;i<=9;i++)printf("%lld ",calc(r,i)-calc(l-1,i));
	return 0;
}