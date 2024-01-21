#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
constexpr int N=11451,P=114,mod=1'000'000'007;

int a[N];
int p,cnt;
char n[N];

int mem[N][P][2][2];
#define now mem[i][sum][small][zero]
int dfs(int i=cnt,int sum=0,bool small=false,bool zero=true)
{
	if(~now)return now;
	if(!i)return now=(!sum&&!zero);
	now=0;
	for(int j=0;j<10;j++)if(small||j<=a[i])
	{
		now=(now+dfs(i-1,(sum+j)%p,small||j^a[i],zero&&!j))%mod;
	}
	return (now+mod)%mod;
}

int main()
{
	scanf("%d\n\r%s",&p,n);
	cnt=strlen(n);
	for(int i=0;i<=cnt;i++)
	{
		a[i]=n[cnt-i]-'0';
	}
	fill(***mem,***mem+(N*P<<2),-1);
	printf("%d",(dfs()+mod)%mod);
	return 0;
}